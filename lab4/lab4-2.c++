#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

int main()
{
    double x, xp, xk, dx, y, B;

    cout << "xp = ";
    cin >> xp;

    cout << "xk = ";
    cin >> xk;

    cout << "dx = ";
    cin >> dx;

    cout << fixed;
    cout << "--------------------------------" << endl;
    cout << "|" << setw(7) << "x" << " |"
         << setw(10) << "y" << " |" << endl;
    cout << "--------------------------------" << endl;

    x = xp;

    while (x <= xk)
    {
        if (x < 1)
            B = 0.65 * x + 8;
        else if (x < 5)
            B = atan((x + 6.1) / 2) + exp(x);
        else
            B = sqrt(1 + sqrt(x));

        y = 1 / x + 4 - B;

        cout << "|" << setw(7) << setprecision(2) << x
                << " |" << setw(10) << setprecision(3) << y
                << " |" << endl;
    

        x += dx;
    }

    cout << "--------------------------------" << endl;

    return 0;
}