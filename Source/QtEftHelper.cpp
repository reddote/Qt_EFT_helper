#include "Header/QtEftHelper.h"
#include <vector>
#include <QQmlApplicationEngine>
#include <QQmlContext>

QtEftHelper::QtEftHelper(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	weapons = ui.weaponComboBox;
	bullets = ui.bulletComboBox;
	bulletTableView = ui.bulletTable;
	WeaponComboBoxUpdater();
	connect(weapons, SIGNAL(currentIndexChanged(int)), 
		this, SLOT(OnComboBoxIndexChanged(int)));
	connect(bullets, SIGNAL(currentIndexChanged(int)),
		this, SLOT(BulletTableUpdater(int)));


	QQmlApplicationEngine engine;
	customBulletTable = new BulletTable(this);
	bulletTableView->setModel(customBulletTable);
	if (customBulletTable) {
		engine.rootContext()->setContextProperty("myBulletTableModel", customBulletTable);
	}
	else {
		// Handle the error: customBulletTable is null
	}
	engine.load(QUrl(QStringLiteral("qrc:/QtEftHelper/qml/main.qml")));

	BulletTableUpdater(bullets->currentIndex());

}



QtEftHelper::~QtEftHelper()
{}

void QtEftHelper::WeaponComboBoxUpdater()
{
	jsonReader = new JsonReader();
	weapons->clear();
	bullets->clear();

	weaponAndBulletList = jsonReader->ReadJsonFile("C:\\Users\\3DDL\\Desktop\\QT_Test\\EftBullet.json");

	for each (CustomWeaponVectorList var in weaponAndBulletList)
	{
		weapons->addItem(var.key);
	}
	
	for each (CustomBulletList var in weaponAndBulletList[weapons->currentIndex()].values)
	{
		bullets->addItem(var.type);
	}

}

void QtEftHelper::BulletTableUpdater(int index)
{	
	if(index >= 0){
		CustomBulletList bullet = weaponAndBulletList[weapons->currentIndex()].values[index];
		QModelIndex tableIndex = customBulletTable->index(0, 0);
		bool result = customBulletTable->setData(tableIndex, bullet.armor1, Qt::EditRole);
		tableIndex = customBulletTable->index(1, 0);
		result = customBulletTable->setData(tableIndex, bullet.armor2, Qt::EditRole);
		tableIndex = customBulletTable->index(2, 0);
		result = customBulletTable->setData(tableIndex, bullet.armor3, Qt::EditRole);
		tableIndex = customBulletTable->index(3, 0);
		result = customBulletTable->setData(tableIndex, bullet.armor4, Qt::EditRole);
		tableIndex = customBulletTable->index(4, 0);
		result = customBulletTable->setData(tableIndex, bullet.armor5, Qt::EditRole);
		tableIndex = customBulletTable->index(5, 0);
		result = customBulletTable->setData(tableIndex, bullet.armor6, Qt::EditRole);
		tableIndex = customBulletTable->index(6, 0);
		result = customBulletTable->setData(tableIndex, bullet.damage, Qt::EditRole);
		tableIndex = customBulletTable->index(7, 0);
		result = customBulletTable->setData(tableIndex, bullet.penetration, Qt::EditRole);
		tableIndex = customBulletTable->index(8, 0);
		result = customBulletTable->setData(tableIndex, bullet.armorDmg, Qt::EditRole);
		tableIndex = customBulletTable->index(9, 0);
		result = customBulletTable->setData(tableIndex, bullet.accuracy, Qt::EditRole);
		tableIndex = customBulletTable->index(10, 0);
		result = customBulletTable->setData(tableIndex, bullet.recoil, Qt::EditRole);
		tableIndex = customBulletTable->index(11, 0);
		result = customBulletTable->setData(tableIndex, bullet.fragChance, Qt::EditRole);
		tableIndex = customBulletTable->index(12, 0);
		result = customBulletTable->setData(tableIndex, bullet.light, Qt::EditRole);
		tableIndex = customBulletTable->index(13, 0);
		result = customBulletTable->setData(tableIndex, bullet.heavy, Qt::EditRole);
		tableIndex = customBulletTable->index(14, 0);
		result = customBulletTable->setData(tableIndex, bullet.speed, Qt::EditRole);
	}

}

void QtEftHelper::OnComboBoxIndexChanged(int index) {

	bullets->clear();
	
	for each (CustomBulletList var in weaponAndBulletList[index].values)
	{
		bullets->addItem(var.type);
	}
	BulletTableUpdater(bullets->currentIndex());
}



