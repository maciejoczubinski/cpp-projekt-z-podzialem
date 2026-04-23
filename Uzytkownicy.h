#ifndef UZYTKOWNICY_H
#define UZYTKOWNICY_H

#include <string>
#include <vector>

struct Uzytkownik {
    std::string imie;
    int wiek;
    std::string haslo;
};

void dodajUzytkownika(std::vector<Uzytkownik> & uzytkownicy);
void wyswietlUzytkownikow(const std::vector<Uzytkownik> & uzytkownicy);
void wyszukajUzytkownika(const std::vector<Uzytkownik> & uzytkownicy);
void usunUzytkownika(std::vector<Uzytkownik> & uzytkownicy);
void edytujUzytkownika(std::vector<Uzytkownik> & uzytkownicy);
void menuUzytkownicy(std::vector<Uzytkownik>& uzytkownicy);
void zapiszDoPliku(const std::vector<Uzytkownik>& uzytkownicy);
void wczytajZPliku(std::vector<Uzytkownik>& uzytkownicy);
bool zalogujUzytkownika(const std::vector<Uzytkownik>& uzytkownicy);

#endif