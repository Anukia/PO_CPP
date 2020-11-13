#pragma once
#include "Brunatny.h"
#include <iostream>

using namespace std;

class KopalniaOdkrywkowa :
	public Brunatny
{
public:
	KopalniaOdkrywkowa();
	void wyswietl_informacje();

protected:
	float powierzchnia;

private:

};

