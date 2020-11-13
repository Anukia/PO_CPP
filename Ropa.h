#pragma once
#include "SurowcowNaturalnych.h"
#include <iostream>

using namespace std;

class Ropa :
	public SurowcowNaturalnych
{
public:
	Ropa();
	void wyswietl_informacje();

protected:
	float liczba_spalonych_l;

private:

};

