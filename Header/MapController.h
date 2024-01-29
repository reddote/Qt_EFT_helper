#ifndef MAPCONTROLLER_H
#define MAPCONTROLLER_H

#include <QGraphicsView>
#include <QGraphicsScene>
#include <QGraphicsPixmapItem>
#include <QWheelEvent>
#include <QMouseEvent>
#include <QScrollBar>
#include <QPointF>

class MapController : public QGraphicsView {
	Q_OBJECT

public:
	MapController(QWidget *parent = nullptr);
	MapController(QString pixmapFile, QWidget *parent = nullptr);
	void ChangeMapView(QString file);
	~MapController();

protected:
	void wheelEvent(QWheelEvent *event) override;
	void mousePressEvent(QMouseEvent *event) override;
	void mouseMoveEvent(QMouseEvent *event) override;
	void mouseReleaseEvent(QMouseEvent *event) override;

private:
	bool _dragging;
	QPointF _lastDragPoint;
	QPoint _lastPanPoint;
	void startPanning(const QPoint &pos);
	void doPanning(const QPoint &pos);
	void stopPanning();
	QGraphicsScene *scene;
};

#endif // MAPCONTROLLER