#include <iostream>
#include <vector>
#include "Menu.h"

using namespace std;

int main() {
    vector<Uzytkownik> uzytkownicy;

    wczytajZPliku(uzytkownicy);

    uruchomMenu(uzytkownicy);
    zapiszDoPliku(uzytkownicy);
    return 0;
}