#include "Ropa.h"
#include <iostream>
#include <fstream>

using namespace std;

Ropa::Ropa(string p_nazwa)
	:SurowcowNaturalnych(p_nazwa)
{
	mod_spalonychl();
	cout << "Obiekt dodano!" << endl;
}

Ropa::Ropa(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia, float p_spalonychl)
	:SurowcowNaturalnych(p_nazwa, p_panstwo, p_moc, p_stan_skupienia)
{
	liczba_spalonych_l = p_spalonychl;
}

void Ropa::wyswietl_informacje()
{
	SurowcowNaturalnych::wyswietl_informacje();
	cout << "Liczba spalanych l/h: " << liczba_spalonych_l << endl;
}

void Ropa::wyswietl_zapis(fstream &plik)
{
	SurowcowNaturalnych::wyswietl_zapis(plik);
	plik << liczba_spalonych_l << endl;
}

void Ropa::mod_spalonychl()
{
	string tmp;
	cout << "Liczba spalanych l/h: "; getline(cin, tmp);
	if (tmp != "") liczba_spalonych_l = stof(tmp);
	return;
}

void Ropa::modyfikuj()
{
	SurowcowNaturalnych::modyfikuj();
	mod_spalonychl();
	cout << "Obiekt zmodyfikowano!" << endl;
}