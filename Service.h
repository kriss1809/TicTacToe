#pragma once
#include "Repo.h"
#include "Joc.h"

class Service
{

	private:
		Repo& repo;

		/*
		* genereaza un id random
		* return: id-ul generat (int)
		*/
		int generare_id();

	public:
		// Constructor, returneaza un obiect de tip Service
		Service(Repo& r) : repo{ r } {};

		/*
			adauga un joc la lista
		*/
		void adaugare(int dim, string tabla, string jucator, string stare);

		/*
		* modifica un joc cu aribute date
		* param id: id-ul jocului de modificat (int, id-ul trebuie sa existe)
		* param dim: dimensiunea tablei (int, trebuie sa fie intre 3 si 5)
		* param tabla: tabla de joc (string, trebuie sa aiba dim*dim caractere, caracterele trebuie sa fie X, 0 sau -)
		* param jucator: jucatorul care urmeaza sa mute (string, X sau 0)
		* param stare: starea jocului
		* return: lista de erori (string)
		*/
		string modificare(int id, int dim, string tabla, string jucator, string stare);


		// returneaza lista jocurilor (vector<Joc>)
		vector<Joc> getAll();

};

