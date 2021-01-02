#pragma once
#include "SurowcowNaturalnych.h"
#include <iostream>
#include <string>

using namespace std;

class Weglowe :
	public SurowcowNaturalnych
{
public:
	Weglowe();
	Weglowe(string p_nazwa);
	Weglowe(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia, float p_procent_wegla);
	void wyswietl_informacje();
	void wyswietl_zapis(fstream& plik);
	void modyfikuj();

protected:
	float procent_wegla;
	void mod_procentwegla();

private:
	static const bool czy_lisc = false;
};

