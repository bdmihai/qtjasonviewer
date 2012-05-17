/****************************************************************************
**
** Copyright (C) 2010-2012 B.D. Mihai.
**
** This file is part of JSON Viewer.
**
** JSON Viewer is free software: you can redistribute it and/or modify it 
** under the terms of the GNU Lesser Public License as published by the Free 
** Software Foundation, either version 3 of the License, or (at your option) 
** any later version.
**
** JSON Viewer is distributed in the hope that it will be useful, but 
** WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY 
** or FITNESS FOR A PARTICULAR PURPOSE. See the GNU Lesser Public License for 
** more details.
**
** You should have received a copy of the GNU Lesser Public License along 
** with JSON Viewer.  If not, see http://www.gnu.org/licenses/.
**
****************************************************************************/

#include "StdAfx.h"
#include "MainWindow.h"
#include "Settings.h"
#include "Defines.h"

MainWindow::MainWindow(QWidget *parent) : QMainWindow(parent)
{
  filePath = "";
  isUntitled = true;
  isFirstTime = true;

  jsonModel = new JsonModel(this);

  createLayout();
  createActions();
  createMenus();
  createToolBars();
  createDockWindows();
  createStatusBar();
  readSettings();

  highlighter = new SyntaxHighlighter(textEdit->document());
}

MainWindow::~MainWindow()
{

}

void MainWindow::showEvent(QShowEvent *event)
{
  if (isFirstTime)
  {
    readSettings();
    newFile();
    isFirstTime = false;   
  }
  QMainWindow::showEvent(event);
}

void MainWindow::closeEvent(QCloseEvent *event)
{
  if (maybeSave()) 
  {
    writeSettings();
    event->accept();
  } 
  else 
  {
    event->ignore();
  }
}

void MainWindow::createLayout()
{
  textEdit = new QTextEdit(this);
  textEdit->setFontFamily("Courier New");
  textEdit->setFontPointSize(10);
  textEdit->setLineWrapMode(QTextEdit::NoWrap);

  connect(textEdit->document(), SIGNAL(contentsChanged()),
          this, SLOT(modified()));

  jsonTreeView = new QTreeView(this);
  jsonTreeView->setModel(jsonModel);

  setCentralWidget(textEdit);
  setWindowIcon(QIcon(":/JsonViewer.png"));
}

void MainWindow::createActions()
{
  newAct = new QAction(QIcon(":/New.png"), tr("&New"), this);
  newAct->setShortcuts(QKeySequence::New);
  newAct->setStatusTip(tr("Create a new file"));
  connect(newAct, SIGNAL(triggered()), this, SLOT(newFile()));

  openAct = new QAction(QIcon(":/Open.png"), tr("&Open..."), this);
  openAct->setShortcuts(QKeySequence::Open);
  openAct->setStatusTip(tr("Open an existing file"));
  connect(openAct, SIGNAL(triggered()), this, SLOT(open()));

  saveAct = new QAction(QIcon(":/Save.png"), tr("&Save"), this);
  saveAct->setShortcuts(QKeySequence::Save);
  saveAct->setStatusTip(tr("Save the file to disk"));
  connect(saveAct, SIGNAL(triggered()), this, SLOT(save()));

  saveAsAct = new QAction(QIcon(":/SaveAs.png"), tr("Save &As..."), this);
  saveAsAct->setShortcuts(QKeySequence::SaveAs);
  saveAsAct->setStatusTip(tr("Save the file under a new name"));
  connect(saveAsAct, SIGNAL(triggered()), this, SLOT(saveAs()));

  exitAct = new QAction(tr("E&xit"), this);
  exitAct->setShortcuts(QKeySequence::Quit);
  exitAct->setStatusTip(tr("Exit the application"));
  connect(exitAct, SIGNAL(triggered()), qApp, SLOT(closeAllWindows()));

  cutAct = new QAction(QIcon(":/Cut.png"), tr("Cu&t"), this);
  cutAct->setShortcuts(QKeySequence::Cut);
  cutAct->setStatusTip(tr("Cut the current selection's contents to the clipboard"));
  connect(cutAct, SIGNAL(triggered()), textEdit, SLOT(cut()));

  copyAct = new QAction(QIcon(":/Copy.png"), tr("&Copy"), this);
  copyAct->setShortcuts(QKeySequence::Copy);
  copyAct->setStatusTip(tr("Copy the current selection's contents to the clipboard"));
  connect(copyAct, SIGNAL(triggered()), textEdit, SLOT(copy()));

  pasteAct = new QAction(QIcon(":/Paste.png"), tr("&Paste"), this);
  pasteAct->setShortcuts(QKeySequence::Paste);
  pasteAct->setStatusTip(tr("Paste the clipboard's contents into the current selection"));
  connect(pasteAct, SIGNAL(triggered()), textEdit, SLOT(paste()));

  helpAct = new QAction(tr("&Help..."), this);
  helpAct->setStatusTip(tr("Help"));
  connect(helpAct, SIGNAL(triggered()), this, SLOT(help()));

  aboutAct = new QAction(tr("&About..."), this);
  aboutAct->setStatusTip(tr("About"));
  connect(aboutAct, SIGNAL(triggered()), this, SLOT(about()));

  aboutQtAct = new QAction(tr("About &Qt..."), this);
  aboutQtAct->setStatusTip(tr("Show the Qt library's About box"));
  connect(aboutQtAct, SIGNAL(triggered()), qApp, SLOT(aboutQt()));
}

