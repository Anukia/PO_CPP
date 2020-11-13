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
	Wodne(string p_nazwa, string p_zbiornik, string p_turbina, string p_panstwo, float p_moc);
	void wyswietl_informacje();
	void modyfikuj();

protected:
	string zbiornik_wodny;	//np. Wis³a, Odra...
	string typ_turbiny;

	void mod_zbiornik();
	void mod_turbina();

private:

};

