#pragma once
#include "Brunatny.h"
#include <iostream>

using namespace std;

class KopalniaOdkrywkowa :
	public Brunatny
{
public:
	KopalniaOdkrywkowa(string p_nazwa);
	KopalniaOdkrywkowa(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia, float p_procent_wegla, float p_wymiarziarna, float p_powierzchnia);
	void wyswietl_informacje();
	void wyswietl_zapis(fstream& plik);
	void modyfikuj();

protected:
	float powierzchnia;

	void mod_powierzchnia();

private:
	static const bool czy_lisc = true;
};