void MainWindow::createMenus()
{
  fileMenu = menuBar()->addMenu(tr("&File"));
  fileMenu->addAction(newAct);
  fileMenu->addAction(openAct);
  fileMenu->addAction(saveAct);
  fileMenu->addAction(saveAsAct);
  fileMenu->addSeparator();
  fileMenu->addAction(exitAct);

  editMenu = menuBar()->addMenu(tr("&Edit"));
  editMenu->addAction(cutAct);
  editMenu->addAction(copyAct);
  editMenu->addAction(pasteAct);

  helpMenu = menuBar()->addMenu(tr("&Help"));
  helpMenu->addAction(helpAct);
  helpMenu->addSeparator();
  helpMenu->addAction(aboutAct);
  helpMenu->addAction(aboutQtAct);
}

void MainWindow::createToolBars()
{
  editToolBar = addToolBar(tr("Edit"));
  editToolBar->setObjectName("QToolBar.Edit");
  editToolBar->addAction(cutAct);
  editToolBar->addAction(copyAct);
  editToolBar->addAction(pasteAct);
}

void MainWindow::createStatusBar()
{
  statusBar()->showMessage(tr("Ready"));
}

void MainWindow::createDockWindows()
{
  QDockWidget *dock;

  dock = new QDockWidget(tr("Json View"), this);
  dock->setObjectName("QDockWidget.JsonView");
  dock->setAllowedAreas(Qt::LeftDockWidgetArea | Qt::RightDockWidgetArea);
  dock->setWidget(jsonTreeView);
  addDockWidget(Qt::LeftDockWidgetArea, dock);
}

void MainWindow::readSettings()
{
  restoreGeometry(settings->getWindowGeometry());
  restoreState(settings->getWindowState());
}

void MainWindow::writeSettings()
{
  settings->setWindowGeometry(saveGeometry());
  settings->setWindowState(saveState());
}

bool MainWindow::maybeSave()
{
  if (textEdit->document()->isModified()) 
  {
    QMessageBox::StandardButton ret;

    ret = QMessageBox::warning(this, APP_NAME,
      tr("The document has been modified.\nDo you want to save your changes?"),
      QMessageBox::Save | QMessageBox::Discard | QMessageBox::Cancel);

    if (ret == QMessageBox::Save)
      return save();
    else if (ret == QMessageBox::Cancel)
      return false;
  }
  return true;
}

void MainWindow::loadFile(const QString &path)
{
  QFile file(path);

  if (!file.open(QFile::ReadOnly | QFile::Text)) 
  {
    QMessageBox::warning(this, APP_NAME,
      tr("Cannot read file %1:\n%2.").arg(path).arg(file.errorString()));
    return;
  }

  QTextStream in(&file);
  QApplication::setOverrideCursor(Qt::WaitCursor);
  textEdit->setPlainText(in.readAll());
  QApplication::restoreOverrideCursor();

  setCurrentFile(path);
  statusBar()->showMessage(tr("File loaded"), 2000);
}

bool MainWindow::saveFile(const QString &path)
{
  QFile file(path);

  if (!file.open(QFile::WriteOnly | QFile::Text)) 
  {
    QMessageBox::warning(this, APP_NAME,
      tr("Cannot write file %1:\n%2.").arg(filePath).arg(file.errorString()));
    return false;
  }

  QTextStream out(&file);
  QApplication::setOverrideCursor(Qt::WaitCursor);
  out << textEdit->toPlainText();
  QApplication::restoreOverrideCursor();

  setCurrentFile(path);
  statusBar()->showMessage(tr("File saved"), 2000);
  return true;
}

void MainWindow::setCurrentFile(const QString &path)
{
  static int sequenceNumber = 1;

  isUntitled = path.isEmpty();
  if (isUntitled) 
  {
    filePath = tr("Untitled%1.json").arg(sequenceNumber++);
  } 
  else 
  {
    filePath = QFileInfo(path).canonicalFilePath();
  }

  textEdit->document()->setModified(false);
  setWindowModified(false);
  setWindowFilePath(filePath);
}

void MainWindow::newFile()
{
  if (maybeSave()) 
  {
    textEdit->setPlainText("");
    setCurrentFile("");
    statusBar()->showMessage(tr("New file"), 2000);
  }
}

void MainWindow::open()
{
  if (maybeSave()) 
  {
    QString fileName = QFileDialog::getOpenFileName(this);
    if (!fileName.isEmpty()) 
    {
      loadFile(fileName);
    }
  }
}

bool MainWindow::save()
{
  if (isUntitled) 
    return saveAs();
  else 
    return saveFile(filePath);
}

bool MainWindow::saveAs()
{
  QString fileName = QFileDialog::getSaveFileName(this, tr("Save As"), filePath);

  if (!fileName.isEmpty())
    return saveFile(fileName);
  else
    return false;
}

void MainWindow::modified()
{
  setWindowModified(true);
  jsonModel->parse(textEdit->toPlainText());
  jsonTreeView->expandAll();
}

void MainWindow::about()
{
  QMessageBox::about(this, tr("About ") + APP_NAME,
    tr("<b>") + APP_NAME + tr("</b> version ")  + APP_VERSION +
    tr("<p>Developed using <a href=\"http://qt.nokia.com\">Qt ")
    + qVersion() + tr(" framework</a>.</p>"
    "<p>Email : <a href=\"mailto:bdmihai@gmail.com\">bdmihai@gmail.com</a></p>"));
}

void MainWindow::help()
{
  QMessageBox::information(this, APP_NAME + tr("Help"), tr("In work"));
}
