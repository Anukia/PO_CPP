#pragma once
#include "Kamienny.h"
#include "Brunatny.h"
#include <iostream>

using namespace std;


class KopalniaGlebinowa :
	public Kamienny,  Brunatny
{
public:
	KopalniaGlebinowa();
	void wyswietl_informacje();

protected:
	float glebokosc;

private:

};

