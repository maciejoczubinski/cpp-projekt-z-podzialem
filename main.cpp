#include <iostream>
#include <vector>
#include "Menu.h"

using namespace std;

int main() {
    vector<Uzytkownik> uzytkownicy;

    wczytajZPliku(uzytkownicy);

    uruchomMenu(uzytkownicy);
    return 0;
}