#pragma once
#include "SurowcowNaturalnych.h"
#include <iostream>

using namespace std;

class Gazowe :
	public SurowcowNaturalnych
{
public:
	Gazowe(string p_nazwa);
	Gazowe(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia, float p_v_komory);
	void wyswietl_informacje();
	void wyswietl_zapis(fstream &plik);
	void modyfikuj();

protected:
	float v_komory_spalania;

	void mod_v_komory();

private:
	static const bool czy_lisc = true;
};

