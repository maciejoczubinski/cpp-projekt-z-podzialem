#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <map>
#include <string>
using namespace std;

struct Osoba {
    string imie;
    int wiek;
};

vector<Osoba> osoby = {
    {"Anna", 25},
    {"Zofia", 12},
    {"Tomek", 51},
    {"Kasia", 23},
    {"Marek", 40},
    {"Piotr", 18},
};

void zadanie1() {
    cout << "\n--- ZADANIE 1: Rodzaje petli ---\n";

    cout << "Stara petla:\n";
    for (int i = 0; i < (int)osoby.size(); i++) {
        cout << " " << osoby[i].imie << ", wiek: " << osoby[i].wiek << "\n";
    }

    cout << "Ragnge-based  for:\n";
    for (const auto& o : osoby) {
        cout << " " << o.imie << ", wiek: " << o.wiek << "\n";
    }

    cout << "for_each + lambda:\n";
    for_each(osoby.begin(), osoby.end(), [](const Osoba& o){
        cout << " " << o.imie << ", wiek: " << o.wiek << "\n";
    });
}

void zadanie2() {
    cout << "\n--- ZADANIE 2: find_if ---\n";

    //znajdz pierwsza osobe ponizej 18 lat
    auto it = find_if(osoby.begin(), osoby.end(), [](const Osoba& o) {
        return o.wiek < 18;
    });

    if (it != osoby.end()) {
        cout << "Pierwsza osoba ponizej 18 lat: " << it->imie << " ("<< it->wiek << ")\n";
    } else {
        cout << "Nie znaleziono osoby poniżej 18 lat.\n";
    }

    //Znajdz osobe o konkretnym imieniu
    string szukane = "Kasia";
    auto it2 = find_if(osoby.begin(), osoby.end(), [&szukane](const Osoba& o) {
        return o.imie == szukane;
    });

    if (it != osoby.end()) {
        cout << "Znaleniono: " << it2->imie << ", wiek: " << it2->wiek << "\n";
    }
}

void zadanie3() {
    cout << "\n--- ZADANIE 3: sort + map ---\n";

    //kopia zeby nie zepsuc oryginalnych danych
    vector<Osoba> posortowane = osoby;

    //sortuj po wieku rosnaco
    sort(posortowane.begin(), posortowane.end(), [](const Osoba& a, const Osoba& b) {
        return a.wiek < b.wiek;  //true = a idzie przed b
    });

    cout << "Posortowani po wieku:\n";
    for (const auto& o : posortowane) {
        cout << " " << o.imie << " (" << o.wiek <<")\n";
    }

    //grupuj po wieku uzywajac map<wiek, lista imion>
    map<int, vector<string>> grupy;
    for (const auto& o : osoby) {
        grupy[o.wiek].push_back(o.imie);
    }

    cout << "Zgrupowani po wieku:\n";
    for (const auto& [wiek, imiona] : grupy) {
        cout << " Wiek " << wiek << ": ";
        for (const auto& imie : imiona) cout << imie << " ";
        cout << "\n";
    }
}

void zadanie4() {
    cout << "\n--- ZADANIE 4: transform + count_if ---\n";

    //transform: stworz nowy vector samych imion (wyciagnij z Osoba)
    vector<string> imiona;
    transform(osoby.begin(),osoby.end(), back_inserter(imiona), [](const Osoba& o) {
        return o.imie;
    });

    cout << "Same imiona: ";
    for (const auto& i : imiona) cout << i << " ";
    cout << "\n";

    // count_if: ile osob jest pelnoletnia?
    int pelnoletni = count_if(osoby.begin(), osoby.end(), [](const Osoba& o) {
        return o.wiek >= 18;
    });
    cout << "Pelnoletni: " << pelnoletni << " z " << osoby.size() << "\n";
}

void zadanie5() {
    cout << "\n--- ZADANIE 5: accumulate + min/max ---\n";

    //accumulate: suma wszystkich wiekow
    int sumaWiekow = accumulate(osoby.begin(), osoby.end(), 0, [](int suma, const Osoba& o) {
        return suma + o.wiek;  //dodaj wiek kolejnej osoby do sumy
    });

    double srednia = (double)sumaWiekow / osoby.size();
    cout << "Sredni wiek: " << srednia << "\n";

    //min/max element
    auto najmlodszy = min_element(osoby.begin(), osoby.end(), [](const Osoba& a, const Osoba& b) {
        return a.wiek < b.wiek;
    });

    auto najstarszy = max_element(osoby.begin(), osoby.end(), [](const Osoba& a, const Osoba& b) {
        return a.wiek < b.wiek;
    });

    cout << "Najmlodszy: " << najmlodszy->imie << " (" << najmlodszy->wiek << ")\n";
    cout << "Najstarszy: " << najstarszy->imie << " (" << najstarszy->wiek << ")\n";
}

int main() {
    zadanie1();
    zadanie2();
    zadanie3();
    zadanie4();
    zadanie5(); 
    return 0;
}