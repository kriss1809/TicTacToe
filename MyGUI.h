#pragma once
#include <QtWidgets/QApplication>
#include <qlabel.h>
#include <qlineedit.h>
#include <qpushbutton.h>
#include <qmessagebox.h>
#include <QVBoxLayout>
#include <QHBoxLayout>
#include <qwidget.h>
#include <qslider.h>
#include <qcombobox.h>
#include <qlayout.h>
#include <qformlayout.h>
#include <qtableview.h>
#include <qobject.h>
#include <QString>
#include <QStringList>

#include "Joc.h"
#include "Service.h"
#include "MyTableView.h"
#include <algorithm>
#include <iostream>
#include <string>

using namespace std;

class MyGUI : public QWidget
{
	private:
		Service& srv;
		void initializare_componente();
		void incarcare_date(vector <Joc> v);
		void conectare();

		QLabel* lbl_dim = new QLabel{ "Dimensiune: " };
		QLabel* lbl_tabla = new QLabel{ "Tabla de joc: " };
		QLabel* lbl_jucator = new QLabel{ "Jucatorul curent: " };
		QLabel* lbl_stare = new QLabel{ "Starea jocului: " };
		QLabel* lbl_id = new QLabel{ "ID-ul jocului pe care doriti sa il modificati: " };

		QLineEdit* le_id = new QLineEdit;
		QLineEdit* le_dim = new QLineEdit;
		QLineEdit* le_tabla = new QLineEdit;
		QLineEdit* le_jucator = new QLineEdit;

		MyTableModel* model;
		QTableView* tabel = new QTableView;

		QPushButton* btn_adaugare = new QPushButton{ "Adaugare" };
		QPushButton* btn_modificare = new QPushButton{ "Modificare" };
		QPushButton* btn_tabla = new QPushButton{ "Creeaza tabla" };
		QComboBox* cb_stare = new QComboBox;

		QVBoxLayout* tablaLayout = new QVBoxLayout{};
		QWidget* tabla_joc = new QWidget;

	public:
		MyGUI(Service& s) : srv{ s }
		{
			initializare_componente();
			conectare();
			incarcare_date(srv.getAll());
		}

		void adaugare();
		void modificare();
		void creare_tabla();
		void clearLayout(QLayout* layout);
};

