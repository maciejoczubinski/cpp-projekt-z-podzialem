#include <iostream>
#include <string>
#include <vector>
#include <limits>
#include <fstream>
#include "Uzytkownicy.h"
using namespace std;

// ===== KLASA =====

Uzytkownik::Uzytkownik() : wiek(0) {}

Uzytkownik::Uzytkownik(const string& imie, int wiek, const string& haslo)
    : imie(imie), wiek(wiek), haslo(haslo) {}

string Uzytkownik::getImie() const { return imie; }
int    Uzytkownik::getWiek() const { return wiek; }
string Uzytkownik::getHaslo() const { return haslo; }

void Uzytkownik::setImie(const string& i) {
    if (i.empty()) { cout << "Blad: imie nie moze byc puste.\n"; return; }
    imie = i;
}
void Uzytkownik::setWiek(int w) {
    if (w < 0 || w > 150) { cout << "Blad: niepoprawny wiek.\n"; return; }
    wiek = w;
}
void Uzytkownik::setHaslo(const string& h) {
    if (h.size() < 3) { cout << "Blad: haslo min. 3 znaki.\n"; return; }
    haslo = h;
}

// ===== FUNKCJE =====

void dodajUzytkownika(vector<Uzytkownik>& uzytkownicy) {
    string imie, haslo;
    int wiek;

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Podaj imie: ";
    getline(cin, imie);

    cout << "Podaj wiek: ";
    cin >> wiek;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Niepoprawny wiek.\n";
        return;
    }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    cout << "Podaj haslo (min. 3 znaki): ";
    getline(cin, haslo);

    uzytkownicy.push_back(Uzytkownik(imie, wiek, haslo));
    cout << "Uzytkownik dodany.\n";
}

void wyswetlUzytkownikow(const vector<Uzytkownik>& uzytkownicy) {
    if (uzytkownicy.empty()) { cout << "Brak uzytkownikow.\n"; return; }
    cout << "\n===== LISTA UZYTKOWNIKOW =====\n";
    for (size_t i = 0; i < uzytkownicy.size(); i++) {
        cout << i + 1 << ". " << uzytkownicy[i].getImie()
             << ", wiek: " << uzytkownicy[i].getWiek() << "\n";
    }
}

void wyszukajUzytkownika(const vector<Uzytkownik>& uzytkownicy) {
    if (uzytkownicy.empty()) { cout << "Brak uzytkownikow.\n"; return; }

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string imie;
    cout << "Podaj imie do wyszukania: ";
    getline(cin, imie);

    bool znaleziono = false;
    for (size_t i = 0; i < uzytkownicy.size(); i++) {
        if (uzytkownicy[i].getImie() == imie) {
            cout << i + 1 << ". " << uzytkownicy[i].getImie()
                 << ", wiek: " << uzytkownicy[i].getWiek() << "\n";
            znaleziono = true;
        }
    }
    if (!znaleziono) cout << "Nie znaleziono: " << imie << "\n";
}

void usunUzytkownika(vector<Uzytkownik>& uzytkownicy) {
    if (uzytkownicy.empty()) { cout << "Brak uzytkownikow.\n"; return; }
    wyswetlUzytkownikow(uzytkownicy);
    cout << "Podaj numer do usuniecia: ";
    int numer;
    cin >> numer;
    if (numer < 1 || numer > (int)uzytkownicy.size()) {
        cout << "Niepoprawny numer.\n"; return;
    }
    uzytkownicy.erase(uzytkownicy.begin() + numer - 1);
    cout << "Uzytkownik usuniety.\n";
}

void edytujUzytkownika(vector<Uzytkownik>& uzytkownicy) {
    if (uzytkownicy.empty()) { cout << "Brak uzytkownikow.\n"; return; }
    wyswetlUzytkownikow(uzytkownicy);
    cout << "Podaj numer do edycji: ";
    int numer;
    cin >> numer;
    if (numer < 1 || numer > (int)uzytkownicy.size()) {
        cout << "Niepoprawny numer.\n"; return;
    }

    Uzytkownik* u = &uzytkownicy[numer - 1];   // wskaznik!

    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string noweImie;
    cout << "Nowe imie (obecne: " << u->getImie() << "): ";
    getline(cin, noweImie);
    u->setImie(noweImie);

    cout << "Nowy wiek (obecny: " << u->getWiek() << "): ";
    int nowyWiek;
    cin >> nowyWiek;
    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cout << "Niepoprawny wiek.\n"; return;
    }
    u->setWiek(nowyWiek);

    cout << "Uzytkownik zaktualizowany.\n";
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

void zapiszDoPliku(const vector<Uzytkownik>& uzytkownicy) {
    ofstream plik("uzytkownicy.txt");
    for (const auto& u : uzytkownicy) {
        plik << u.getImie() << "\n" << u.getWiek() << "\n" << u.getHaslo() << "\n";
    }
}

void wczytajZPliku(vector<Uzytkownik>& uzytkownicy) {
    ifstream plik("uzytkownicy.txt");
    if (!plik.is_open()) return;
    uzytkownicy.clear();
    string imie, haslo;
    int wiek;
    while (getline(plik, imie)) {
        plik >> wiek;
        plik.ignore();
        getline(plik, haslo);
        uzytkownicy.push_back(Uzytkownik(imie, wiek, haslo));
    }
}

bool zalogujUzytkownika(const vector<Uzytkownik>& uzytkownicy) {
    if (uzytkownicy.empty()) { cout << "Brak uzytkownikow.\n"; return false; }
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
    string imie, haslo;
    cout << "Podaj imie: ";
    getline(cin, imie);
    cout << "Podaj haslo: ";
    getline(cin, haslo);
    for (const auto& u : uzytkownicy) {
        if (u.getImie() == imie && u.getHaslo() == haslo) {
            cout << "Witaj, " << u.getImie() << "!\n";
            return true;
        }
    }
    cout << "Niepoprawne dane.\n";
    return false;
}