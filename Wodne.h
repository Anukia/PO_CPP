#pragma once
#include "Elektrownie.h"
#include <iostream>
#include <vector>

using namespace std;

class Wodne :
	public Elektrownie
{
public:
	Wodne(string p_nazwa);
	Wodne(string p_nazwa, string p_panstwo, float p_moc, string p_zbiornik, string p_rodzaj);
	void wyswietl_informacje();
	void wyswietl_zapis(fstream& plik);
	void modyfikuj();
	int operator + (Wodne l)
	{
		l.wyswietl_informacje();
		return 0;
	}

protected:
	string zbiornik_wodny;	//np. Wis³a, Odra...
	string rodzaj;

	void mod_zbiornik();
	void mod_rodzaj();

private:
	static const bool czy_lisc = true;
};

