#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include "Uzytkownicy.h"

using namespace std;

void dodajUzytkownika(vector<Uzytkownik> & uzytkownicy) {
    Uzytkownik nowy;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');

    cout << "Podaj imie uzytkownika: ";
    getline(cin, nowy.imie);

    cout << "Podaj wiek uzytkownika: ";
    cin >> nowy.wiek;

    uzytkownicy.push_back(nowy);

    cout << "Uzytkownik zostal dodany.\n";
}

void wyswetlUzytkownikow(const vector<Uzytkownik> & uzytkownicy) {
    if(uzytkownicy.empty()) {
        cout << "Brak uzytkownikow.\n";
        return;
    }

    cout << "\n===== LISTA UZYTKOWNIKOW =====\n";
    for(int i = 0; i < uzytkownicy.size(); i++) {
        cout << i + 1 << ". Imie: " << uzytkownicy[i].imie << ", wiek: " << uzytkownicy[i].wiek << "\n";
    }
}

void menuUzytkownicy() {
    vector<Uzytkownik> uzytkownicy;
    int wybor;

    do {
        cout << "\n===== UZYTKOWNICY =====\n";
        cout << "1. Dodaj uzytkownika\n";
        cout << "2. Wyswietl wszystkich uzytkownikow\n";
        cout << "0. Powrot\n";
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor) {
            case 1:
                dodajUzytkownika(uzytkownicy);
                break;
            case 2:
                wyswetlUzytkownikow(uzytkownicy);
                break;
            case 0:
                cout << "Powrot do menu glownego\n";
                break;
            default:
                cout << "Niepoprawny wybor.\n";
        }
    } while (wybor != 0);
}