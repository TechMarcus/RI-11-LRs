// Lab 5_1

#include <iostream>
#include <cmath>

using namespace std;

double k(const double x, const double y); // прототип

#ifndef UNIT_TEST
int main()
{
    double p, q, c;
    cout << "p = "; cin >> p;
    cout << "q = "; cin >> q;

    c = k(p + sqrt(q), q - sqrt(p))
      * k(p + sqrt(q), q - sqrt(p))
      - k(1.0, p + q);

    cout << "c = " << c << endl;
    return 0;
}
#endif

double k(const double x, const double y)
{
    return x / abs(x * x * x + y * y * y)
         + y / abs(x + y);
}
