## Intro
[wxWidgets](https://github.com/wxWidgets/wxWidgets) "Hello World" CMake cross-platform example project.

![MainWindow](doc/screenshots/MainWindow.png)

Tested on:
 - Linux (Ubuntu)
 - Windows 

## CI Status
[![CI](https://github.com/nkh-lab/wxwidgets-hello-world/actions/workflows/ci.yml/badge.svg)](https://github.com/nkh-lab/wxwidgets-hello-world/actions/workflows/ci.yml) 

Ubuntu | Windows 

## How to build
### Linux (Ubuntu)

1. Install dependencies
```
$ sudo apt-get install libwxgtk3.0-gtk3-dev
```
2. Build
```
mkdir build && cd build
cmake ..
make
```
Or via script for creating portable package:
```
.\tools\build-portable-linux.sh
```

### Windows
The following describes how to build the project from the command line for the compiler from Visual Studio.

1. Add `msbuild` to `PATH` environment variable if it's unset:
```
set PATH=%PATH%;<path to msbuild>
```
2. Downloads prebuilts libraries (Debug and Release) and hedears from [wxWidgets/releases](https://github.com/wxWidgets/wxWidgets/releases), for example for [wxWidgets 3.2.1](https://github.com/wxWidgets/wxWidgets/releases/tag/v3.2.1) version:
- Debug libraries: [wxMSW-3.2.1_vc14x_x64_Dev.7z](https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.1/wxMSW-3.2.1_vc14x_x64_Dev.7z)
- Release libraries: [wxMSW-3.2.1_vc14x_x64_ReleaseDLL.7z](https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.1/wxMSW-3.2.1_vc14x_x64_ReleaseDLL.7z)
- Headers: [wxWidgets-3.2.1-headers.7z](https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.1/wxWidgets-3.2.1-headers.7z) 
3. Unpack and link downloaded stuff to project prebuilt folder:
```
mkdir prebuilt\wxwidgets\lib && cd prebuilt\wxwidgets\lib
mklink /D Debug d:\Downloads\wxMSW-3.2.1_vc14x_x64_Dev\lib\vc14x_x64_dll
mklink /D Release d:\Downloads\wxMSW-3.2.1_vc14x_x64_ReleaseDLL\lib\vc14x_x64_dll
```
```
cd prebuilt\wxwidgets
mklink /D include d:\Downloads\wxWidgets-3.2.1-headers\include
```
4. Build
```
mkdir build && cd build
cmake -G "Visual Studio 17 2022" ..
cmake --build . --config Release
```
Or via script for creating portable package:
```
.\tools\build-portable-windows.bat
```

## Notes
### wxWidgets objects deletion
According to [Window Deletion](https://docs.wxwidgets.org/3.0/overview_windowdeletion.html) spec wxWidgects are suicide objects 
and must have not be deleted by `delete` operator.

Example of the callstack during app closing:
```
virtual MainWindow::~MainWindow()
virtual int App::OnExit()
virtual App::~App()
```