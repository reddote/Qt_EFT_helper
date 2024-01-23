#pragma once
#include <QJsonObject>
#include <QJsonArray>
#include <QJsonDocument>
#include <vector>

class JsonReader
{
	QJsonObject qWeapons;
	QJsonArray qBulletType;

private:
	~JsonReader();

public:
	JsonReader();
	std::vector<QString> ReadJsonFile(const QString &fileName);
};

