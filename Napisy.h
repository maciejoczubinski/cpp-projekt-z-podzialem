#ifndef NAPISY_H
#define NAPISY_H

#include <string>

void menuNapisy();

int policzDlugoscNapisu(const std::string & tekst);
std::string naDuzeLitery(std::string tekst);
std::string naMaleLitery(std::string tekst);
int policzSamogloski(const std::string & tekst);
std::string odwrocNapis(const std::string & tekst);
bool czyPalindrom(const std:: string & tekst);

int policzSpacje(const std::string & tekst);
bool czyZawieraSlowo(const std::string & tekst, const std::string & szukane);
std::string usunCyfry(const std::string & tekst);
#endif