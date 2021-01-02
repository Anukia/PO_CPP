#include "Weglowe.h"
#include <fstream>

Weglowe::Weglowe()
	:SurowcowNaturalnych()
{
	//empty
}

Weglowe::Weglowe(string p_nazwa)
	:SurowcowNaturalnych(p_nazwa)
{
	mod_procentwegla();
}

Weglowe::Weglowe(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia, float p_procent_wegla)
	: SurowcowNaturalnych(p_nazwa, p_panstwo, p_moc, p_stan_skupienia)
{
	procent_wegla = p_procent_wegla;
}

void Weglowe::wyswietl_informacje()
{
	SurowcowNaturalnych::wyswietl_informacje();
	cout << "Procent czystego wegla: " << procent_wegla << endl;
}

void Weglowe::wyswietl_zapis(fstream &plik)
{
	SurowcowNaturalnych::wyswietl_zapis(plik);
	plik << procent_wegla << endl;
}

void Weglowe::mod_procentwegla()
{
	string tmp;
	cout << "Procent czystego wegla: "; getline(cin, tmp);
	if (tmp != "") procent_wegla = stof(tmp);
	return;
}

void Weglowe::modyfikuj()
{
	SurowcowNaturalnych::modyfikuj();
	mod_procentwegla();
}