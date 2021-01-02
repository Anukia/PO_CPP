#include <iostream>
#include <string>
#include <vector>
#include <fstream>

#include "generyczna.cpp"
#include "Elektrownie.h"
#include "Wodne.h"
#include "Jadrowe.h"
#include "SurowcowNaturalnych.h"
#include "Weglowe.h"
#include "Gazowe.h"
#include "Ropa.h"
#include "Brunatny.h"
#include "Kamienny.h"
#include "KopalniaOdkrywkowa.h"
#include "KopalniaGlebinowa.h"

using namespace std;

string upper(string napis);
void tree();
void menu();
void cd(string *zmienna);
void mo(string f_wezel);
void f_do(string f_wezel);
void mdo(string f_wezel);
void show(string f_wezel);
void dir(string f_wezel);
void dir_wodne();
void dir_jadrowe();
void dir_odkrywkowa();
void dir_glebinowa();
void dir_gazowe();
void dir_ropa();
void save();
void read();

vector <Wodne*> o_wodne;
vector <Jadrowe*> o_jadrowe;
vector <KopalniaGlebinowa*> o_glebinowa;
vector <KopalniaOdkrywkowa*> o_odkrywkowa;
vector <Gazowe*> o_gazowe;
vector <Ropa*> o_ropa;

int main()
{
    bool powtorka = true;
    string wybor, wezel = "";

    menu();

    do
    {
        cin >> wybor;
        cin.ignore();
        wybor = upper(wybor);
        if (wybor.find("CD") == 0) cd(&wezel);

        else if (wybor.find("MO") == 0) mo(wezel);

        else if (wybor.find("DO") == 0) f_do(wezel);

        else if (wybor.find("MDO") == 0) mdo(wezel);

        else if (wybor.find("DIR") == 0) dir(wezel);

        else if (wybor.find("SHOW") == 0) show(wezel);

        else if (wybor.find("SAVE") == 0) save();

        else if (wybor.find("READ") == 0) read();

        else if (wybor.find("TREE") == 0) tree();

        else if (wybor.find("MENU") == 0) menu();

        else if (wybor.find("EXIT") == 0) powtorka = false;

        else cout << "Nie rozpoznano komendy. Sprobuj ponownie!" << endl;

    } while (powtorka);
}

//---------------------------------------------------------------------------------------

string upper(string napis)
{
    string wynik;
    for (int i = 0; i < napis.length(); i++)
    {
        if (napis[i] >= 'a' && napis[i] <= 'z') wynik += napis[i] - 32;
        else wynik += napis[i];
    }
    return wynik;
}

void menu()
{
    cout << "\t\tMENU" << endl;;
    cout << "CD [nazwa wezla] - zmiana wezla w strukturze" << endl;
    cout << "MO [obiekt] - tworzy obiekt podany jako parametr dla biazacego liscia" << endl;
    cout << "DO [obiekt] - usuwa obiekt podany jako parametr dla biezacego liscia" << endl;
    cout << "MDO [obiekt] - modyfikacja obiektu podanego jako parametr dla biezacego liscia" << endl;
    cout << "DIR - wyswietla informacje o nazwach obiektow widocznych z danego poziomu" << endl;
    cout << "SHOW [obiekt] - wyswietla szczegolowe informacje o obiekcie" << endl;
    cout << "SAVE - zapis zbioru do pliku" << endl;
    cout << "READ - odczyt zbioru z pliku" << endl;
    cout << "MENU - wyswietla MENU" << endl;
    cout << "TREE - wyswietla cala strukture" << endl;
    cout << "EXIT - wyjscie z programu" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
}

void cd(string *zmienna)
{
    getline(cin, *zmienna);
    *zmienna = upper(*zmienna);
    cout << "Zmieniono wezel na: " << *zmienna << endl;
}

void mo(string f_wezel)
{
    string obiekt;
    getline(cin, obiekt);
    if (f_wezel == "WODNE") o_wodne.push_back(new Wodne(obiekt));
    else if (f_wezel == "JADROWE") o_jadrowe.push_back(new Jadrowe(obiekt));

    else if (f_wezel == "KOPALNIA_ODKRYWKOWA"
        || f_wezel == "KOPALNIA ODKRYWKOWA") o_odkrywkowa.push_back(new KopalniaOdkrywkowa(obiekt));

    else if (f_wezel == "KOPALNIA_GLEBINOWA"
        || f_wezel == "KOPALNIA GLEBINOWA") o_glebinowa.push_back(new KopalniaGlebinowa(obiekt));

    else if (f_wezel == "GAZOWE") o_gazowe.push_back(new Gazowe(obiekt));

    else if (f_wezel == "ROPA") o_ropa.push_back(new Ropa(obiekt));

    else cout << "Podano nieistniejacy wezel, lub wezel niebedacy lisciem!" << endl;
}

