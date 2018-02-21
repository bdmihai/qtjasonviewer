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
  name: "setup"
  targetName: "JsonViewerSetup"
  type: "application"

  Depends { name: "innosetup" }
  Depends { name: "json-viewer" }
  
  files: [
    "jsonviewer.iss"
  ]

  // install group for the produced executable
  Group {
    qbs.install: true
    qbs.installDir: ""
    fileTagsFilter: product.type
  }
}
