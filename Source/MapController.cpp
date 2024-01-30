#include "..\Header\MapController.h"
#include <QApplication>

MapController::MapController(QWidget *parent)
	: QGraphicsView(parent), scene(new QGraphicsScene(this)) {
}

void MapController::ChangeMapView(QString file)
{
	this->scene->clear();

	// Load an image
	QPixmap pixmap(file); // Replace with your image path

	// Create a pixmap item to be added to the scene
	item = new QGraphicsPixmapItem(pixmap);
	
	// Add and Set the item to the scene
	scene->addItem(item);
	this->setScene(scene);

	//Set the view's size
	this->setFixedSize(831, 431);
	this->fitInView(item, Qt::KeepAspectRatio);
}

//Mouse Controller Start
void MapController::wheelEvent(QWheelEvent *event) {
	// Zoom Factor
	double scaleFactor = 1.15;
	if (event->angleDelta().y() > 0) {
		// Zoom in
		scale(scaleFactor, scaleFactor);
	}
	else {
		// Zooming out
		scale(1.0 / scaleFactor, 1.0 / scaleFactor);
	}
}

void MapController::mousePressEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		startPanning(event->pos());
	}
	QGraphicsView::mousePressEvent(event);
}

void MapController::mouseMoveEvent(QMouseEvent *event) {
	if (_lastPanPoint != QPoint()) {
		doPanning(event->pos());
	}
	QGraphicsView::mouseMoveEvent(event);
}

void MapController::mouseReleaseEvent(QMouseEvent *event) {
	if (event->button() == Qt::LeftButton) {
		stopPanning();
	}
	QGraphicsView::mouseReleaseEvent(event);
}

void MapController::startPanning(const QPoint &pos) {
	_lastPanPoint = pos;
	setCursor(Qt::ClosedHandCursor);
}

void MapController::doPanning(const QPoint &pos) {
	QPoint delta = pos - _lastPanPoint;
	_lastPanPoint = pos;
	horizontalScrollBar()->setValue(horizontalScrollBar()->value() - delta.x());
	verticalScrollBar()->setValue(verticalScrollBar()->value() - delta.y());
}

void MapController::stopPanning() {
	_lastPanPoint = QPoint();
	setCursor(Qt::ArrowCursor);
}
//Mouse Controller End

MapController::~MapController()
{
	// Clean up
	delete scene;
}
