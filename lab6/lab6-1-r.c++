#include <iostream>
#include <iomanip>

using namespace std;

bool IsValidKriteria(int n) {
    if ( n > 0 || n % 3 != 0) {
        return true;
    }
    return false;
}
void FillWithRandom(int* a, const int size, const int Low, const int High, int i = 0)
{
    if (i >= size) return;

    a[i] = Low + rand() % (High - Low + 1);
    FillWithRandom(a, size, Low, High, i + 1);
}

void NullTheSpecified(int* a, const int size, int i = 0)
{
    if (i >= size) return;

    if (IsValidKriteria(a[i]))
        {
            a[i] = 0;
        }
    NullTheSpecified(a, size, i + 1);
}

void SumOfSpecified(int* a, const int size, int* sum, int i = 0)
{
    if (i >= size) return;

    if (IsValidKriteria(a[i]))
    {
            *sum += a[i];
    }
    SumOfSpecified(a, size, sum, i + 1);
}

void NumOfSpecified(int* a, const int size, int* count, int i = 0)
{
    if (i >= size) return;

    if (IsValidKriteria(a[i]))
    {
            *count+=1;
    }
    NumOfSpecified(a, size, count, i + 1);
}

void PrintArray(int* a, const int size, int i = 0)
{
    if (i >= size) {
        cout << endl;
        return;
    }

    cout << setw(4) << a[i];
    PrintArray(a, size, i + 1);
}


#ifndef UNIT_TEST

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

    const int n = 22;
    int a[n];

    FillWithRandom(a, n, -10, 35);
    PrintArray(a, n);

    int sum = 0, count = 0;
    SumOfSpecified(a, n, &sum);
    NumOfSpecified(a, n, &count);
    cout << "Suma: " << sum << endl;
    cout << "Kilkist: " << count << endl;

    NullTheSpecified(a, n);

    PrintArray(a, n);
    return 0;
}

#endif