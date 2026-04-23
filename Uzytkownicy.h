#pragma once
#include <string>
#include <vector>

class Uzytkownik {
private:
    std::string imie;
    int wiek;
    std::string haslo;

public:
    Uzytkownik();
    Uzytkownik(const std::string& imie, int wiek, const std::string& haslo);

    std::string getImie() const;
    int getWiek() const;
    std::string getHaslo() const;

    void setImie(const std::string& imie);
    void setWiek(int wiek);
    void setHaslo(const std::string& haslo);
};

void dodajUzytkownika(std::vector<Uzytkownik>& uzytkownicy);
void wyswetlUzytkownikow(const std::vector<Uzytkownik>& uzytkownicy);
void wyszukajUzytkownika(const std::vector<Uzytkownik>& uzytkownicy);
void usunUzytkownika(std::vector<Uzytkownik>& uzytkownicy);
void edytujUzytkownika(std::vector<Uzytkownik>& uzytkownicy);
void menuUzytkownicy(std::vector<Uzytkownik>& uzytkownicy);
void zapiszDoPliku(const std::vector<Uzytkownik>& uzytkownicy);
void wczytajZPliku(std::vector<Uzytkownik>& uzytkownicy);
bool zalogujUzytkownika(const std::vector<Uzytkownik>& uzytkownicy);