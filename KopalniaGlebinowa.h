#pragma once
#include "Kamienny.h"
#include "Brunatny.h"
#include <iostream>

using namespace std;


class KopalniaGlebinowa :
	public Kamienny,  Brunatny
{
public:
	KopalniaGlebinowa(string p_nazwa);
	KopalniaGlebinowa(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia, float p_procent_wegla, float p_lotne, float p_wymiarziarna, float p_glebokosc);
	void wyswietl_informacje();
	void wyswietl_zapis(fstream& plik);
	void modyfikuj();

protected:
	float glebokosc;

	void mod_glebokosc();

private:
	static const bool czy_lisc = true;
};

