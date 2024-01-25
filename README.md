# Qt_EFT_helper
Escape From Tarkov Ballistic Information Table Viewer

This project is developed using Qt 5.6 and integrates libcurl with OpenSSL 1.1 for network operations. It is designed to run on platforms where these libraries are supported.

Prerequisites
Before you begin, ensure you have met the following requirements:

Windows OS
Visual Studio 2017
Qt 5.6
libcurl (compiled with OpenSSL 1.1 support)
OpenSSL 1.1


SSetting Up
To set up the development environment for this project:

Install Visual Studio 2017:
Download and install Visual Studio 2017 from the official site.

Install Qt 5.6:
Download Qt 5.6 and install it on your system.
During installation, select components that are relevant to your development, including the compiler used by Visual Studio 2017.

Install libcurl and OpenSSL:
Download and install libcurl. Ensure it is compiled with OpenSSL 1.1 support.
Download and install OpenSSL 1.1. Follow the installation instructions provided on their respective websites.

Configure Visual Studio with Qt 5.6:
Open your project in Visual Studio.
Configure the Qt Version in Visual Studio by going to Qt VS Tools > Qt Options > Add and navigate to your Qt installation.
Set up the Qt project settings by right-clicking on the project and selecting Qt Project Settings.

Linking libcurl and OpenSSL:
In Visual Studio, add the include paths of libcurl and OpenSSL to your project's C/C++ > General > Additional Include Directories.
Add the lib directories of libcurl and OpenSSL to Linker > General > Additional Library Directories.
Specify the necessary .lib files under Linker > Input > Additional Dependencies (e.g., libcurl.lib, libssl.lib, libcrypto.lib).
