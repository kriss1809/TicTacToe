#pragma once
#include <string>

using std::string;

class Joc
{
private:
	int id;
	int dim;
	string tabla;
	string jucator_curent;
	string stare;
public:

	// constructorii clasei
	Joc() = default;
	Joc(int i, int d, string t, string j, string s) :id{ i }, dim{ d }, tabla{ t }, jucator_curent{ j }, stare{ s } {};
	Joc(const Joc& ot): id{ ot.id }, dim{ ot.dim }, tabla{ ot.tabla }, jucator_curent{ ot.jucator_curent }, stare{ ot.stare } {};

	// returneaza id-ul jocului
	int getId() const
	{
		return id;
	}

	// returneaza dimensiunea tablei de joc
	int getDim() const
	{
		return dim;
	}

	// returneaza tabla jocului
	string getTabla() const
	{
		return tabla;
	}

	// returneaza jucatorul al carui rand este
	string getJucator() const
	{
		return jucator_curent;
	}

	// returneaza starea jocului
	string getStare() const
	{
		return stare;
	}
};

