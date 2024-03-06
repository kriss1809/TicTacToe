#include "Service.h"
#include <random>

int Service::generare_id()
{
	bool gasit = false;
	int id;
	while (!gasit)
	{
		bool pp = true;
		id = rand() % 1000;
		for (auto j : getAll())
			if (j.getId() == id)
				pp = false;
		if (pp)
			gasit = true;
	}
	return id;
}

void Service::adaugare(int dim, string tabla, string jucator, string stare)
{
	int id = generare_id();
	Joc j{ id, dim, tabla, jucator, stare };
	repo.adaugare(j);
}
string Service::modificare(int id, int dim, string tabla, string jucator, string stare)
{
	string erori;

	bool p = false;
	for (auto j : getAll())
		if (j.getId() == id)
			p = true;

	if(p==false)
		erori += "Jocul cu ID-ul dat nu exista\n";

	if (dim < 3 || dim > 5)
		erori += "Dimensiunea trebuie sa fie 3, 4 sau 5\n";
	else
	{
		if (tabla.size() != dim * dim)
			erori += "Tabla trebuie sa aiba dim*dim caractere\n";

		bool pp = true;
		for (int i = 0; i < tabla.size(); i++)
			if (tabla[i] != 'X' && tabla[i] != '0' && tabla[i] != '-')
				pp = false;

		if(pp==false)
			erori += "Tabla trebuie sa contina doar caracterele X, 0, -\n";
	}
	if(jucator!="X" && jucator!="0")
		erori += "Jucatorul poate fi X sau 0\n";

	if (erori.size() == 0)
	{
		Joc j{ id, dim, tabla, jucator, stare };
		repo.modificare(j);
	}
	
	return erori;
}

vector<Joc> Service::getAll()
{
	return repo.getAll();
}
