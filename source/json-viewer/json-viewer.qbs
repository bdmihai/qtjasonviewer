/****************************************************************************
**
** Copyright (C) 2010-2018 B.D. Mihai.
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

Product {
  name: "json-viewer"
  type: "application"
  consoleApplication: false

  // dependencies
  Depends { name: "cpp" }
  Depends { name: "Qt.core" }
  Depends { name: "Qt.widgets" }
  Depends { name: "qt-json" }

  // cpp module configuration
  cpp.windowsApiCharacterSet: "mbcs"
  cpp.includePaths: [ "." ]
  cpp.cxxLanguageVersion: "c++14"
  cpp.useCxxPrecompiledHeader: true

  // precompiled header
  Group {
    name: "pch files"
    files: [ "stdafx.h" ]
    fileTags: "cpp_pch_src"
  }

  // resource files
  Group {
    name: "resources"
    files : [ "resources/*.png", "resources/*.ico", "resources/*.rc", "resources/*.qrc" ]
  }

  // install group for the produced executable
  Group {
    qbs.install: true
    qbs.installDir: ""
    fileTagsFilter: product.type
  }

  files: [
    "defines.h",
    "main.cpp",
    "settings.cpp",
    "settings.h",
    "data/jsonitem.cpp",
    "data/jsonitem.h",
    "data/jsonmodel.cpp",
    "data/jsonmodel.h",
    "data/syntaxhighlighter.cpp",
    "data/syntaxhighlighter.h",
    "windows/mainwindow.cpp",
    "windows/mainwindow.h"
  ]
}
