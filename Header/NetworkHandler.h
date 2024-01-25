#ifndef NETWORKHANDLER_H
#define NETWORKHANDLER_H

#include <QObject>
#include <QNetworkAccessManager>
#include <QNetworkReply>

class NetworkHandler : public QObject {
	Q_OBJECT

public:
	explicit NetworkHandler(QObject *parent = nullptr);
	void fetchJsonData(const QUrl &url);

private slots:
	void onFinished(QNetworkReply *reply);

private:
	QNetworkAccessManager *manager;

signals:
	void jsonReceived(const QJsonObject& jsonObject);
};

#endif // NETWORKHANDLER_H



