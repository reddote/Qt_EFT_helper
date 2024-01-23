#include "QtEftHelper.h"
#include <vector>

QtEftHelper::QtEftHelper(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	weapons = ui.weaponComboBox;
	bullets = ui.bulletComboBox;
	WeaponComboBoxUpdater();
	connect(weapons, SIGNAL(currentIndexChanged(int)), this, SLOT(OnComboBoxIndexChanged(int)));
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
	
	for each (QString var in weaponAndBulletList[weapons->currentIndex()].values)
	{
		bullets->addItem(var);
	}

}

void QtEftHelper::OnComboBoxIndexChanged(int index) {

	bullets->clear();
	
	for each (QString var in weaponAndBulletList[index].values)
	{
		bullets->addItem(var);
	}
}



