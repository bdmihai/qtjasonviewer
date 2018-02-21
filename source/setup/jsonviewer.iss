; Script generated by the Inno Setup Script Wizard.
; SEE THE DOCUMENTATION FOR DETAILS ON CREATING INNO SETUP SCRIPT FILES!

#define MyAppName "JSON Viewer"
#define MyAppVersion "1.1.0"
#define MyAppPublisher "B.D. Mihai"
#define MyAppURL "https://github.com/bdmihai/qtjasonviewer"
#define MyAppExeName "json-viewer.exe"
#define MyQtDir "d:\work\libraries\qt\5.9.3\msvc2015_64"

[Setup]
; NOTE: The value of AppId uniquely identifies this application.
; Do not use the same AppId value in installers for other applications.
; (To generate a new GUID, click Tools | Generate GUID inside the IDE.)
AppID={{988F2D32-48B1-4669-8EEC-61B214605108}}
AppName={#MyAppName}
AppVersion = {#MyAppVersion}
AppVerName={#MyAppName} {#MyAppVersion}
AppPublisher={#MyAppPublisher}
AppPublisherURL={#MyAppURL}
AppSupportURL={#MyAppURL}
AppUpdatesURL={#MyAppURL}
DefaultDirName={pf}\{#MyAppName}
DefaultGroupName={#MyAppName}
AllowNoIcons=true
LicenseFile=..\..\doc\LICENSE.rtf
;InfoBeforeFile=..\doc\LICENSE.rtf
OutputDir=.\
OutputBaseFilename=JsonViewerSetup
Compression=lzma/Max
SolidCompression=true
ShowLanguageDialog=no
AppCopyright=Copyright (C) 2010-2018 B.D. Mihai.
SetupIconFile=setup.ico
WizardImageFile=wizimage.bmp
WizardSmallImageFile=smallimage.bmp

[Languages]
Name: "english"; MessagesFile: "compiler:Default.isl"

[Tasks]
Name: "desktopicon"; Description: "{cm:CreateDesktopIcon}"; GroupDescription: "{cm:AdditionalIcons}"; Flags: unchecked

[Files]
Source: "..\..\bin\{#MyAppExeName}"; DestDir: "{app}"; Flags: ignoreversion
Source: "vc_redist.x64.exe"; DestDir: {tmp}; Flags: deleteafterinstall
Source: "{#MyQtDir}\bin\opengl32sw.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#MyQtDir}\bin\libGLESv2.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#MyQtDir}\bin\libEGL.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#MyQtDir}\bin\d3dcompiler_47.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#MyQtDir}\bin\Qt5Core.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#MyQtDir}\bin\Qt5Gui.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#MyQtDir}\bin\Qt5Widgets.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#MyQtDir}\bin\Qt5Svg.dll"; DestDir: "{app}"; Flags: ignoreversion
Source: "{#MyQtDir}\plugins\platforms\qwindows.dll"; DestDir: "{app}\platforms"; Flags: ignoreversion
Source: "{#MyQtDir}\plugins\imageformats\qgif.dll"; DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "{#MyQtDir}\plugins\imageformats\qicns.dll"; DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "{#MyQtDir}\plugins\imageformats\qico.dll"; DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "{#MyQtDir}\plugins\imageformats\qjpeg.dll"; DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "{#MyQtDir}\plugins\imageformats\qsvg.dll"; DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "{#MyQtDir}\plugins\imageformats\qtga.dll"; DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "{#MyQtDir}\plugins\imageformats\qtiff.dll"; DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "{#MyQtDir}\plugins\imageformats\qwbmp.dll"; DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "{#MyQtDir}\plugins\imageformats\qwebp.dll"; DestDir: "{app}\imageformats"; Flags: ignoreversion
Source: "{#MyQtDir}\plugins\iconengines\qsvgicon.dll"; DestDir: "{app}\iconengines"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_uk.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_sk.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_ru.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_pl.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_ko.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_ja.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_it.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_hu.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_he.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_fr.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_fi.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_es.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_en.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_de.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_da.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_cs.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_ca.qm"; DestDir: "{app}\translations"; Flags: ignoreversion
Source: "{#MyQtDir}\translations\qt_bg.qm"; DestDir: "{app}\translations"; Flags: ignoreversion

[Icons]
Name: "{group}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"
Name: "{group}\{cm:UninstallProgram,{#MyAppName}}"; Filename: "{uninstallexe}"
Name: "{commondesktop}\{#MyAppName}"; Filename: "{app}\{#MyAppExeName}"; Tasks: desktopicon

[Run]
Filename: {app}\{#MyAppExeName}; Flags: nowait postinstall skipifsilent;
Filename: {tmp}\vc_redist.x64.exe; Parameters: "/install /quiet /norestart"; StatusMsg: "Installing VC++ 2015 Redistributables..."; Check: VCRedistNeedsInstall

[Code]
type
  INSTALLSTATE = Longint;
const
  INSTALLSTATE_INVALIDARG = -2;  { An invalid parameter was passed to the function. }
  INSTALLSTATE_UNKNOWN = -1;     { The product is neither advertised or installed. }
  INSTALLSTATE_ADVERTISED = 1;   { The product is advertised but not installed. }
  INSTALLSTATE_ABSENT = 2;       { The product is installed for a different user. }
  INSTALLSTATE_DEFAULT = 5;      { The product is installed for the current user. }

  { Visual C++ 2015 Redistributable }
  VC_2015_REDIST_X64 = '{EF1EC6A9-17DE-3DA9-B040-686A1E8A8B04}';

function MsiQueryProductState(szProduct: string): INSTALLSTATE;
  external 'MsiQueryProductStateA@msi.dll stdcall';

function VCVersionInstalled(const ProductID: string): Boolean;
begin
  Result := MsiQueryProductState(ProductID) = INSTALLSTATE_DEFAULT;
end;

function VCRedistNeedsInstall: Boolean;
begin
  Result := not (VCVersionInstalled(VC_2015_REDIST_X64));
end;
