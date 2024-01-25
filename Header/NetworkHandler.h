#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include <string>

class NetworkHandler {
public:
	static bool DownloadFile(const std::string& url, const std::string& outputFilePath);
};

#endif // FILEDOWNLOADER