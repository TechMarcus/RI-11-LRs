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
    string result;


    bool inCircle = (x <= 0) && (y >= 0) && (x * x + y * y <= R * R);
    bool inTriangle = (y <= 0) && (2 * x + y >= 0) && (2 * x - y <= 2 * R);

    if (inCircle || inTriangle)
        result = "yes";
    else
        result = "no";

    cout << endl;
    cout << "1) " << result << endl;

    // розширена форма
    if (inCircle) {
        result = "yes";
    } 
    else if (inTriangle) {
        result = "yes";
    } 
    else {
        result = "no";
    }

    cout << "2) " << result << endl;

    return 0;
}