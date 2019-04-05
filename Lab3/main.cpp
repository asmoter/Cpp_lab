#include <iostream>
#include "obiekty.h"
using namespace std;

int main() {

    try{
        Pojazd P1;
        Pojazd P2 = Pojazd("Opel", 2000, 5000);
        Pojazd P3 = Pojazd("Skoda", 1000, 6000);
        Pojazd P4 = Pojazd("Toyota", 1500, 5000);
        Pojazd P5 = Pojazd("Fiat", 200, 6500);

        Komis K1;
        Komis K2 = Komis(4);
        Komis K3 = Komis(6);
        Komis K4;

        cout << "Pojazd P1 -> " << P1 << endl;
        cout << "Pojazd P2 -> " << P2 << endl;

        cout << "Licznik K1: " << K1.zwroc_licznik() << endl;
        cout << "Licznik K2: " << K2.zwroc_licznik() << endl;

        K2.dodaj_obiekt(P2);
        K2.dodaj_obiekt(P3);
        K2.dodaj_obiekt(P4);

        cout << "Licznik K2 po dodaniu obiektow: " << K2.zwroc_licznik() << endl;

        K3.operator=(K2);
        cout << "Licznik K3 po skopiowaniu z K2: " << K3.zwroc_licznik() << endl;

        K4=move(K3);
        cout << "Licznik K4 po przeniesieniu K3: " << K4.zwroc_licznik() << endl;
        cout << "Licznik K3 po przeniesieniu K3 do K4: " << K3.zwroc_licznik() << endl;

        Komis K5(K4);
        cout << "Licznik K5 po skopiowaniu K4: " << K5.zwroc_licznik() << endl;
        Komis K6 =move(K4);
        cout << "Licznik K6 po przeniesieniu K4: " << K6.zwroc_licznik() << endl;
        cout << "Licznik K4 po skopiowaniu K4: " << K4.zwroc_licznik() << endl;

        Komis *K7 = new Komis(8);
        delete K7;
    }
    catch(string s){
        cout <<"Wyjatek: " << s << endl;
    }

}