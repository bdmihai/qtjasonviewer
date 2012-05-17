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
#include "Settings.h"

#define APP_SETTINGS_FILE QDesktopServices::storageLocation(QDesktopServices::DataLocation) + "/Settings.ini"

//! The application settings.
Settings *settings;

Settings::Settings() : QSettings(APP_SETTINGS_FILE, QSettings::IniFormat, 0)
{
  if (!QFile::exists(APP_SETTINGS_FILE))
    setDefault();
}

Settings::~Settings()
{

}

void Settings::setDefault()
{

}

void Settings::setWindowGeometry(const QByteArray &newValue)
{
  setValue("MainWindow/Geometry", newValue);
}

QByteArray Settings::getWindowGeometry()
{
  return value("MainWindow/Geometry").toByteArray();
}

void Settings::setWindowState(const QByteArray &newValue)
{
  setValue("MainWindow/State", newValue);
}

QByteArray Settings::getWindowState()
{
  return value("MainWindow/State").toByteArray();
}
