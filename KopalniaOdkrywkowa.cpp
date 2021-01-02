#include "KopalniaOdkrywkowa.h"
#include <fstream>


KopalniaOdkrywkowa::KopalniaOdkrywkowa(string p_nazwa)
	:Brunatny(p_nazwa)
{
	mod_powierzchnia();
	cout << "Obiekt dodano!" << endl;
}

KopalniaOdkrywkowa::KopalniaOdkrywkowa(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia, float p_procent_wegla, float p_wymiarziarna, float p_powierzchnia)
	:Brunatny(p_nazwa, p_panstwo, p_moc, p_stan_skupienia, p_procent_wegla, p_wymiarziarna)
{
	powierzchnia = p_powierzchnia;
}

void KopalniaOdkrywkowa::wyswietl_informacje()
{
	Brunatny::wyswietl_informacje();
	cout << "Powierzchnia kopalni odkrywkowej [m^2]: " << powierzchnia << endl;
}

void KopalniaOdkrywkowa::wyswietl_zapis(fstream &plik)
{
	Brunatny::wyswietl_zapis(plik);
	plik << powierzchnia << endl;
}


void KopalniaOdkrywkowa::mod_powierzchnia()
{
	string tmp;
	cout << "Powierzchnia kopalni odkrywkowej [m^2]: "; getline(cin, tmp);
	if (tmp != "") powierzchnia = stof(tmp);
	return;
}

void KopalniaOdkrywkowa::modyfikuj()
{
	Brunatny::modyfikuj();
	mod_powierzchnia();
	cout << "Obiekt zmodyfikowano!" << endl;
}