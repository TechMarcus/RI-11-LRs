// Lab_03_4.cpp
// < Возниця Маркіян >
// Лабораторна робота № 3.4
// Розгалуження, задане плоскою фігурою.
// Варіант 2

#include <iostream>
using namespace std;

int main() {
    double x; // вхідний аргумент
    double y; // вхідний параметр
    double R; // вхідний параметр

    cout << "R = "; cin >> R;
    cout << "x = "; cin >> x;
    cout << "y = "; cin >> y;


    bool inCircle = (x <= 0) && (y >= 0) && (x * x + y * y <= R * R);
    bool inTriangle = (y <= 0) && (2 * x + y >= 0) && (2 * x - y <= 2 * R);

    if (inCircle || inTriangle)
        cout << "yes" << endl;
    else
        cout << "no" << endl;

    return 0;
}