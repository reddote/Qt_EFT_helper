#pragma once
#ifndef CUSTOMBULLETLIST_H
#define CUSTOMBULLETLIST_H

#include <QFile>
#include <QJsonObject>
#include <QJsonValue>

class CustomBulletList {
public:
	CustomBulletList(const QJsonValue &value) {
		// Assuming 'value' is a JSON object
		QJsonObject obj = value.toObject();

		// Initialize each field from the JSON object
		type = obj["type"].toString();
		armor1 = obj["armor1"].toString();
		armor2 = obj["armor2"].toString();
		armor3 = obj["armor3"].toString();
		armor4 = obj["armor4"].toString();
		armor5 = obj["armor5"].toString();
		armor6 = obj["armor6"].toString();
		damage = obj["damage"].toString();
		penetration = obj["penetration"].toString();
		recoil = obj["recoil"].toString();
		fragChance = obj["fragChance"].toString();
		light = obj["light"].toString();
		heavy = obj["heavy"].toString();
		speed = obj["speed"].toString();

	}

	QString type;
	QString armor1;
	QString armor2;
	QString armor3;
	QString armor4;
	QString armor5;
	QString armor6;
	QString damage;
	QString penetration;
	QString armorDmg;
	QString accuracy;
	QString recoil;
	QString fragChance;
	QString light;
	QString heavy;
	QString speed;
};

#endif