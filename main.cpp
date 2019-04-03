#include <iostream>
#include <cmath>
#include <iomanip>

using namespace std;

class Punkt{

    double x, y, z;
    static int licznik;

public:
    Punkt(): x{0}, y{0}, z{0} {licznik++;}

    Punkt(double x, double y = 0, double z = 0): x{x}, y{y}, z{z}{licznik++;}

    double zwroc_z(){
        return z;
    }
    void zmien_z(double n){
        z = n;
    }
    double odleglosc (Punkt P);

    void wypisz(){
        cout << "x = " << x << ", " << "y = " << y << ", " << "z = " << z << endl;
    }
    static void zeruj_licznik(){
        licznik = 0;
    }
    static int zwroc_licznik(){
        return licznik;
    }
    void zapisz(ostream& os);
    void wczytaj(istream& is);
};

int Punkt::licznik(0);

double Punkt::odleglosc(Punkt P) {
    double d = sqrt((P.x - x)*(P.x - x) + (P.y - y)*(P.y - y) + (P.z - z)*(P.z - z));
    return d;
}

double zaokr(double n, int p) {
    return round(n * pow(10, p)) / pow(10, p);
}

void Punkt::zapisz(ostream &os) {
    os << "[" << zaokr(x,3) << "; " << zaokr(y,3) << "; " << zaokr(z,3) << "]";
}

void Punkt::wczytaj(istream &is) {
    char c;
    is >> c >> x >> c >> y >> c >> x >> c;
}

int main() {

    Punkt P1{};
    Punkt P2{1.0, 3.2, 9.4};
    Punkt P3{3.2, 2.4};
    Punkt P4{2.9};
    Punkt P5{5.6, 8.3, 2.3};
    Punkt P6{2.1, 5.9, 3.2};
    Punkt P7{};

    cout << "Wartosc licznika: " << P7.zwroc_licznik();
    P7.zeruj_licznik();
    cout << endl << "Wartosc licznika po wyzerowaniu: " << P7.zwroc_licznik();

    cout << endl << "Wspolrzedna z pkt P1: " << P1.zwroc_z();
    cout << endl << "Wspolrzedna z pkt P2: " << P2.zwroc_z();
    P2.zmien_z(5.3);
    cout << endl << "Wsplrzedna z pkt P2 po zmianie na 5.3: " << P2.zwroc_z();
    cout << endl << "Odleglosc miedzy pkt P3 i P4: " << P3.odleglosc(P4);

    cout << endl << "Wspolrzedne pkt P5: ";
    P5.wypisz();

    cout << "Punkt 6 wczytany za pomoca funkcji zapisz: ";
    P6.zapisz(cout);
    cout << endl << "Podaj wspolrzedne dla punktu P7: ";
    P7.wczytaj(cin);
    cout << endl << "Punkt P7 wczytany za pomoca funkcji wczytaj: ";
    P7.wypisz();


    return 0;
}