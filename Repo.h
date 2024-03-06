#pragma once
#include <string>
#include <vector>
#include "Joc.h"

using namespace std;

class Repo
{
	private:
		string filename;
		vector<Joc> jocuri;

	public:
		// Constructorii clasei, returneaza un obiect de tip Repo
		Repo() = default;
		Repo(string f) :filename{ f } 
		{
			load_from_file();
		}

		// incarca datele din fisier
		// return: -
		void load_from_file();

		// salveaza datele in fisier
		// return: -
		void save_to_file();

		// sorteaza lista de jocuri alfabetic (crescator) dupa stare
		// return: -
		void sortare();

		/*
		* adauga un joc la lista de jocuri
		* param j: jocul de adaugat (Joc)
		* // return: -
		*/
		void adaugare(Joc j);

		/*
		* modifica un joc existent din lista de jocuri
		* param j: jocul modificat (Joc)
		* // return: -
		*/
		void modificare(const Joc& J);

		/*
		* Returneaza lista cu jocuri
		* return: lista (vector <Joc>)
		*/
		vector<Joc> getAll();
};

