#include "SurowcowNaturalnych.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

SurowcowNaturalnych::SurowcowNaturalnych()
	:Elektrownie()
{
	//empty
}

SurowcowNaturalnych::SurowcowNaturalnych(string p_nazwa)
	:Elektrownie(p_nazwa)
{
	mod_stan();
}

SurowcowNaturalnych::SurowcowNaturalnych(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia)
	:Elektrownie(p_nazwa, p_panstwo, p_moc)
{
	stan_skupienia = p_stan_skupienia;
}

void SurowcowNaturalnych::wyswietl_informacje()
{
	Elektrownie::wyswietl_informacje();
	cout << "Stan skupienia surowca: " << stan_skupienia << endl;
}

void SurowcowNaturalnych::wyswietl_zapis(fstream &plik)
{
	Elektrownie::wyswietl_zapis(plik);
	plik << stan_skupienia << endl;
}

void SurowcowNaturalnych::mod_stan()
{
	string tmp;
	cout << "Stan skupienia surowca: "; getline(cin, tmp);
	if (tmp != "") stan_skupienia = tmp;
	return;
}

void SurowcowNaturalnych::modyfikuj()
{
	Elektrownie::modyfikuj();
	mod_stan();
}