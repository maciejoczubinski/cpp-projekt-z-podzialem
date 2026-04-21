#include <iostream>
#include <vector>
#include "Menu.h"
#include "Napisy.h"
#include "Uzytkownicy.h"

using namespace std;

void uruchomMenu() {
    vector<Uzytkownik> uzytkownicy;
    int wybor;

    do {
        cout << "\n===== MENU GLOWNE =====\n";
        cout << "1. Operacje na napisach\n";
        cout << "2. Uzytkownicy\n";
        cout << "0. Wyjscie\n";
        cout << "Wybierz opcje: ";
        cin >> wybor;

        switch (wybor)
        {
        case 1:
            menuNapisy();
            break;
        case 2:
            menuUzytkownicy(uzytkownicy);
            break;
        case 0:
            cout << "Koniec programu.\n";
            break;
        default:
            cout << "Niepoprawny wybor.\n";
        }
    } while (wybor != 0);
}
