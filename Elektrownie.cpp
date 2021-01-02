#include "Elektrownie.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Elektrownie::Elektrownie()
{
	//empty
}

Elektrownie::Elektrownie(string p_nazwa)
{
	nazwa = p_nazwa;
	mod_panstwo();
	mod_moc();
}

Elektrownie::Elektrownie(string p_nazwa, string p_panstwo, float p_moc)
{
	nazwa = p_nazwa;
	panstwo = p_panstwo;
	moc = p_moc;
}

void Elektrownie::wyswietl_informacje()
{
	cout << "Nazwa: " << nazwa << endl
		<< "Panstwo: " << panstwo << endl
		<< "Moc: " << moc << endl;
}

void Elektrownie::wyswietl_zapis(fstream &plik)
{
	plik << nazwa << endl
		<< panstwo << endl
		<< moc << endl;
}

void Elektrownie::mod_panstwo()
{
	string tmp;
	cout << "Panstwo: "; getline(cin, tmp);
	if (tmp != "") panstwo = tmp;
	return;
}

void Elektrownie::mod_moc()
{
	string tmp;
	cout << "Moc: "; getline(cin, tmp);
	if (tmp != "") moc = stof(tmp);
	return;
}

void Elektrownie::modyfikuj()
{
	cout << "Wpisz wartosci dla pol ktore chcesz zmodyfikowac, pozostale zostaw puste (enter)" << endl;
	mod_panstwo();
	mod_moc();
}