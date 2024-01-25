#include "Header/NetworkHandler.h"
#include <QNetworkRequest>
#include <QJsonDocument>
#include <QJsonObject>
#include <openssl/ssl.h>
#include <openssl/err.h>

NetworkHandler::NetworkHandler(QObject *parent) : QObject(parent) {
	// Initialize OpenSSL
	SSL_library_init();
	OpenSSL_add_all_algorithms();
	SSL_load_error_strings();

	manager = new QNetworkAccessManager(this);
	connect(manager, &QNetworkAccessManager::finished, this, &NetworkHandler::onFinished);
}

void NetworkHandler::fetchJsonData(const QUrl &url) {
	
	QNetworkRequest request(url);
	manager->get(request);
}

void NetworkHandler::onFinished(QNetworkReply *reply) {
	QString strReply = reply->readAll();
	QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
	emit jsonReceived(jsonResponse.object());
	if (reply->error() == QNetworkReply::NoError) {
		QString strReply = reply->readAll();
		QJsonDocument jsonResponse = QJsonDocument::fromJson(strReply.toUtf8());
		emit jsonReceived(jsonResponse.object());
	}
	else {
		qDebug() << "Network error occurred:" << reply->errorString();
	}
	reply->deleteLater();
}
