#include "Repo.h"
#include <fstream>
#include <sstream>

void Repo::sortare()
{
	for (int i = 0; i < jocuri.size() - 1; i++)
		for (int j = i+1; j < jocuri.size(); j++)
			if (jocuri[i].getStare() > jocuri[j].getStare())
				swap(jocuri[i], jocuri[j]);
}

vector<Joc> Repo::getAll()
{
	sortare();
	return jocuri;
}


void Repo::adaugare(Joc j)
{
	jocuri.push_back(j);
	save_to_file();
}

void Repo::modificare(const Joc& J)
{
	for (int i = 0; i < this->jocuri.size(); i++)
		if (jocuri[i].getId() == J.getId())
		{
			jocuri[i] = J;
			break;}

	save_to_file();
}

void Repo::load_from_file()
{
	ifstream fin(filename);

	string linie;
	while (getline(fin, linie))
	{
		stringstream linestream(linie);
		string item;
		int curent = 0;

		int id, dim;
		string tabla, jucator, stare;

		while (getline(linestream, item, '|'))
		{
			if (curent == 0)
				id = stoi(item);
			else if (curent == 1)
				dim = stoi(item);
			else if (curent == 2)
				tabla = item;
			else if (curent == 3)
				jucator = item;
			else if (curent == 4)
				stare = item;

			curent++;
		}

		Joc J{ id, dim, tabla, jucator, stare };
		jocuri.push_back(J);
	}
	

	fin.close();
}

void Repo::save_to_file()
{
	ofstream fout(filename);
	for (auto j : jocuri)
		fout << j.getId() << "|" << j.getDim() << "|" << j.getTabla() << "|" << j.getJucator() << "|" << j.getStare() << endl;
	fout.close();
}
