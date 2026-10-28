#include <iostream>
#include <iomanip>

using namespace std;

bool IsValidKriteria(int n) {
    if ( n > 0 || n % 3 != 0) {
        return true;
    }
    return false;
}
void FillWithRandom(int* a, const int size, const int Low, const int High)
{
    for (int i=0; i<size; i++)
    {
        a[i] = Low + rand() % (High - Low + 1);
    }
}

void NullTheSpecified(int* a, const int size)
{
    for (int i=0; i<size; i++)
    {
        if (IsValidKriteria(a[i]))
        {
            a[i] = 0;
        }
    }
}

void SumOfSpecified(int* a, const int size, int* sum)
{
    *sum = 0;
    for (int i=0; i<size; i++)
    {
        if (IsValidKriteria(a[i]))
        {
            *sum += a[i];
        }
    }
}

void NumOfSpecified(int* a, const int size, int* count)
{
    *count = 0;
    for (int i=0; i<size; i++)
    {
        if (IsValidKriteria(a[i]))
        {
            *count+=1;
        }
    }
}

void PrintArray(int* a, const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << setw(4) << a[i];
    }
    cout << endl;
}


#ifndef UNIT_TEST

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел

    const int n = 22;
    int a[n];

    FillWithRandom(a, n, -10, 35);
    PrintArray(a, n);

    int sum, count;
    SumOfSpecified(a, n, &sum, &count);
    NumOfSpecified(a, n, &count);
    cout << "Suma: " << sum << endl;
    cout << "Kilkist: " << count << endl;

    NullTheSpecified(a, n);

    PrintArray(a, n);
    return 0;
}

#endif