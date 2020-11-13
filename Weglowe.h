#pragma once
#include "SurowcowNaturalnych.h"
#include <iostream>

using namespace std;

class Weglowe :
	public SurowcowNaturalnych
{
public:
	Weglowe();
	void wyswietl_informacje();

protected:
	float max_srednica_wegla;

private:

};

