#include "Header/BulletTable.h"

BulletTable::BulletTable(QObject *parent)
	: QAbstractTableModel(parent) {
	// Initialize row names here.
	rowNames << "Armor 1" << "Armor 2" << "Armor 3" << "Armor 4" << "Armor 5"
		<< "Armor 6" << "DMG" << "Pen Power" << "Armor DMG %" << "Accuracy%"
		<< "Recoil" << "FragChance" << "LightBleed%" << "HeavyBleed%" << "Speed m/s";
}


int BulletTable::rowCount(const QModelIndex & parent) const
{
	return ROWS;
}

int BulletTable::columnCount(const QModelIndex & parent) const
{
	return COLUMNS;
}

QVariant BulletTable::data(const QModelIndex & index, int role) const
{
	if (!index.isValid() || role != Qt::DisplayRole) {
		return QVariant();
	}

	if (index.column() == 0) { // Single column
		return rowNames.at(index.row());
	}
	

	return QVariant();
}

QVariant BulletTable::headerData(int section, Qt::Orientation orientation, int role) const
{
	if (role != Qt::DisplayRole)
		return QVariant();

	if (orientation == Qt::Horizontal) {
		// Set the header title for the column here
		return QString("Header Title");
	}
	else {
		// Optional: For vertical headers
		return QString::number(section + 1); // Row numbers
	}
}

QHash<int, QByteArray> BulletTable::roleNames() const
{
	return { {Qt::DisplayRole, "display"} };
}

bool BulletTable::setData(const QModelIndex & index, const QVariant & value, int role)
{
	if (index.row() < 0 || index.row() >= rowNames.size() || role != Qt::EditRole) {
		return false;
	}

	rowNames[index.row()] = value.toString();
	emit dataChanged(index, index, { role });
	return true;
}

Qt::ItemFlags BulletTable::flags(const QModelIndex & index) const
{
	if (!index.isValid()) {
		return Qt::NoItemFlags;
	}
	return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
