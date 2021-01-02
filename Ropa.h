#pragma once
#include "SurowcowNaturalnych.h"
#include <iostream>

using namespace std;

class Ropa :
	public SurowcowNaturalnych
{
public:
	Ropa(string p_nazwa);
	Ropa(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia, float p_spalonychl);
	void wyswietl_informacje();
	void wyswietl_zapis(fstream& plik);
	void modyfikuj();

protected:
	float liczba_spalonych_l;

	void mod_spalonychl();

private:
	static const bool czy_lisc = true;
};

