#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    double x, y, R;

    cout << "R = "; cin >> R;

    srand((unsigned) time(NULL));

    // Ручний інпут
    cout << "\n--- Manual Input Tests ---\n";
    for (int i = 0; i < 10; i++)
    {
        cout << "x = "; cin >> x;
        cout << "y = "; cin >> y;

        bool in_shaded_region = (x <= 0 && y >= 0 && (x * x + y * y <= R * R)) ||
                                (x >= 0 && y <= 0 && y >= -2 * x && y >= 2 * x - 2 * R);

        if (in_shaded_region)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    // Рандомні числа
    cout << fixed;
    for (int i = 0; i < 10; i++)
    {
        x = 6.0 * rand() / RAND_MAX - 3.0;
        y = 6.0 * rand() / RAND_MAX - 3.0;

        bool in_shaded_region = (x <= 0 && y >= 0 && (x * x + y * y <= R * R)) ||
                                (x >= 0 && y <= 0 && y >= -2 * x && y >= 2 * x - 2 * R);

        cout << setw(8) << setprecision(4) << x << " "
             << setw(8) << setprecision(4) << y << " ";

        if (in_shaded_region)
            cout << "yes" << endl;
        else
            cout << "no" << endl;
    }

    return 0;
}