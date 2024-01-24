#pragma once
#include <vector>
#include <QFile>
#include <QJsonObject>
#include <QJsonValue>
#include "CustomBulletList.h"

class CustomWeaponVectorList {
public:
	QString key;
	std::vector<CustomBulletList> values;
	
};

