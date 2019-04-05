#ifndef CPP_LAB3_OBIEKTY_H
#define CPP_LAB3_OBIEKTY_H
#include <iostream>
#include <utility>
using namespace std;

class Pojazd{
    string marka;
    int przebieg;
    float cena;

public:
    Pojazd(string marka = "b/d", int przebieg = 0, float cena = 0): marka{std::move(marka)}, przebieg{przebieg}, cena{cena}{};
    friend ostream &operator<< (ostream &wyjscie, const Pojazd &p);
};

class Komis{
    int rozmiar;
    int licznik;
    Pojazd *tab;

public:
    Komis(int rozmiar = 10): rozmiar{rozmiar}, licznik{0}, tab{new Pojazd[rozmiar]}{}

    Komis(const Komis &k);
    Komis(Komis &&k);

    Komis &operator=(const Komis &k);
    Komis &operator=(Komis &&k);

    int zwroc_licznik()const {return this->licznik;}

    void dodaj_obiekt(const Pojazd &p);

    ~Komis() {delete[] tab;}

};

#endif
