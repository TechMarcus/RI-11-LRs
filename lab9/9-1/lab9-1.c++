//////////////////////////////////////////////////////////////////////////////
// Lab_9_1.cpp
// головний файл проекту – функція main
#include <iostream>
#include <iomanip>
#include <cmath>
#include "sum.h"
#include "var.h"
using namespace std;
using namespace nsSum;
using namespace nsVar;

int main()
{
    cout << "x_p = "; cin >> x_p;
    cout << "x_k = "; cin >> x_k;
    cout << "dx = ";  cin >> dx;
    cout << "e = ";   cin >> e;
    cout << endl;

    cout << fixed << setprecision(8);
    cout << setw(12) << "x"
         << setw(16) << "S(x)"
         << setw(16) << "exp(-x)"
         << setw(6)  << "n" << endl;

    x = x_p;
    while (x <= x_k){
        sum(); // виклик процедури обчислення суми
        cout << setw(12) << x
             << setw(16) << s
             << setw(16) << exp(-x)
             << setw(6)  << n << endl;
        x += dx;
    }
    cin.get();
    cin.get();
    return 0;
}