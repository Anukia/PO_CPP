#pragma once
#include "Elektrownie.h"
#include <iostream>

using namespace std;

class Jadrowe :
	public Elektrownie
{
public:
	Jadrowe();
	void wyswietl_informacje();

protected:
	int liczba_reaktorow;
	bool czy_doswiadczalna;

private:
	bool czy_lisc;
};

