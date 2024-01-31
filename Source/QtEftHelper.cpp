#include "Header/QtEftHelper.h"
#include <vector>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <QDebug>

QtEftHelper::QtEftHelper(QWidget *parent)
	: QMainWindow(parent)
{
	ui.setupUi(this);

	//Init Setup
	ObjectInit();
	JsonDowloadFromNet();
	SetUI(0);
	Init();
	//Setup End
	
	MenuController();
	
}

QtEftHelper::~QtEftHelper()
{}

void QtEftHelper::MenuController(){
	//Menu Controller
	//Map information for actioMenuButtons
	QString shoreline = ":/QtEftHelper/Reseources/Shoreline.webp";
	QString custom = ":/QtEftHelper/Reseources/custom.png";
	QAction *shorelineButton = ui.actionShorline;
	QAction *customButton = ui.actionCustom;

	int mapPage = 2;
	int bulletPage = 1;
	QMenu *menuMapButton = ui.menuMap;
	QAction *bulletMenuButton = ui.actionBulletType;
	QAction *quitMenuButton = ui.actionQuit;

	// Connect the menu button's triggered signal to the handler's slot
	connect(shorelineButton, &QAction::triggered, this, [this, shoreline]() {
		this->onMenuButtonTriggered(shoreline);
	});

	connect(customButton, &QAction::triggered, this, [this, custom]() {
		this->onMenuButtonTriggered(custom);
	});

	connect(menuMapButton, &QMenu::triggered, this, [this, mapPage]() {
		this->onMenuButtonTriggered(mapPage); });

	connect(bulletMenuButton, &QAction::triggered, this, [this, bulletPage]() {
		this->onMenuButtonTriggered(bulletPage); });

	connect(bulletMenuButton, &QAction::triggered, this, [this, bulletPage]() {
		this->onMenuButtonTriggered(bulletPage); });

	connect(quitMenuButton, &QAction::triggered, &QCoreApplication::quit);
	//MenuController End
}
void QtEftHelper::ObjectInit(){
	mapController = new MapController(ui.mapView);
	jsonReader = new JsonReader();
	customBulletTable = new BulletTable(this);
}

void QtEftHelper::SetUI(int index) {
	if (index == 0) {
		ui.frameBullet->setVisible(false);
		ui.frameMap->setVisible(false);
	}
	else if(index == 1) {
		ui.frameBullet->setVisible(true);
		ui.frameMap->setVisible(false);
		Init();
		InitBulletFrame();
	}
	else if (index == 2) {
		ui.frameBullet->setVisible(false);
		ui.frameMap->setVisible(true);
	}
	else{
		qDebug() << "Index must be between 0-3";
	}
}

void QtEftHelper::Init() {

	weapons = ui.weaponComboBox;
	bullets = ui.bulletComboBox;
	bulletTableView = ui.bulletTable;

	weaponAndBulletList = jsonReader->ReadJsonFile("C:\\Users\\3DDL\\Desktop\\QT_Test\\Eft.json");
}

