#include <iostream>
#include <string>
#include <vector>
#include "Elektrownie.h"
#include "Wodne.h"
using namespace std;

void tree();
void menu();
void cd(string *zmienna);
void mo(string f_wezel);
void mdo(string f_wezel);
void show();

vector <Wodne*> o_wodne;

int main()
{
    bool powtorka = true;
    string wybor, wezel = "";

    menu();

    do
    {
        cin >> wybor;
        cin.ignore();
        if (wybor.find("CD") == 0) cd(&wezel);

        else if (wybor.find("MO") == 0) mo(wezel);

        else if (wybor.find("DO") == 0)
        {
            cin >> wezel;
            cout << "Podany obiekt: " << wezel << endl;
        }

        else if (wybor.find("MDO") == 0) mdo(wezel);

        else if (wybor.find("DIR") == 0)
        {
            cout << "Wyswietle informacje wkrotce :) " << endl;
        }

        else if (wybor.find("SHOW") == 0) show();

        else if (wybor.find("SAVE") == 0)
        {
            cout << "Zapis do pliku wkrotce :) " << endl;
        }

        else if (wybor.find("READ") == 0)
        {
            cout << "Odczyt z pliku wkrotce :) " << endl;
        }

        else if (wybor.find("TREE") == 0) tree();

        else if (wybor.find("MENU") == 0)
        {
            menu();
        }

        else if (wybor.find("EXIT") == 0) powtorka = false;

        else cout << "Nie rozpoznano komendy. Sprobuj ponownie!" << endl;

    } while (powtorka);
}

//------------------------------------------------------------------------------

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
    cout << "EXIT - wyjscie z programu" << endl;
    cout << "----------------------------------------------------------------------------------" << endl;
}

void cd(string *zmienna)
{
    getline(cin, *zmienna);
    cout << "Zmieniono wezel na: " << *zmienna << endl;
}

void mo(string f_wezel)
{
    string obiekt;
    getline(cin, obiekt);
    if (f_wezel == "WODNE")
    {
        o_wodne.push_back(new Wodne(obiekt));
    }
    else if (f_wezel == "JADROWE") cout << "konstruktor" << endl;

    else if (f_wezel == "KOPALNIA_ODKRYWKOWA"
        || f_wezel == "KOPALNIA ODKRYWKOWA") cout << "konstruktor" << endl;

    else if (f_wezel == "KOPALNIA_GLEBINOWA"
        || f_wezel == " KOPALNIA GLEBINOWA") cout << "konstruktor" << endl;

    else if (f_wezel == "GAZOWE") cout << "konstruktor" << endl;

    else if (f_wezel == "ROPA") cout << "konstruktor" << endl;

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
        cout << "Podany obiekt nieistnieje dla bie¿¹cego liœcia!" << endl;
    }

    else if (f_wezel == "JADROWE") cout << "mod" << endl;

    else if (f_wezel == "KOPALNIA_ODKRYWKOWA"
        || f_wezel == "KOPALNIA ODKRYWKOWA") cout << "mod" << endl;

    else if (f_wezel == "KOPALNIA_GLEBINOWA"
        || f_wezel == " KOPALNIA GLEBINOWA") cout << "mod" << endl;

    else if (f_wezel == "GAZOWE") cout << "mod" << endl;

    else if (f_wezel == "ROPA") cout << "mod" << endl;

    else cout << "Podano nieistniejacy wezel, lub wezel niebedacy lisciem!" << endl;
}

void show()
{
    string obiekt;
    getline(cin, obiekt);
    for (auto i : o_wodne)
    {
        if (i->nazwa == obiekt)
        {
            i->wyswietl_informacje();
            return;
        }
    }
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