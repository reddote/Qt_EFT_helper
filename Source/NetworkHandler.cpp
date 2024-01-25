#include "Header/NetworkHandler.h"
#include <Curl/curl.h>
#include <fstream>
#include <iostream>

size_t writeData(void* ptr, size_t size, size_t nmemb, FILE* stream) {
	return fwrite(ptr, size, nmemb, stream);
}

bool NetworkHandler::DownloadFile(const std::string& url, const std::string& filepath) {
	CURL* curl = curl_easy_init();
	if (!curl) {
		std::cerr << "Curl initialization failed" << std::endl;
		return false;
	}

	FILE* fp = fopen(filepath.c_str(), "wb");
	if (!fp) {
		std::cerr << "Failed to open file for writing" << std::endl;
		curl_easy_cleanup(curl);
		return false;
	}

	curl_easy_setopt(curl, CURLOPT_CAINFO, "C:\\Curl\\curl-8.5.0_6-win64-mingw\\bin\\cacert.pem");
	curl_easy_setopt(curl, CURLOPT_URL, url.c_str());
	curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION, writeData);
	curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);

	CURLcode res = curl_easy_perform(curl);
	if (res != CURLE_OK) {
		std::cerr << "Curl perform failed: " << curl_easy_strerror(res) << std::endl;
		fclose(fp);
		curl_easy_cleanup(curl);
		return false;
	}

	fclose(fp);
	curl_easy_cleanup(curl);
	return true;
}