void QtEftHelper::InitBulletFrame() {

	WeaponComboBoxUpdater();
	connect(weapons, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &QtEftHelper::OnComboBoxIndexChanged);
	/*connect(weapons, SIGNAL(currentIndexChanged(int)),
		this, SLOT(OnComboBoxIndexChanged(int)));//old imp*/
	connect(bullets, static_cast<void (QComboBox::*)(int)>(&QComboBox::currentIndexChanged),
		this, &QtEftHelper::BulletTableUpdater);
	/*connect(bullets, SIGNAL(currentIndexChanged(int)),
		this, SLOT(BulletTableUpdater(int)));//old imp*/

	QQmlApplicationEngine engine;
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

void QtEftHelper::MapChanger(QString map)
{
	mapController->ChangeMapView(map);
}

void QtEftHelper::WeaponComboBoxUpdater()
{
	weapons->clear();
	bullets->clear();

	for each (CustomWeaponVectorList var in weaponAndBulletList)
	{
		weapons->addItem(var.key);
	}
	
	for each (CustomBulletList var in weaponAndBulletList[weapons->currentIndex()].values)
	{
		bullets->addItem(var.type);
	}

}

void QtEftHelper::JsonDowloadFromNet()
{
	const std::string url = "https://raw.githubusercontent.com/reddote/EFTJSON/main/EftBullet.json";
	const std::string outputFilePath = "EFT.json";

	if (jsonDownloader->DownloadFile(url, outputFilePath)) {
		qDebug() << "Download successful";
	}
	else {
		qDebug() << "Download failed";
	}
}

void QtEftHelper::BulletTableUpdater(int index)
{	
	if(index >= 0){
		CustomBulletList bullet = weaponAndBulletList[weapons->currentIndex()].values[index];
		QModelIndex tableIndex = customBulletTable->index(0, 1);
		bool result = customBulletTable->setData(tableIndex, bullet.armor1, Qt::EditRole);
		tableIndex = customBulletTable->index(1, 1);
		result = customBulletTable->setData(tableIndex, bullet.armor2, Qt::EditRole);
		tableIndex = customBulletTable->index(2, 1);
		result = customBulletTable->setData(tableIndex, bullet.armor3, Qt::EditRole);
		tableIndex = customBulletTable->index(3, 1);
		result = customBulletTable->setData(tableIndex, bullet.armor4, Qt::EditRole);
		tableIndex = customBulletTable->index(4, 1);
		result = customBulletTable->setData(tableIndex, bullet.armor5, Qt::EditRole);
		tableIndex = customBulletTable->index(5, 1);
		result = customBulletTable->setData(tableIndex, bullet.armor6, Qt::EditRole);
		tableIndex = customBulletTable->index(6, 1);
		result = customBulletTable->setData(tableIndex, bullet.damage, Qt::EditRole);
		tableIndex = customBulletTable->index(7, 1);
		result = customBulletTable->setData(tableIndex, bullet.penetration, Qt::EditRole);
		tableIndex = customBulletTable->index(8, 1);
		result = customBulletTable->setData(tableIndex, bullet.armorDmg, Qt::EditRole);
		tableIndex = customBulletTable->index(9, 1);
		result = customBulletTable->setData(tableIndex, bullet.accuracy, Qt::EditRole);
		tableIndex = customBulletTable->index(10, 1);
		result = customBulletTable->setData(tableIndex, bullet.recoil, Qt::EditRole);
		tableIndex = customBulletTable->index(11, 1);
		result = customBulletTable->setData(tableIndex, bullet.fragChance, Qt::EditRole);
		tableIndex = customBulletTable->index(12, 1);
		result = customBulletTable->setData(tableIndex, bullet.light, Qt::EditRole);
		tableIndex = customBulletTable->index(13, 1);
		result = customBulletTable->setData(tableIndex, bullet.heavy, Qt::EditRole);
		tableIndex = customBulletTable->index(14, 1);
		result = customBulletTable->setData(tableIndex, bullet.speed, Qt::EditRole);
	}

}

void QtEftHelper::onMenuButtonTriggered(const QString & mapName)
{
	// Emit the custom signal when the menu button is triggered
	emit menuButtonClicked();
	//QString mapFile = ":/QtEftHelper/Reseources/Shoreline.webp";
	MapChanger(mapName);
}

void QtEftHelper::onMenuButtonTriggered(const int& pageNumber) {
	emit menuButtonClicked();
	if (pageNumber < 0 && pageNumber >2) {
		qDebug() << "Check Page number";
	}
	else {
		SetUI(pageNumber);
	}
}

void QtEftHelper::OnComboBoxIndexChanged(int index) {

	if (index < 0) {
		qDebug() << "Index less then 0";
	}
	else {
		bullets->clear();
		
		for each (CustomBulletList var in weaponAndBulletList[index].values)
		{
			bullets->addItem(var.type);
		}
		BulletTableUpdater(bullets->currentIndex());
	}
	
}



