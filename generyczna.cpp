#include <iostream>
#include <vector>
#include <fstream>

#include "Wodne.h"
#include "Jadrowe.h"
#include "KopalniaOdkrywkowa.h"
#include "KopalniaGlebinowa.h"
#include "Gazowe.h"
#include "Ropa.h"

using namespace std;

template<class Typ>

class Plik
{
	vector<Typ*> tab;

public:
	Plik(vector<Typ*> tmp)
	{
		for (auto i : tmp) tab.push_back(i);
	}

	void zapis(string klasa, fstream& plik)
	{
		for (auto i : tab)
		{
			plik << klasa << endl;
			i->wyswietl_zapis(plik);
		}
	}
	//komentarz w main
};