void f_do(string f_wezel)
{
    string obiekt;
    getline(cin, obiekt);
    if (f_wezel == "WODNE")
    {
        for (int i = 0; i < o_wodne.size(); i++)
        {
            if (o_wodne[i]->nazwa == obiekt)
            {
                o_wodne.erase(o_wodne.begin() + i);
                cout << "Obiekt usunieto!" << endl;
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else if (f_wezel == "JADROWE")
    {
        for (int i = 0; i < o_jadrowe.size(); i++)
        {
            if (o_jadrowe[i]->nazwa == obiekt)
            {
                o_jadrowe.erase(o_jadrowe.begin() + i);
                cout << "Obiekt usunieto!" << endl;
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else if (f_wezel == "KOPALNIA_ODKRYWKOWA"
        || f_wezel == "KOPALNIA ODKRYWKOWA")
    {
        for (int i = 0; i < o_jadrowe.size(); i++)
        {
            if (o_jadrowe[i]->nazwa == obiekt)
            {
                o_jadrowe.erase(o_jadrowe.begin() + i);
                cout << "Obiekt usunieto!" << endl;
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else if (f_wezel == "KOPALNIA_GLEBINOWA"
        || f_wezel == "KOPALNIA GLEBINOWA")
    {
        for (int i = 0; i < o_glebinowa.size(); i++)
        {
            if (o_glebinowa[i]->Kamienny::nazwa == obiekt)
            {
                o_glebinowa.erase(o_glebinowa.begin() + i);
                cout << "Obiekt usunieto!" << endl;
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else if (f_wezel == "GAZOWE")
    {
        for (int i = 0; i < o_gazowe.size(); i++)
        {
            if (o_gazowe[i]->nazwa == obiekt)
            {
                o_gazowe.erase(o_gazowe.begin() + i);
                cout << "Obiekt usunieto!" << endl;
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else if (f_wezel == "ROPA")
    {
        for (int i = 0; i < o_ropa.size(); i++)
        {
            if (o_ropa[i]->nazwa == obiekt)
            {
                o_ropa.erase(o_ropa.begin() + i);
                cout << "Obiekt usunieto!" << endl;
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else cout << "Podano nieistniejacy wezel, lub wezel niebedacy lisciem!" << endl;
}

void mdo(string f_wezel)
{
    string obiekt;
    getline(cin, obiekt);
    if (f_wezel == "WODNE")
    {
        for (auto i : o_wodne)
        {
            if (i->nazwa == obiekt)
            {
                i->modyfikuj();
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else if (f_wezel == "JADROWE")
    {
        for (auto i : o_jadrowe)
        {
            if (i->nazwa == obiekt)
            {
                i->modyfikuj();
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else if (f_wezel == "KOPALNIA_ODKRYWKOWA"
        || f_wezel == "KOPALNIA ODKRYWKOWA")
    {
        for (auto i : o_odkrywkowa)
        {
            if (i->nazwa == obiekt)
            {
                i->modyfikuj();
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else if (f_wezel == "KOPALNIA_GLEBINOWA"
        || f_wezel == "KOPALNIA GLEBINOWA")
    {
        for (auto i : o_glebinowa)
        {
            if (i->Kamienny::nazwa == obiekt)
            {
                i->modyfikuj();
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else if (f_wezel == "GAZOWE")
    {
        for (auto i : o_gazowe)
        {
            if (i->nazwa == obiekt)
            {
                i->modyfikuj();
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else if (f_wezel == "ROPA")
    {
        for (auto i : o_ropa)
        {
            if (i->nazwa == obiekt)
            {
                i->modyfikuj();
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else cout << "Podano nieistniejacy wezel, lub wezel niebedacy lisciem!" << endl;
}

void dir_wodne()
{
    cout << "WODNE:" << endl;
    for (auto i : o_wodne) cout << i->nazwa << endl;
}

void dir_jadrowe()
{
    cout << "JADROWE:" << endl;
    for (auto i : o_jadrowe) cout << i->nazwa << endl;
}

void dir_odkrywkowa()
{
    cout << "KOPALNIA ODKRYWKOWA:" << endl;
    for (auto i : o_odkrywkowa) cout << i->nazwa << endl;
}

void dir_glebinowa()
{
    cout << "KOPALNIA GLEBINOWA:" << endl;
    for (auto i : o_glebinowa) cout << i->Kamienny::nazwa << endl;
}

void dir_gazowe()
{
    cout << "GAZOWE:" << endl;
    for (auto i : o_gazowe) cout << i->nazwa << endl;
}

void dir_ropa()
{
    cout << "ROPA:" << endl;
    for (auto i : o_ropa) cout << i->nazwa << endl;
}

void dir(string f_wezel)
{
    if (f_wezel == "WODNE") dir_wodne();

    else if (f_wezel == "JADROWE") dir_jadrowe();

    else if (f_wezel == "KOPALNIA_ODKRYWKOWA"
        || f_wezel == "KOPALNIA ODKRYWKOWA") dir_odkrywkowa();

    else if (f_wezel == "KOPALNIA_GLEBINOWA"
        || f_wezel == "KOPALNIA GLEBINOWA") dir_glebinowa();

    else if (f_wezel == "GAZOWE") dir_gazowe();

    else if (f_wezel == "ROPA") dir_ropa();

    else if (f_wezel == "BRUNATNY")
    {
        dir_odkrywkowa();
        dir_glebinowa();
    }

    else if (f_wezel == "KAMIENNY") dir_glebinowa();

    else if (f_wezel == "WEGLOWE")
    {
        dir_odkrywkowa();
        dir_glebinowa();
    }

    else if (f_wezel == "SUROWCOW_NATURALNYCH"
        || f_wezel == "SUROWCOW NATURALNYCH")
    {
        dir_odkrywkowa();
        dir_glebinowa();
        dir_gazowe();
        dir_ropa();
    }

    else if (f_wezel == "ELEKTROWNIE")
    {
        dir_wodne();
        dir_jadrowe();
        dir_odkrywkowa();
        dir_glebinowa();
        dir_gazowe();
        dir_ropa();
    }

    else cout << "Podano nieistniejacy wezel!" << endl;
}

void show(string f_wezel)
{
    string obiekt;
    getline(cin, obiekt);
    if (f_wezel == "WODNE")
    {
        for (auto i : o_wodne)
        {
            if (i->nazwa == obiekt)
            {
                *i + *i;
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else if (f_wezel == "JADROWE")
    {
        for (auto i : o_jadrowe)
        {
            if (i->nazwa == obiekt)
            {
                i->wyswietl_informacje();
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else if (f_wezel == "KOPALNIA_ODKRYWKOWA"
        || f_wezel == "KOPALNIA ODKRYWKOWA")
    {
        for (auto i : o_odkrywkowa)
        {
            if (i->nazwa == obiekt)
            {
                i->wyswietl_informacje();
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else if (f_wezel == "KOPALNIA_GLEBINOWA"
        || f_wezel == "KOPALNIA GLEBINOWA")
    {
        for (auto i : o_glebinowa)
        {
            if (i->Kamienny::nazwa == obiekt)
            {
                i->wyswietl_informacje();
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else if (f_wezel == "GAZOWE")
    {
        for (auto i : o_gazowe)
        {
            if (i->nazwa == obiekt)
            {
                i->wyswietl_informacje();
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else if (f_wezel == "ROPA")
    {
        for (auto i : o_ropa)
        {
            if (i->nazwa == obiekt)
            {
                i->wyswietl_informacje();
                return;
            }
        }
        cout << "Podany obiekt nieistnieje dla biezacego liscia!" << endl;
    }

    else cout << "Podano nieistniejacy wezel, lub wezel niebedacy lisciem!" << endl;
}

void save()
{
    string nazwa_pliku;
    cout << "Podaj nazwe pliku: "; 
    cin >> nazwa_pliku;
    cin.ignore();
    cout << endl;

    fstream plik;
    plik.open(nazwa_pliku);
    if (!plik.is_open())
    {
        cout << "Nie mozna otworzyc pliku!" << endl;
        return;
    }

    string nazwa_klasy = "WODNE";
    Plik<Wodne> tab1(o_wodne);
    tab1.zapis(nazwa_klasy, plik);
    nazwa_klasy = "JADROWE";
    Plik<Jadrowe> tab2(o_jadrowe);
    tab2.zapis(nazwa_klasy, plik);
    nazwa_klasy = "KOPALNIA_ODKRYWKOWA";
    Plik<KopalniaOdkrywkowa> tab3(o_odkrywkowa);
    tab3.zapis(nazwa_klasy, plik);
    nazwa_klasy = "KOPALNIA_GLEBINOWA";
    Plik<KopalniaGlebinowa> tab4(o_glebinowa);
    tab4.zapis(nazwa_klasy, plik);
    nazwa_klasy = "GAZOWE";
    Plik<Gazowe> tab5(o_gazowe);
    tab5.zapis(nazwa_klasy, plik);
    nazwa_klasy = "ROPA";
    Plik<Ropa> tab6(o_ropa);
    tab6.zapis(nazwa_klasy, plik);

    plik.close();
    cout << "Plik zapisano!" << endl;
}

void read()
{
    string nazwa_pliku;
    cout << "Podaj nazwe pliku: " << endl;
    cin >> nazwa_pliku;
    cin.ignore();
    cout << endl;

    fstream plik;
    plik.open(nazwa_pliku);
    if (!plik.is_open())
    {
        cout << "Nie mozna otworzyc pliku!" << endl;
        return;
    }

    string linia, linia_duze;
    string tmp1, tmp2, tmp3, tmp4, tmp5, tmp6, tmp7, tmp8;
    do
    {
        getline(plik, linia);
        linia_duze = upper(linia);

        if (linia_duze.find("WODNE") == 0)
        {
            getline(plik, tmp1);
            getline(plik, tmp2);
            getline(plik, tmp3);
            getline(plik, tmp4);
            getline(plik, tmp5);
            o_wodne.push_back(new Wodne(tmp1, tmp2, stof(tmp3), tmp4, tmp5));
        }

        else if (linia_duze.find("JADROWE") == 0)
        {
            getline(plik, tmp1);
            getline(plik, tmp2);
            getline(plik, tmp3);
            getline(plik, tmp4);
            getline(plik, tmp5);
            o_jadrowe.push_back(new Jadrowe(tmp1, tmp2, stof(tmp3), stoi(tmp4), tmp5));
        }

        else if (linia_duze.find("KOPALNIA_ODKRYWKOWA") == 0
            || linia_duze.find("KOPALNIA ODKRYWKOWA") == 0)
        {
            getline(plik, tmp1);
            getline(plik, tmp2);
            getline(plik, tmp3);
            getline(plik, tmp4);
            getline(plik, tmp5);
            getline(plik, tmp6);
            getline(plik, tmp7);
            o_odkrywkowa.push_back(new KopalniaOdkrywkowa(tmp1, tmp2, stof(tmp3), tmp4, stof(tmp5), stof(tmp6), stof(tmp7)));
        }

        else if (linia_duze.find("KOPALNIA_GLEBINOWA") == 0
            || linia_duze.find("KOPALNIA GLEBINOWA") == 0)
        {
            getline(plik, tmp1);
            getline(plik, tmp2);
            getline(plik, tmp3);
            getline(plik, tmp4);
            getline(plik, tmp5);
            getline(plik, tmp6);
            getline(plik, tmp7);
            getline(plik, tmp8);
            o_glebinowa.push_back(new KopalniaGlebinowa(tmp1, tmp2, stof(tmp3), tmp4, stof(tmp5), stof(tmp6), stof(tmp7), stof(tmp8)));
        }

        else if (linia_duze.find("GAZOWE") == 0)
        {
            getline(plik, tmp1);
            getline(plik, tmp2);
            getline(plik, tmp3);
            getline(plik, tmp4);
            getline(plik, tmp5);
            o_gazowe.push_back(new Gazowe(tmp1, tmp2, stof(tmp3), tmp4, stof(tmp5)));
        }

        else if (linia_duze.find("ROPA") == 0)
        {
            getline(plik, tmp1);
            getline(plik, tmp2);
            getline(plik, tmp3);
            getline(plik, tmp4);
            getline(plik, tmp5);
            o_ropa.push_back(new Ropa(tmp1, tmp2, stof(tmp3), tmp4, stof(tmp5)));
        }

        else if (linia_duze == "");

        else cout << "Blad w pliku (nie wiem co to za wezel)." << endl;

    } while (!plik.eof());

    plik.close();
    cout << "Plik wczytano!" << endl;
}

void tree()
{
    cout << "Elektrownie" << endl;
    cout << "\t Wodne" << endl;
    cout << "\t Jadrowe" << endl;
    cout << "\t Surowcow Naturalnych" << endl;
    cout << "\t\t Weglowe" << endl;
    cout << "\t\t\t Brunatny" << endl;
    cout << "\t\t\t\t Kopalnia odkrywkowa" << endl;
    cout << "\t\t\t\t Kopalnia glebinowa" << endl;
    cout << "\t\t\t Kamienny" << endl;
    cout << "\t\t\t\t Kopalnia glebinowa" << endl;
    cout << "\t\t Gazowe" << endl;
    cout << "\t\t Ropa" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
}