#ifndef CPP_LABY2_OBIEKTY_H
#define CPP_LABY2_OBIEKTY_H
#include <iostream>
using namespace std;

class Wektor;

class Macierz{

    float mxx, mxy, myx, myy;

public:
    Macierz(): mxx{0}, mxy{0}, myx{0}, myy{0}{};
    Macierz(float mxx, float mxy, float myx, float myy): mxx{mxx}, mxy{mxy}, myx{myx}, myy{myy}{};

    friend ostream &operator<< (ostream &wyjscie, const Macierz &m);

    friend Macierz operator* (const Macierz &m, const float &f);
    friend Macierz operator* (const float &f, const Macierz &m);

    Macierz operator- ();

    friend class Wektor;

};

class Wektor{

    float x, y;

public:
    Wektor(): x{0}, y{0}{};
    Wektor(float x, float y): x{x}, y{y}{};

    friend ostream &operator<< (ostream &wyjscie, const Wektor &w);

    Wektor operator-= (const Wektor &w);
    Wektor operator- (const Wektor &w) const;
    Wektor operator* (const Macierz &m);
    Wektor &operator++ ();
    const Wektor operator++ (int);
    bool operator== (const Wektor &w);
    float operator[] (int);
    friend class Macierz;
};

ostream &operator<< (ostream &wyjscie, const Macierz &m);
ostream &operator<< (ostream &wyjscie, const Wektor &w);
Macierz operator* (const Macierz &m, const float &f);
Macierz operator* (const float &f, const Macierz &m);

#endif














