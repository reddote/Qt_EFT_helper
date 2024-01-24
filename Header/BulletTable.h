#pragma once

#ifndef BULLETTABLE_H
#define BULLETTABLE_H

#include <QObject>
#include <QAbstractTableModel>

class BulletTable : public QAbstractTableModel {
	Q_OBJECT
public:
	explicit BulletTable(QObject * parent = nullptr);

	int rowCount(const QModelIndex &parent = QModelIndex()) const override;
	int columnCount(const QModelIndex &parent = QModelIndex()) const override;
	QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
	QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
	QHash<int, QByteArray> roleNames() const override;

	bool setData(const QModelIndex &index, const QVariant &value, int role = Qt::EditRole) override;
	Qt::ItemFlags flags(const QModelIndex &index) const override;

private:
	QStringList rowNames;
	static const int ROWS = 15;
	static const int COLUMNS = 2;

signals:

public slots:

};

#endif