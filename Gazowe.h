#pragma once
#include "SurowcowNaturalnych.h"
#include <iostream>

using namespace std;

class Gazowe :
	public SurowcowNaturalnych
{
public:
	Gazowe();
	void wyswietl_informacje();

protected:
	float v_komory_spalania;

private:
	bool czy_lisc;
};

