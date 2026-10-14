#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

double s(const double x);

#ifndef UNIT_TEST
int main()
{
    double gp, gk, t, res;
    int n;

    cout << "gp = "; cin >> gp;
    cout << "gk = "; cin >> gk;
    cout << "n = "; cin >> n;

    if (n <= 0)
    {
        cout << "n має бути більше 0" << endl;
        return 1;
    }

    double dg = (gk - gp) / n;
    double root = sqrt(s(1.0));

    cout << fixed;
    cout << "--------------------------"
         << endl;
    cout << "|" << setw(9) << "t" << " |"
         << setw(12) << "res" << " |" << endl;
    cout << "--------------------------"
         << endl;

    for (int i = 0; i <= n; i++)
    {
        t = gp + i * dg;

        double a = s(2 * t + 1);
        double b = s(t * t);

        res = a + 2 * b + root;

        cout << "|" << setw(9) << setprecision(2) << t << " |"
             << setw(12) << setprecision(6) << res << " |"
             << endl;
    }

    cout << "--------------------------"
         << endl;

    return 0;
}
#endif

double s(const double x)
{
    if (fabs(x) >= 1 || x == 0)
    {
        return (cos(x) * cos(x) + 1) / exp(x);
    }
    else
    {
        double sum = 0;

        for (int k = 0; k <= 4; k++)
        {
            int m = 2 * k + 1;
            double fact = 1;

            for (int j = 1; j <= m; j++)
            {
                fact *= j;
            }

            sum += pow(2.0, m) * pow(x, m) / fact;
        }

        return sum / sin(2 * x);
    }
}