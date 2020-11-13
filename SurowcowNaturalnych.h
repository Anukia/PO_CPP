#pragma once
#include "Elektrownie.h"
#include <iostream>

using namespace std;

class SurowcowNaturalnych :
	public Elektrownie
{
public:
	SurowcowNaturalnych();
	void wyswietl_informacje();

protected:
	string stan_skupienia;
	string zrodlo_surowca;

private:
	bool czy_lisc;
};

