#include "Header/BulletTable.h"

BulletTable::BulletTable(QObject *parent)
	: QAbstractTableModel(parent) {
	// Initialize row names here.
	rowNames << "Armor 1" << "Armor 2" << "Armor 3" << "Armor 4" << "Armor 5"
		<< "Armor 6" << "DMG" << "Pen Power" << "Armor DMG %" << "Accuracy%"
		<< "Recoil" << "FragChance" << "LightBleed%" << "HeavyBleed%" << "Speed m/s";
	columnValues.resize(rowNames.size());
	columnValues.fill("");
}


int BulletTable::rowCount(const QModelIndex & parent) const
{
	return ROWS;
}

int BulletTable::columnCount(const QModelIndex & parent) const
{
	return COLUMNS;
}

QVariant BulletTable::data(const QModelIndex &index, int role) const {
	if (!index.isValid() || role != Qt::DisplayRole) {
		return QVariant();
	}

	int row = index.row();
	int col = index.column();

	if (row < 0 || row >= columnValues.size()) {
		return QVariant(); // Return an invalid QVariant if row is out of bounds
	}

	if (col == 0) {
		return rowNames.at(row);
	}
	else if (col == 1) {
		return columnValues.at(row);
	}

	return QVariant();
}


QVariant BulletTable::headerData(int section, Qt::Orientation orientation, int role) const {
	if (role != Qt::DisplayRole) {
		return QVariant();
	}

	if (orientation == Qt::Horizontal) {
		if (section == 0) {
			return QString("Row Name");
		}
		else if (section == 1) {
			return QString("Value");
		}
	}
	else {
		// For vertical headers
		return QString::number(section + 1);
	}

	return QVariant();
}

QHash<int, QByteArray> BulletTable::roleNames() const
{
	return { {Qt::DisplayRole, "display"} };
}

bool BulletTable::setData(const QModelIndex &index, const QVariant &value, int role) {
	if (role != Qt::EditRole || !index.isValid()) {
		return false;
	}

	int row = index.row();
	int col = index.column();

	if (col == 1 && row < columnValues.size()) { // Second column
		columnValues[row] = value.toString();
		emit dataChanged(index, index, QVector<int>() << role);
		return true;
	}

	return false;
}

Qt::ItemFlags BulletTable::flags(const QModelIndex & index) const
{
	if (!index.isValid()) {
		return Qt::NoItemFlags;
	}
	return QAbstractTableModel::flags(index) | Qt::ItemIsEditable;
}
