#pragma once
#include <iostream>

using namespace std;

class Elektrownie
{
public:
	string nazwa;

	Elektrownie(string p_nazwa);
	Elektrownie(string p_nazwa, string p_panstwo, float p_moc);
	void wyswietl_informacje();
	void modyfikuj();

protected:
	string panstwo;
	float moc;

	void mod_panstwo();
	void mod_moc();

private:

};

