#include <iostream>
using namespace std;
#include "obiekty.h"

int main() {

    Wektor W1 = Wektor();
    Wektor W2 = Wektor(3.2, 8.3);
    Wektor W3 = Wektor(2.98, 5.62);

    Macierz M1 = Macierz();
    Macierz M2 = Macierz(3.2, 7.1, 9.0, 8.65);
    Macierz M3 = Macierz(2.5, 7.4, 1.8, 9.4);

    cout << "W1: " << W1;
    cout << "W2: " << W2;
    cout << "M1: " << M1;
    cout << "M2: " << M2;

    Wektor W4 = W2-W3;
    cout << "W4: " << W4;

    Macierz M4 = M3 * 2;
    cout << "M4: " << M4;

    Wektor W5 = W3*M2;
    cout << "W5: " << W5;

    Wektor W6 = W5++;
    Wektor W7 = ++W6;

    cout << "W6 = W5++: " << W6;
    cout << "W7 = ++W6: " << W7;

    Macierz M5 = -M4;
    cout << "M5: " << M5;

    bool equals = W1 == W2;
    cout << "W1 == W2: " << equals << endl;

    cout << "W3.x: " << W3[1] << " W3.y: " << W3[2] << endl;

}