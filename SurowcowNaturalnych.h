#pragma once
#include "Elektrownie.h"
#include <iostream>
#include <string>

using namespace std;

class SurowcowNaturalnych :
	public Elektrownie
{
public:
	SurowcowNaturalnych();
	SurowcowNaturalnych(string p_nazwa);
	SurowcowNaturalnych(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia);
	void wyswietl_informacje();
	void wyswietl_zapis(fstream& plik);
	void modyfikuj();

protected:
	string stan_skupienia;

	void mod_stan();

private:
	static const bool czy_lisc = false;
};

