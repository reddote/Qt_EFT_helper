#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtEftHelper.h"
#include "JsonReader.h"
#include "CustomWeaponVectorList.h"
#include "BulletTable.h"
#include "CustomBulletList.h"
#include "NetworkHandler.h"
#include "MapController.h"

class QtEftHelper : public QMainWindow
{
    Q_OBJECT

public:
    QtEftHelper(QWidget *parent = nullptr);
	~QtEftHelper();
	void SetUI(int index);//index only took 0,1,2

private:
	QComboBox *weapons;
	QComboBox *bullets;
	QTableView *bulletTableView;
	BulletTable* customBulletTable;
	std::vector<CustomWeaponVectorList> weaponAndBulletList;
    Ui::QtEftHelperClass ui;
	JsonReader *jsonReader;
	NetworkHandler *jsonDownloader;
	MapController *mapController;
	void WeaponComboBoxUpdater();
	void JsonDowloadFromNet();
	void InitBulletFrame();
	void MapChanger(QString map);
	void Init();
	void MenuController();
	void ObjectInit();

signals:
	void menuButtonClicked();

public slots:
	void OnComboBoxIndexChanged(int index);

private slots:
	void BulletTableUpdater(int index);
	void onMenuButtonTriggered(const QString& mapName);
	void onMenuButtonTriggered(const int& pageNumber);

};
