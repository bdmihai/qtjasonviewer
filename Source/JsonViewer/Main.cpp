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
#include "Defines.h"
#include "Settings.h"
#include "Windows/MainWindow.h"

/*!
This is the main entry point for the application. It shows the main window and 
starts the application main message loop.
*/
int main(int argc, char *argv[])
{
  QApplication app(argc, argv);

  // set the application info
  app.setApplicationName(APP_NAME);
  app.setOrganizationName(APP_COMPANY);
  app.setOrganizationDomain(APP_DOMAIN);
  app.setApplicationVersion(APP_VERSION);

  // application settings
  settings = new Settings();

  // show the main window
  MainWindow mainWindow;
  mainWindow.show();

  // run the application
  return app.exec();;
}
