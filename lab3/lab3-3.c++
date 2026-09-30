// Lab_03_3.cpp
// < Возниця Маркіян >
// Лабораторна робота № 3.3
// Розгалуження, задане графіком функції.
// Варіант 2
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    double x; // вхідний аргумент
    double R; // вхідний параметр
    double y; // результат обчислення

    cout << "R = ";
    cin >> R;

    cout << "x = ";
    cin >> x;

    if (x <= -8)
        y = -R;
    else if (x > -8 && x <= -R)
        y = (R / 8) * (x + R);
    else if (x > -R && x < R)
        y = -sqrt(R * R - x * x);
    else if (x >= R && x < 5)
        y = (2.0 / (5 - R)) * (x - R);
    else
        y = 3;

    cout << endl;
    cout << "y = " << y << endl;

    cin.get();
    return 0;
}
