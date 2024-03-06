#pragma once
#include "Joc.h"
#include <assert.h>
#include "Repo.h"
#include "Service.h"

void test_joc()
{
	Joc j{ 1, 3, "X-0X0-X00", "X", "Terminat" };
	assert(j.getDim() == 3);
	assert(j.getId() == 1);
	assert(j.getTabla() == "X-0X0-X00");
	assert(j.getJucator() == "X");
	assert(j.getStare() == "Terminat");
}

void teste()
{
	Repo repo{ "teste.txt" };
	Service srv{ repo };

	vector<Joc> jocuri = srv.getAll();
	assert(jocuri.size() > 0);
	assert(jocuri[0].getStare() <= jocuri[1].getStare());

	srv.adaugare(3, "X-0X0-X00", "X", "Terminat");
	string s = srv.modificare(1, 3, "X-0X0XX00", "X", "In derulare");
	assert(s.size() == 0);

	s = srv.modificare(1, 7, "X-0X0XX00", "X", "In derulare");
	assert(s.size() > 0);

	s = srv.modificare(1001, 3, "X-0X0XX00", "X", "In derulare");
	assert(s.size() > 0);

	s = srv.modificare(1, 3, "X-1X0XX0000000", "9", "In derulare");
	assert(s.size() > 0);


}

void testAll()
{
	test_joc();
	teste();
}