#include "JsonReader.h"
#include <QFile>
#include <QDebug>

JsonReader::JsonReader()
{
	
}

std::vector<QString> JsonReader::ReadJsonFile(const QString & fileName)
{
	std::vector<QString> keyList;
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "Failed to open file for reading";
		return keyList;
	}

	QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
	file.close();

	if (doc.isNull()) {
		qDebug() << "Failed to create JSON doc.";
		return keyList;
	}
	if (!doc.isObject()) {
		qDebug() << "JSON is not an object.";
		return keyList;
	}

	qWeapons = doc.object();
	for (const QString &key : qWeapons.keys()) {
		qBulletType = qWeapons.value(key).toArray();
		qDebug() << "Weapon:" << key;
		keyList.push_back(key);
		for (const QJsonValue &value : qBulletType) {
			qDebug() << "  Bullet Type:" << value.toString();
		}
	}
	
	return keyList;
}

JsonReader::~JsonReader()
{}
