#pragma once
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>

class JsonReader
{
	QJsonObject qWeapons;
	QJsonArray qBulletType;

private:
	~JsonReader();

public:
	JsonReader();
	void ReadJsonFile(const QString &fileName);
};

