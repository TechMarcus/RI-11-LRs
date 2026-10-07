#include <iostream>
#include <cmath>

using namespace std;

int main()
{
    double P, S;
    int n, i;

    // while
    P = 1;
    n = 1;
    while (n <= 15)
    {
        S = 0;
        i = 1;
        while (i <= n)
        {
            S += 1.0 / i;
            i++;
        }

        P *= (sin(1.0 * n) * sin(1.0 * n) +
              cos(S) * cos(S)) / (1.0 * n * n);

        n++;
    }
    cout << P << endl;


    // do while
    P = 1;
    n = 1;
    do
    {
        S = 0;
        i = 1;
        do
        {
            S += 1.0 / i;
            i++;
        } while (i <= n);

        P *= (sin(1.0 * n) * sin(1.0 * n) +
              cos(S) * cos(S)) / (1.0 * n * n);

        n++;
    } while (n <= 15);

    cout << P << endl;


    // for
    P = 1;
    for (n = 1; n <= 15; n++)
    {
        S = 0;

        for (i = 1; i <= n; i++)
        {
            S += 1.0 / i;
        }

        P *= (sin(1.0 * n) * sin(1.0 * n) +
              cos(S) * cos(S)) / (1.0 * n * n);
    }
    cout << P << endl;


    // інвертоване for
    P = 1;
    for (n = 15; n >= 1; n--)
    {
        S = 0;

        for (i = n; i >= 1; i--)
        {
            S += 1.0 / i;
        }

        P *= (sin(1.0 * n) * sin(1.0 * n) +
              cos(S) * cos(S)) / (1.0 * n * n);
    }
    cout << P << endl;

    return 0;
}