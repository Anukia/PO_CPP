#pragma once
#include "Elektrownie.h"
#include <iostream>
#include <string>

using namespace std;

class Jadrowe :
	public Elektrownie
{
public:
	Jadrowe(string p_nazwa);
	Jadrowe(string p_nazwa, string p_panstwo, float p_moc, int p_lreaktorow, string p_czy_doswiadczalne);
	void wyswietl_informacje();
	void wyswietl_zapis(fstream& plik);
	void modyfikuj();

protected:
	int lreaktorow;
	string czy_doswiadczalna;

	void mod_reaktor();
	void mod_doswiadczalne();

private:
	static const bool czy_lisc = true;
};

