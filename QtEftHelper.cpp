#include "QtEftHelper.h"
#include <vector>

QtEftHelper::QtEftHelper(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	WeaponComboBoxUpdater();
}



QtEftHelper::~QtEftHelper()
{}

void QtEftHelper::WeaponComboBoxUpdater()
{
	jsonReader = new JsonReader();
	QComboBox *weapons = ui.weaponList;
	weapons->clear();

	std::vector<QString> weaponList;
	weaponList = jsonReader->ReadJsonFile("C:\\Users\\3DDL\\Desktop\\QT_Test\\EftBullet.json");

	for each (QString var in weaponList)
	{
		weapons->addItem(var);
	}

}
