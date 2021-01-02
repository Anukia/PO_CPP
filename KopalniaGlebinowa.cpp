#include "KopalniaGlebinowa.h"
#include <fstream>

KopalniaGlebinowa::KopalniaGlebinowa(string p_nazwa)
	:Kamienny(p_nazwa), Brunatny()
{
	mod_glebokosc();
	cout << "Obiekt dodano!" << endl;
}

KopalniaGlebinowa::KopalniaGlebinowa(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia, float p_procent_wegla, float p_lotne, float p_wymiarziarna, float p_glebokosc)
	:Kamienny(p_nazwa, p_panstwo, p_moc, p_stan_skupienia, p_procent_wegla, p_lotne), Brunatny(p_nazwa, p_panstwo, p_moc, p_stan_skupienia, p_procent_wegla, p_wymiarziarna)
{
	glebokosc = p_glebokosc;
}

void KopalniaGlebinowa::wyswietl_informacje()
{
	Kamienny::wyswietl_informacje();
	cout << "Wymiar ziarna [mm]: " << wymiar_ziarna << endl;
	cout << "Glebokosc kopalni [m]: " << glebokosc << endl;
}

void KopalniaGlebinowa::wyswietl_zapis(fstream &plik)
{
	Kamienny::wyswietl_zapis(plik);
	plik << wymiar_ziarna << endl;
	plik << glebokosc << endl;
}

void KopalniaGlebinowa::mod_glebokosc()
{
	string tmp;
	cout << "Glebokosc kopalni [m]: "; getline(cin, tmp);
	if (tmp != "") glebokosc = stof(tmp);
	return;
}

void KopalniaGlebinowa::modyfikuj()
{
	Kamienny::modyfikuj();
	Brunatny::mod_wymiarziarna();
	mod_glebokosc();
	cout << "Obiekt zmodyfikowano!" << endl;
}