#include "Jadrowe.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

Jadrowe::Jadrowe(string p_nazwa)
	:Elektrownie(p_nazwa)
{
	mod_reaktor();
	mod_doswiadczalne();
	cout << "Obiekt dodano!" << endl;
}

Jadrowe::Jadrowe(string p_nazwa, string p_panstwo, float p_moc, int p_lreaktorow, string p_czy_doswiadczalne)
	:Elektrownie(p_nazwa, p_panstwo, p_moc)
{
	lreaktorow = p_lreaktorow;
	czy_doswiadczalna = p_czy_doswiadczalne;
}

void Jadrowe::wyswietl_informacje()
{
	Elektrownie::wyswietl_informacje();
	cout << "Liczba reaktorow: " << lreaktorow << endl;
	if (czy_doswiadczalna == "t" || czy_doswiadczalna == "T") cout << "Elektrownia doswiadczalna: tak" << endl;
	else if (czy_doswiadczalna == "n" || czy_doswiadczalna == "N") cout << "Elektrownia doswiadczalna: nie" << endl;
	else cout << "Elektrownia doswiadczalna: bledne informacje" << endl;
}

void Jadrowe::wyswietl_zapis(fstream &plik)
{
	Elektrownie::wyswietl_zapis(plik);
	plik << lreaktorow << endl;
	if (czy_doswiadczalna == "t" || czy_doswiadczalna == "T") plik << "t" << endl;
	else if (czy_doswiadczalna == "n" || czy_doswiadczalna == "N") plik << "n" << endl;
	else plik << "bledne informacje" << endl;
}

void Jadrowe::mod_reaktor()
{
	string tmp;
	cout << "Liczba reaktorow: "; getline(cin, tmp);
	if (tmp != "") lreaktorow = stoi(tmp);
	return;
}

void Jadrowe::mod_doswiadczalne()
{
	string tmp;
	cout << "Czy elektrownia jest doswiadczalna? [t/n] "; getline(cin, tmp);
	if (tmp != "") czy_doswiadczalna = tmp;
	return;
}

void Jadrowe::modyfikuj()
{
	Elektrownie::modyfikuj();
	mod_reaktor();
	mod_doswiadczalne();
	cout << "Obiekt zmodyfikowano!" << endl;
}