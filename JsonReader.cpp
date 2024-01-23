#include "JsonReader.h"
#include <QFile>
#include <QDebug>

JsonReader::JsonReader()
{
	
}

void JsonReader::ReadJsonFile(const QString & fileName)
{
	QFile file(fileName);
	if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
		qDebug() << "Failed to open file for reading";
		return;
	}

	QJsonDocument doc = QJsonDocument::fromJson(file.readAll());
	file.close();

	if (doc.isNull()) {
		qDebug() << "Failed to create JSON doc.";
		return;
	}
	if (!doc.isObject()) {
		qDebug() << "JSON is not an object.";
		return;
	}

	qWeapons = doc.object();
	for (const QString &key : qWeapons.keys()) {
		qBulletType = qWeapons.value(key).toArray();
		qDebug() << "Weapon:" << key;
		for (const QJsonValue &value : qBulletType) {
			qDebug() << "  Bullet Type:" << value.toString();
		}
	}
}

JsonReader::~JsonReader()
{}
