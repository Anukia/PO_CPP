#include "Wodne.h"
#include <iostream>
#include <string>

using namespace std;

Wodne::Wodne(string p_nazwa)
	:Elektrownie(p_nazwa)
{
	mod_zbiornik();
	mod_turbina();
	cout << "Obiekt dodano!" << endl;
}

Wodne::Wodne(string p_nazwa, string p_zbiornik, string p_turbina, string p_panstwo, float p_moc)
:Elektrownie(p_nazwa, p_panstwo, p_moc)
{
	zbiornik_wodny = p_zbiornik;
	typ_turbiny = p_turbina;
}

void Wodne::wyswietl_informacje()
{
	Elektrownie::wyswietl_informacje();
	cout << "Zbiornik wodny: " << zbiornik_wodny << endl;
	cout << "Typ turbiny: " << typ_turbiny << endl;
}

void Wodne::mod_zbiornik()
{
	string tmp;
	cout << "Zbiornik wodny: "; getline(cin, tmp);
	if (tmp != "") zbiornik_wodny = tmp;	
	return;
}

void Wodne::mod_turbina()
{
	string tmp;
	cout << "Typ turbiny: "; getline(cin, tmp);
	if (tmp != "") typ_turbiny = tmp;
	return;
}

void Wodne::modyfikuj()
{
	Elektrownie::modyfikuj();
	mod_zbiornik();
	mod_turbina();
	cout << "Obiekt zmodyfikowano!" << endl;
}