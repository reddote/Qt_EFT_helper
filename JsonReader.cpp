#include "JsonReader.h"
#include <QFile>
#include <QDebug>

JsonReader::JsonReader()
{
	
}

std::vector<CustomWeaponVectorList> JsonReader::ReadJsonFile(const QString & fileName)
{
	std::vector<CustomWeaponVectorList> keyList;
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
		CustomWeaponVectorList *customList = new CustomWeaponVectorList();
		customList->key = key;
		for (const QJsonValue &value : qBulletType) {
			qDebug() << "  Bullet Type:" << value.toString();
			QString tempValue = value.toString();
			customList->values.push_back(tempValue);
		}

		keyList.push_back(*customList);
	}
	
	return keyList;
}


JsonReader::~JsonReader()
{}
