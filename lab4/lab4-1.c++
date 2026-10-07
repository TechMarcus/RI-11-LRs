#include <iostream>
#include <cmath>
using namespace std;

int main()
{
    int k, N, i;
    double S;

    cout << "k = "; cin >> k;
    cout << "N = "; cin >> N;

    S = 0;
    i = k;

    while (i <= 19)
    {
        S += sqrt(pow(sin(1.0 * i), 2) +
                  pow(cos(1.0 * N / i), 2));
        i++;
    }

    cout << S << endl;

    // while do

    S = 0;
    i = k;

    do
    {
        S += sqrt(pow(sin(1.0 * i), 2) +
                  pow(cos(1.0 * N / i), 2));
        i++;
    }
    while (i <= 19);

    cout << S << endl;

    // for increment

    S = 0;

    for (i = k; i <= 19; i++)
    {
        S += sqrt(pow(sin(1.0 * i), 2) +
                  pow(cos(1.0 * N / i), 2));
    }

    cout << S << endl;

    // for decrement

    S = 0;

    for (i = 19; i >= k; i--)
    {
        S += sqrt(pow(sin(1.0 * i), 2) +
                  pow(cos(1.0 * N / i), 2));
    }

    cout << S << endl;

    return 0;
}