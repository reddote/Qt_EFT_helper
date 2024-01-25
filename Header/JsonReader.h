#pragma once
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <vector>
#include "CustomWeaponVectorList.h"
#include "CustomBulletList.h"

class JsonReader
{
	QJsonObject qWeapons;
	QJsonArray qBulletType;

private:
	~JsonReader();

public:
	JsonReader();
	std::vector<CustomWeaponVectorList> ReadFromJsonObject(const QJsonObject& jsonObject);
};

