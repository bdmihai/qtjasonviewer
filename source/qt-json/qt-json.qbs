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

import qbs

Product {
  name: "qt-json"
  type: "staticlibrary"

  // dependencies
  Depends { name: "cpp" }
  Depends { name: "Qt.core" }

  // cpp module configuration
  cpp.windowsApiCharacterSet: "mbcs"
  cpp.cxxLanguageVersion: "c++14"

  Group {
    name: "pch files"
    files: ["stdafx.h"]
    fileTags: "cpp_pch_src"
  }

  files: [
    "json_scanner.h",
    "parser.h",
    "parser_p.h",
    "parserrunnable.h",
    "qjson_debug.h",
    "qobjecthelper.h",
    "serializer.h",
    "serializerrunnable.h",
    "json_parser.hh",
    "location.hh",
    "position.hh",
    "stack.hh",
    "json_parser.cc",
    "json_scanner.cpp",
    "parser.cpp",
    "parserrunnable.cpp",
    "qobjecthelper.cpp",
    "serializer.cpp",
    "serializerrunnable.cpp"
  ]

  Export {
    Depends { name: "cpp" }
    Depends { name: "Qt.core" }
    cpp.includePaths: [ product.sourceDirectory ]
  }
}
