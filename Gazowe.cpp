#include "Gazowe.h"
#include <iostream>
#include <fstream>

using namespace std;

Gazowe::Gazowe(string p_nazwa)
	:SurowcowNaturalnych(p_nazwa)
{
	mod_v_komory();
	cout << "Obiekt dodano!" << endl;
}

Gazowe::Gazowe(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia, float p_v_komory)
	:SurowcowNaturalnych(p_nazwa, p_panstwo, p_moc, p_stan_skupienia)
{
	v_komory_spalania = p_v_komory;
}

void Gazowe::wyswietl_informacje()
{
	SurowcowNaturalnych::wyswietl_informacje();
	cout << "Objetosc komory spalania: " << v_komory_spalania << endl;
}

void Gazowe::wyswietl_zapis(fstream &plik)
{
	SurowcowNaturalnych::wyswietl_zapis(plik);
	plik << v_komory_spalania << endl;
}

void Gazowe::mod_v_komory()
{
	string tmp;
	cout << "Objetosc komory spalania: "; getline(cin, tmp);
	if (tmp != "") v_komory_spalania = stof(tmp);
	return;
}

void Gazowe::modyfikuj()
{
	SurowcowNaturalnych::modyfikuj();
	mod_v_komory();
	cout << "Obiekt zmodyfikowano!" << endl;
}