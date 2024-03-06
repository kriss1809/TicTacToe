#include "MyGUI.h"

void MyGUI::initializare_componente()
{
	QHBoxLayout* ly_main = new QHBoxLayout;
	this->setLayout(ly_main);

	QWidget* dr = new QWidget;
	QWidget* st = new QWidget;
	QVBoxLayout* ly_dr = new QVBoxLayout;
	QVBoxLayout* ly_st = new QVBoxLayout;
	dr->setLayout(ly_dr);
	st->setLayout(ly_st);

	model = new MyTableModel{srv.getAll()};
	tabel->setSelectionBehavior(QAbstractItemView::SelectRows);
	tabel->setModel(model);
	ly_st->addWidget(tabel);

	QWidget* form = new QWidget;
	QFormLayout* ly_form = new QFormLayout;
	form->setLayout(ly_form);

	cb_stare->addItem("Neinceput");
	cb_stare->addItem("In derulare");
	cb_stare->addItem("Terminat");

	ly_form->addRow(lbl_dim, le_dim);
	ly_form->addRow(lbl_tabla, le_tabla);
	ly_form->addRow(lbl_jucator, le_jucator);
	ly_form->addRow(lbl_stare, cb_stare);
	ly_form->addRow(lbl_id, le_id);
	ly_form->addRow(btn_adaugare);
	ly_form->addRow(btn_modificare);
	ly_form->addRow(btn_tabla);

	ly_dr->addWidget(form);

	tabla_joc->setLayout(tablaLayout);
	ly_dr->addWidget(tabla_joc);

	ly_main->addWidget(st);
	ly_main->addWidget(dr);

}
void MyGUI::conectare()
{
	QObject::connect(btn_adaugare, &QPushButton::clicked, this, &MyGUI::adaugare);
	QObject::connect(btn_modificare, &QPushButton::clicked, this, &MyGUI::modificare);
	QObject::connect(btn_tabla, &QPushButton::clicked, this, &MyGUI::creare_tabla);

	QObject::connect(tabel, &QTableView::pressed, [&]() {
		auto sel = tabel->selectionModel();
		if (sel->selectedRows().size() > 0)
		{
			QModelIndex index = sel->selectedRows().at(0);
			QAbstractItemModel* model = tabel->model();
			QVariant id = model->data(model->index(index.row(), 0));
			QVariant dim = model->data(model->index(index.row(), 1));
			QVariant tabla = model->data(model->index(index.row(), 2));
			QVariant jucator = model->data(model->index(index.row(), 3));
			QVariant stare = model->data(model->index(index.row(), 4));
		
			le_id->setText(id.toString());
			le_dim->setText(dim.toString());
			le_tabla->setText(tabla.toString());
			le_jucator->setText(jucator.toString());
			cb_stare->setCurrentText(stare.toString());
		}

	});

}

void MyGUI::incarcare_date(vector <Joc> v)
{
	model->regenerare_tabel(v);
}

void MyGUI::adaugare()
{
	int dim = stoi(le_dim->text().toStdString());
	string tabla = le_tabla->text().toStdString();
	string jucator = le_jucator->text().toStdString();
	string stare = "Neinceput";

	srv.adaugare(dim, tabla, jucator, stare);
	incarcare_date(srv.getAll());
}

void MyGUI::modificare()
{
	int dim = stoi(le_dim->text().toStdString());
	string tabla = le_tabla->text().toStdString();
	string jucator = le_jucator->text().toStdString();
	string stare = cb_stare->currentText().toStdString();
	int id = stoi(le_id->text().toStdString());

	string erori = srv.modificare(id, dim, tabla, jucator, stare);
	if (erori.size() > 0)
		QMessageBox::warning(this, "warning", QString::fromStdString(erori));

	incarcare_date(srv.getAll());
}

void MyGUI::creare_tabla()
{
	clearLayout(tablaLayout);

	int dim = stoi(le_dim->text().toStdString());
	string tabla = le_tabla->text().toStdString();
	int id = stoi(le_id->text().toStdString());
	string stare = cb_stare->currentText().toStdString();

	QWidget* linie = new QWidget;
	QHBoxLayout* ly = new QHBoxLayout;
	linie->setLayout(ly);

	for (int i = 0; i < tabla.size(); i++)
	{

		if (i % dim == 0 && i > 0)
		{
			ly = new QHBoxLayout;
			linie = new QWidget;
			linie->setLayout(ly);
		}
			
		char caracter = tabla[i];
		if (caracter == '-')
			caracter = ' ';
		QPushButton* btn = new QPushButton(QString(caracter));
		ly->addWidget(btn);
		tablaLayout->addWidget(linie);
		
		QObject::connect(btn, &QPushButton::clicked, this, [=]() {

			if (btn->text().toStdString() == " ")
			{
				string curent = le_jucator->text().toStdString();

				btn->setText(QString::fromStdString(curent));

				//tabla[i] = curent[0];
				string t;
				for (int k = 0; k < tabla.size(); k++)
					if (k != i)
						t += tabla[k];
					else
						t += curent[0];
				/// 

				string next;
				if (curent == "X")
					next = "0";
				else
					next = "X";

				le_jucator->setText(QString::fromStdString(next));
				le_tabla->setText(QString::fromStdString(t));
				srv.modificare(id, dim, t, next, stare);
				incarcare_date(srv.getAll());
				creare_tabla();
			}

			});
		

	}
}

void MyGUI::clearLayout(QLayout* layout) {
	if (layout == NULL)
		return;
	QLayoutItem* item;
	while ((item = layout->takeAt(0))) {
		if (item->layout()) {
			clearLayout(item->layout());
			delete item->layout();
		}
		if (item->widget()) {
			delete item->widget();
		}
		delete item;
	}
}