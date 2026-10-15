// Лабораторна робота № 5.2

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double S(const double x, const double eps, int &n);
double A(const double x, const int n, double a);

#ifndef UNIT_TEST
int main()
{
    double xp, xk, x, dx, eps, s = 0;
    int n = 0;

    cout << "xp = "; cin >> xp;
    cout << "xk = "; cin >> xk;
    cout << "dx = "; cin >> dx;
    cout << "eps = "; cin >> eps;

    cout << fixed;
    cout << "-----------------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
         << setw(10) << "exp(-x)" << " |"
         << setw(10) << "S" << " |"
         << setw(5) << "n" << " |"
         << endl;
    cout << "-----------------------------------------" << endl;

    x = xp;

    while (x <= xk + dx / 2)
    {
        s = S(x, eps, n);

        cout << "|" << setw(7) << setprecision(2) << x << " |"
             << setw(10) << setprecision(5) << exp(-x) << " |"
             << setw(10) << setprecision(5) << s << " |"
             << setw(5) << n << " |"
             << endl;

        x += dx;
    }

    cout << "-----------------------------------------" << endl;

    return 0;
}
#endif

double S(const double x, const double eps, int &n)
{
    n = 0;
    double a = 1;
    double s = a;

    do
    {
        n++;
        a = A(x, n, a);
        s += a;
    }
    while (fabs(a) >= eps); 

    return s;
}

double A(const double x, const int n, double a)
{
    return a * (-x / n);
}