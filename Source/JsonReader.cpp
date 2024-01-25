#include "Header/JsonReader.h"
#include <QFile>
#include <QDebug>

JsonReader::JsonReader()
{
	
}

std::vector<CustomWeaponVectorList> JsonReader::ReadFromJsonObject(const QJsonObject& jsonObject) {
	std::vector<CustomWeaponVectorList> keyList;

	for (const QString &key : jsonObject.keys()) {
		QJsonArray qBulletType = jsonObject.value(key).toArray();
		CustomWeaponVectorList customList;
		customList.key = key;
		for (const QJsonValue &value : qBulletType) {
			CustomBulletList tempValue(value);
			customList.values.push_back(tempValue);
		}
		keyList.push_back(customList);
	}

	return keyList;
}


JsonReader::~JsonReader()
{}
