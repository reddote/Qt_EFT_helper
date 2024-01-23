#include "QtEftHelper.h"

QtEftHelper::QtEftHelper(QWidget *parent)
    : QMainWindow(parent)
{
    ui.setupUi(this);
	jsonReader = new JsonReader();
	jsonReader->ReadJsonFile("C:\\Users\\3DDL\\Desktop\\QT_Test\\EftBullet.json");
}

QtEftHelper::~QtEftHelper()
{}
