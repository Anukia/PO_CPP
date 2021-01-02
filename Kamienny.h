#pragma once
#include "Weglowe.h"
#include <iostream>

using namespace std;

class Kamienny :
	public Weglowe
{
public:
	Kamienny(string p_nazwa);
	Kamienny(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia, float p_procent_wegla, float p_lotne);
	void wyswietl_informacje();
	void wyswietl_zapis(fstream& plik);
	void modyfikuj();

protected:
	float procent_czesci_lotnych;

	void mod_lotne();

private:
	static const bool czy_lisc = false;
};

