#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    double x, xp, xk, dx, R, F;

    cout << "R = ";
    cin >> R;

    cout << "xp = ";
    cin >> xp;

    cout << "xk = ";
    cin >> xk;

    cout << "dx = ";
    cin >> dx;

    cout << fixed;
    cout << "--------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
         << setw(10) << "F" << " |" << endl;
    cout << "--------------------------------" << endl;

    x = xp;

    while (x <= xk)
    {
        if (x < -8)
        {
            F = -R;
        }
        else if (x <= -R)
        {
            F = R * (x + R) / (8.0 - R);
        }
        else if (x <= R)
        {
            F = -sqrt(R * R - x * x);
        }
        else if (x <= 5)
        {
            F = 2.0 * (x - R) / (5.0 - R);
        }
        else
        {
            F = 3.0;
        }

        cout << "|" << setw(7) << setprecision(2) << x
             << " |" << setw(10) << setprecision(3) << F
             << " |" << endl;

        x += dx;
    }

    cout << "--------------------------------" << endl;

    return 0;
}
