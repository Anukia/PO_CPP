#include "Wodne.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Wodne::Wodne(string p_nazwa)
	:Elektrownie(p_nazwa)
{
	mod_zbiornik();
	mod_rodzaj();
	cout << "Obiekt dodano!" << endl;
}

Wodne::Wodne(string p_nazwa, string p_panstwo, float p_moc, string p_zbiornik, string p_rodzaj)
:Elektrownie(p_nazwa, p_panstwo, p_moc)
{
	zbiornik_wodny = p_zbiornik;
	rodzaj = p_rodzaj;
}

void Wodne::wyswietl_informacje()
{
	Elektrownie::wyswietl_informacje();
	cout << "Zbiornik wodny: " << zbiornik_wodny << endl;
	cout << "Rodzaj elektrowni: " << rodzaj << endl;
}

void Wodne::wyswietl_zapis(fstream &plik)
{
	Elektrownie::wyswietl_zapis(plik);
	plik << zbiornik_wodny << endl;
	plik << rodzaj << endl;
}

void Wodne::mod_zbiornik()
{
	string tmp;
	cout << "Zbiornik wodny: "; getline(cin, tmp);
	if (tmp != "") zbiornik_wodny = tmp;	
	return;
}

void Wodne::mod_rodzaj()
{
	string tmp;
	cout << "Rodzaj elektrowni: "; getline(cin, tmp);
	if (tmp != "") rodzaj = tmp;
	return;
}

void Wodne::modyfikuj()
{
	Elektrownie::modyfikuj();
	mod_zbiornik();
	mod_rodzaj();
	cout << "Obiekt zmodyfikowano!" << endl;
}