#include <iostream>
using namespace std;
#include "obiekty.h"


ostream &operator<< (ostream &wyjscie, const Macierz &m){
    return wyjscie << "mxx = " << m.mxx << " mxy = " << m.mxy << " myx = " << m.myx << " myy = " << m.myy << endl;
}

ostream &operator<< (ostream &wyjscie, const Wektor &w){
    return wyjscie << "x = " << w.x << " y = " << w.y << endl;
}

Wektor Wektor::operator-=(const Wektor &w) {
    this->x -= w.x;
    this->y -= w.y;
    return *this;
}

Wektor Wektor::operator-(const Wektor &w)const{
    return {this->x - w.x, this->y - w.y};
}

Wektor Wektor::operator*(const Macierz &m) {
    return {this->x * m.mxx + this->y * m.myx, this->x * m.mxy + this->y * m.myy};
}

Macierz operator* (const Macierz &m, const float &f){
    return {m.mxx * f, m.mxy * f, m.myx * f, m.myy * f};
}

Macierz operator* (const float &f, const Macierz &m){
    return {m.mxx * f, m.mxy * f, m.myx * f, m.myy * f};
}

Wektor& Wektor::operator++() { // ++w
    (this->x)++;
    (this->y)++;
    return *this;
}

const Wektor Wektor::operator++(int) { //w++
    Wektor *tmp = this;
    (this->x)++;
    (this->y)++;
    return *tmp;
}

Macierz Macierz::operator-(){
    return {-this->mxx, -this->mxy, -this->myx, -this->myy};
}

bool Wektor::operator==(const Wektor &w) {
    return !(this->x != w.x || this->y != w.y);
}

float Wektor::operator[](int i) {
    if(i == 1) return this->x;
    else return this->y;
}






