#include <fstream>
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

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Niepoprawny wiek.\n";
        return;
    }

    uzytkownicy.push_back(nowy);
    cout << "Uzytkownik zostal dodany.\n";
    zapiszDoPliku(uzytkownicy);
}

void wyswetlUzytkownikow(const vector<Uzytkownik> & uzytkownicy) {
    if(uzytkownicy.empty()) {
        cout << "Brak uzytkownikow.\n";
        return;
    }

    cout << "\n===== LISTA UZYTKOWNIKOW =====\n";
    for(size_t i = 0; i < uzytkownicy.size(); i++) {
        cout << i + 1 << ". Imie: " << uzytkownicy[i].imie << ", wiek: " << uzytkownicy[i].wiek << "\n";
    }
}

void wyszukajUzytkownika(const vector<Uzytkownik> & uzytkownicy) {
    if(uzytkownicy.empty()) {
        cout << "Brak uzytkownikow\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(),'\n');
    string imie;
    cout << "Podaj imie do wyszukania: ";
    getline(cin, imie);

    bool znaleziono = false;

    for (size_t i = 0; i < uzytkownicy.size(); i++) {
        if (uzytkownicy[i].imie == imie) {
            cout << i + 1 << ". Imie: " << uzytkownicy[i].imie << " Wiek: " << uzytkownicy[i].wiek << "\n";
            znaleziono = true;
        }
    }

    if (!znaleziono) {
        cout << "Nie znaleziono uzytkownika o imieniu: " << imie << "\n";
    }
}

void usunUzytkownika(vector<Uzytkownik>& uzytkownicy) {
    if (uzytkownicy.empty()) {
        cout << "Brak uzytkownikow.\n";
        return;
    }

    wyswetlUzytkownikow(uzytkownicy);

    cout << "Podaj uzytkownika do usuniecia: ";
    int numer;
    cin >> numer;

    if (numer <1 || numer > (int)uzytkownicy.size()) {
        cout << "Niepoprawny numer.\n";
        return;
    }

    uzytkownicy.erase(uzytkownicy.begin() + numer - 1);
    cout << "Uzytkownik zostal usuniety.\n";
}

void edytujUzytkownika(vector<Uzytkownik>& uzytkownicy) {
    if (uzytkownicy.empty()) {
        cout << "Brak uzytkownikow.\n";
        return;
    }

    wyswetlUzytkownikow(uzytkownicy);

    cout << "Podaj numer uzytkownika do edycji: ";
    int numer;
    cin >> numer;

    if (numer < 1 || numer > (int)uzytkownicy.size()) {
        cout << "Niepoprawny numer.\n";
        return;
    }

    Uzytkownik& u = uzytkownicy[numer -1]; // referencja do elementu w wektorze

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Nowe imie (obecne: " << u.imie << "): ";
    getline(cin, u.imie);

    cout << "Nowy wiek(obecny: " << u.wiek << "): ";
    cin >> u.wiek;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Niepoprawny wiek - edycja anulowana.\n";
        return;
    }

    cout << "Uzytkownik zostal zaktualizowany.\n";
}

void zapiszDoPliku(const std::vector<Uzytkownik>& uzytkownicy) {
    std::ofstream plik("uzytkownicy.txt");

    if(!plik.is_open()) {
        std::cout << "Blad otwarcia pliku do zapisu!\n";
        return;
    }

    for(const auto& u : uzytkownicy) {
        plik << u.imie << " " << u.wiek << std::endl;
    }
    plik.close();
}

void wczytajZPliku(std::vector<Uzytkownik>& uzytkownicy){
    std::ifstream plik("uzytkownicy.txt");

    if(!plik.is_open()) {
        std::cout << "Brak pliku.\n";
        return;
    }

    Uzytkownik u;

    while (plik >> u.imie >> u.wiek) {
        uzytkownicy.push_back(u);
    }
    plik.close();
}

void menuUzytkownicy(vector<Uzytkownik>& uzytkownicy) {
    int wybor;

    do {
        cout << "\n===== UZYTKOWNICY =====\n";
        cout << "1. Dodaj uzytkownika\n";
        cout << "2. Wyswietl wszystkich uzytkownikow\n";
        cout << "3. Wyszukaj uzytkownika\n";
        cout << "4. Edytuj uzytkownika\n";
        cout << "5. Usun uzytkownika\n";
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
            case 3:
                wyszukajUzytkownika(uzytkownicy);
                break;
            case 4:
                edytujUzytkownika(uzytkownicy);
                break;
            case 5:
                usunUzytkownika(uzytkownicy);
                break;
            case 0:
                cout << "Powrot do menu glownego\n";
                break;
            default:
                cout << "Niepoprawny wybor.\n";
        }
    } while (wybor != 0);
}