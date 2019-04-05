#include <iostream>
#include "obiekty.h"
using namespace std;

//konstruktor kopiowania
Komis::Komis(const Komis &k) {
    this->licznik = k.licznik;
    this->rozmiar = k.rozmiar;
    this->tab = new Pojazd[k.rozmiar];
    copy(k.tab, k.tab + k.licznik, this->tab);
}

//konstruktor przenoszenia
Komis::Komis(Komis &&k) {
    this->licznik = k.licznik;
    this->rozmiar = k.rozmiar;
    this->tab = new Pojazd[k.rozmiar];
    copy(k.tab, k.tab + k.licznik, this->tab);
    k.licznik = 0;
    k.rozmiar = 0;
    k.tab = nullptr;
}

//operator podstawienia
Komis &Komis::operator=(const Komis &k) {
    if(this == &k) return *this;
    delete[] tab;
    this->licznik = k.licznik;
    this->rozmiar = k.rozmiar;
    this->tab = new Pojazd[k.rozmiar];
    copy(k.tab, k.tab + k.licznik, this->tab);
    return *this;
}

//operator przenoszenia
Komis &Komis::operator=(Komis &&k) {
    if(this == &k) return *this;
    this->licznik = k.licznik;
    this->rozmiar = k.rozmiar;
    delete[] tab;
    this->tab = k.tab;
    k.licznik = 0;
    k.rozmiar = 0;
    k.tab = nullptr;
    return *this;
}

void Komis::dodaj_obiekt(const Pojazd &p) {
    if(this->licznik == this->rozmiar){
        string wyjatek = "Tablica jest juz w calosci wypelniona";
        throw (wyjatek);
    }
    this->licznik ++;
    tab[licznik] = p;
}

ostream &operator<<(ostream &wyjscie, const Pojazd &p) {
    return wyjscie << " marka: " << p.marka << "  przebieg: " << p.przebieg << "  cena: " << p.cena << endl;
}
