{\rtf1\ansi\deff0\nouicompat{\fonttbl{\f0\fnil\fcharset0 Courier New;}}
{\*\generator Riched20 10.0.19041}\viewkind4\uc1 
\pard\b\f0\fs50\lang1033 # Qt_EFT_helper\b0\fs22\par
\b\fs30 Escape From Tarkov Ballistic Information Table Viewer\b0\fs22\par
\par
This project is developed using Qt 5.6 and integrates libcurl with OpenSSL 1.1 for network operations. It is designed to run on platforms where these libraries are supported.\par
\par
\b\fs30 Prerequisites\par
\par
\b0\fs22 Before you begin, ensure you have met the following requirements:\par
\par
*Windows OS\par
*Visual Studio 2017\par
*Qt 5.6\par
*libcurl (compiled with OpenSSL 1.1 support)\par
*OpenSSL 1.1\par
\par
\par
\b\fs30 Setting Up\b0\fs22\par
To set up the development environment for this project:\par
\par
->Install Visual Studio 2017:\par
Download and install Visual Studio 2017 from the official site.\par
\par
->Install Qt 5.6:\par
Download Qt 5.6 and install it on your system.\par
During installation, select components that are relevant to your development, including the compiler used by Visual Studio 2017.\par
\par
->Install libcurl and OpenSSL:\par
Download and install libcurl. Ensure it is compiled with OpenSSL 1.1 support.\par
Download and install OpenSSL 1.1. Follow the installation instructions provided on their respective websites.\par
\par
->Configure Visual Studio with Qt 5.6:\par
Open your project in Visual Studio.\par
Configure the Qt Version in Visual Studio by going to \b Qt VS Tools > Qt Options > Add \b0 and navigate to your Qt installation.\par
Set up the Qt project settings by right-clicking on the project and selecting Qt Project Settings.\par
\par
->Linking libcurl and OpenSSL:\par
In Visual Studio, add the include paths of libcurl and OpenSSL to your project's \b C/C++ > General > Additional Include Directories.\par
\b0 Add the lib directories of \b libcurl \b0 and \b OpenSSL \b0 to \b Linker > General > Additional Library Directories.\par
\b0 Specify the necessary \b .lib \b0 files under \b Linker > Input > Additional Dependencies (e.g., libcurl.lib, libssl.lib, libcrypto.lib).\par
\b0\par
}
 