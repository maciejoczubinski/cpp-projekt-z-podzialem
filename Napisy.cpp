#include <iostream>
#include <string>
#include "Napisy.h"

using namespace std;

int policzDlugoscNapisu(const string & tekst) {
    return tekst.length();
}

string naDuzeLitery(string tekst) {
    for (int i = 0; i < tekst.length(); i++) {
        tekst[i] = toupper(tekst[i]);
    }
    return tekst;
}

string naMaleLitery(string tekst) {
    for (int i = 0; i < tekst.length(); i++) {
        tekst[i] = tolower(tekst[i]);
    }
    return tekst;
}

int policzSamogloski(const string & tekst) {
    int licznik = 0;
    for (int i = 0; i < tekst.length(); i++) {
        char c = tolower(tekst[i]);
        if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u' || c == 'y') {
            licznik++;
        }
    }
    return licznik;
}

string odwrocNapis(const string & tekst) {
    string wynik = tekst;
    int n = wynik.length();

    for (int i = 0; i < n /2; i++) {
        char temp = wynik[i];
        wynik[i] = wynik[n - 1 - i];
        wynik[n - 1 - i] = temp;
    }
    return wynik;
}

bool czyPalindrom(const string & tekst) {
    string odwrocony = odwrocNapis(tekst);
    return tekst == odwrocony;
}

int policzSpacje(const string & tekst) {
    int licznik = 0;
    for (int i = 0; i < tekst.length(); i++) {
        if (tekst[i] == ' ') {
            licznik++;
        }
    }
    return licznik;
}

bool czyZawieraSlowo(const string & tekst, const string & szukane) {
    return tekst.find(szukane) != string::npos;
}

string usunCyfry(const string & tekst) {
    string wynik = "";

    for (int i = 0; i < tekst.length(); i++) {
        if (!isdigit(tekst[i])) {
            wynik += tekst[i];
        }
    }
    return wynik;
}

void menuNapisy() {
    cin.ignore();

    string tekst;
    int wybor;

    cout << "Podaj tekst: ";
    getline(cin, tekst);

    do {
        cout << "\n===== OPERACJE NA NAPISACH =====\n";
        cout << "1. Dlugosc napisu\n";
        cout << "2. Na duze litery\n";
        cout << "3. Na male litery\n";
        cout << "4. Liczba samoglosek\n";
        cout << "5. Odwroc napis\n";
        cout << "6. Sprawdz palindrom\n";
        cout << "7. Policz spacje\n";
        cout << "8. Sprawdz, czy zawiera slowo\n";
        cout << "9. Usun cyfry z napisu\n";
        cout << "0. Powrot\n";
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            cout << "Dlugosc: " << policzDlugoscNapisu(tekst) << "\n";
            break;
        case 2:
            cout << naDuzeLitery(tekst) << "\n";
            break;
        case 3:
            cout << naMaleLitery(tekst) << "\n";
            break;
        case 4:
            cout << "Samogloski: " << policzSamogloski(tekst) << "\n";
            break;
        case 5:
            cout << odwrocNapis(tekst) << "\n";
            break;
        case 6:
            if(czyPalindrom(tekst)) {
                cout << "To jest palindrom.\n";
            }else {
                cout << "To nie jest palindrom.\n";
            }
            break;
        case 7:
            cout << "Liczba spacji: " << policzSpacje(tekst) << "\n";
            break;
        case 8: {  //nie mozna deklarowac zmiennej w case bez dodatkowych {}
            cin.ignore();
            string szukane;
            cout << "Podaj slowo do wyszukania: ";
            getline(cin, szukane);

            if(czyZawieraSlowo(tekst, szukane)) {
                cout << "Tekst zawiera szukane slowo.\n";
            } else {
                cout << "Tekst nie zawiera szukanego slowa.\n";
            }
            break;
        }
        case 9:
            cout << usunCyfry(tekst) << "\n";
            break;
        case 0:
            cout << "Powrot do menu glownego.\n";
            break;
        default:
            cout << "Niepoprawny wybor.\n";
        }
    } while (wybor !=0);
}