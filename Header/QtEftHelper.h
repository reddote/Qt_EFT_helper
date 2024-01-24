#pragma once

#include <QtWidgets/QMainWindow>
#include "ui_QtEftHelper.h"
#include "JsonReader.h"
#include "CustomWeaponVectorList.h"
#include "BulletTable.h"
#include "CustomBulletList.h"

class QtEftHelper : public QMainWindow
{
    Q_OBJECT

public:
    QtEftHelper(QWidget *parent = nullptr);
    ~QtEftHelper();

private:
	QComboBox *weapons;
	QComboBox *bullets;
	QTableView *bulletTableView;
	BulletTable* customBulletTable;
	std::vector<CustomWeaponVectorList> weaponAndBulletList;
    Ui::QtEftHelperClass ui;
	JsonReader *jsonReader;
	void WeaponComboBoxUpdater();

private slots:
	void OnComboBoxIndexChanged(int index);
	void BulletTableUpdater(int index);


};