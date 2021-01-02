#include "Kamienny.h"
#include "fstream"

Kamienny::Kamienny(string p_nazwa)
	:Weglowe(p_nazwa)
{
	mod_lotne();
}

Kamienny::Kamienny(string p_nazwa, string p_panstwo, float p_moc, string p_stan_skupienia, float p_procent_wegla, float p_lotne)
	: Weglowe(p_nazwa, p_panstwo, p_moc, p_stan_skupienia, p_procent_wegla)
{
	procent_czesci_lotnych = p_lotne;
}

void Kamienny::wyswietl_informacje()
{
	Weglowe::wyswietl_informacje();
	cout << "Zawartosc czesci lotnych [%]: " << procent_czesci_lotnych << endl;
}
void Kamienny::wyswietl_zapis(fstream &plik)
{
	Weglowe::wyswietl_zapis(plik);
	plik << procent_czesci_lotnych << endl;
}

void Kamienny::mod_lotne()
{
	string tmp;
	cout << "Zawartosc czesci lotnych [%]: "; getline(cin, tmp);
	if (tmp != "") procent_czesci_lotnych = stof(tmp);
	return;
}

void Kamienny::modyfikuj()
{
	Weglowe::modyfikuj();
	mod_lotne();
}