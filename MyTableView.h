#pragma once
#include "Joc.h"
#include <QAbstractTableModel>
#include <vector>

using std::vector;

class MyTableModel : public QAbstractTableModel
{
private:
	vector <Joc> jocuri;

public:
	MyTableModel(const vector<Joc>& j) : jocuri{ j } {};

	int rowCount(const QModelIndex& parent = QModelIndex()) const override
	{
		return jocuri.size();
	}

	int columnCount(const QModelIndex& parent = QModelIndex()) const override
	{
		return 5;
	}

	QVariant data(const QModelIndex& index, int role = Qt::DisplayRole) const override
	{
		Joc j = jocuri[index.row()];

		if (role == Qt::DisplayRole)
		{
			if (index.column() == 0)
				return QString::number(j.getId());
			else if (index.column() == 1)
				return QString::number(j.getDim());
			else if (index.column() == 2)
				return QString::fromStdString(j.getTabla());
			else if (index.column() == 3)
				return QString::fromStdString(j.getJucator());
			else if (index.column() == 4)
				return QString::fromStdString(j.getStare());
		}
		return QVariant{};
	}

	void regenerare_tabel(const vector<Joc>& j)
	{
		jocuri = j;
		auto topLeft = createIndex(0, 0);
		auto bottomRight = createIndex(rowCount(), columnCount());
		emit dataChanged(topLeft, bottomRight);
		emit layoutChanged();
	}

};
