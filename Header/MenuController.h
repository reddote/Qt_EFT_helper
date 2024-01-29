#ifndef MENUCONTROLLER_H
#define MENUCONTROLLER_H

#include <QObject>
#include "MapController.h"

class MenuController : public QObject {
	Q_OBJECT

public:
	explicit MenuController(QGraphicsView* viewer, QObject *parent = nullptr);
	QGraphicsView *tempViewer;

protected:
	MapController *mapController;
	void MapChanger(QString map);

signals:
	void menuButtonClicked();

public slots:
	void onMenuButtonTriggered(const QString& mapName);
};

#endif 
