#pragma once
#include "Weglowe.h"
#include <iostream>

using namespace std;

class Brunatny :
	public Weglowe
{
public:
	Brunatny();
	Brunatny(string p_nazwa);
	Brunatny(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia, float p_procent_wegla, float p_wymiarziarna);
	void wyswietl_informacje();
	void wyswietl_zapis(fstream &file);
	void modyfikuj();

protected:
	float wymiar_ziarna;

	void mod_wymiarziarna();

private:
	static const bool czy_lisc = false;
};

