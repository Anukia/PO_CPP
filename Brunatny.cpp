#include "Brunatny.h"
#include <fstream>

Brunatny::Brunatny()
	:Weglowe()
{
	mod_wymiarziarna();
}

Brunatny::Brunatny(string p_nazwa)
	:Weglowe(p_nazwa)
{
	mod_wymiarziarna();
}

Brunatny::Brunatny(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia, float p_procent_wegla, float p_wymiarziarna)
	: Weglowe(p_nazwa, p_panstwo, p_moc, p_stan_skupienia, p_procent_wegla)
{
	wymiar_ziarna = p_wymiarziarna;
}

void Brunatny::wyswietl_informacje()
{
	Weglowe::wyswietl_informacje();
	cout << "Wymiar ziarna [mm]: " << wymiar_ziarna << endl;
}

void Brunatny::wyswietl_zapis(fstream &file)
{
	Weglowe::wyswietl_zapis(file);
	file << wymiar_ziarna << endl;
}

void Brunatny::mod_wymiarziarna()
{
	string tmp;
	cout << "Wymiar ziarna [mm]: "; getline(cin, tmp);
	if (tmp != "") wymiar_ziarna = stof(tmp);
	return;
}

void Brunatny::modyfikuj()
{
	Weglowe::modyfikuj();
	mod_wymiarziarna();
}