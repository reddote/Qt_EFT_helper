#include "../Header/MenuController.h"
#include <QDebug>

MenuController::MenuController(QGraphicsView* viewer, QObject *parent)
	: QObject(parent) {
	mapController = new MapController(viewer);
}

void MenuController::MapChanger(QString mapFile) {
	mapController->ChangeMapView(mapFile);
}

void MenuController::onMenuButtonTriggered(const QString& mapName) {
	// Emit the custom signal when the menu button is triggered
	emit menuButtonClicked();
	//QString mapFile = ":/QtEftHelper/Reseources/Shoreline.webp";
	MapChanger(mapName);
}
