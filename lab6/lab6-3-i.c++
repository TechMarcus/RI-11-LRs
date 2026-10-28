#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
void PrintArray(const T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(4) << a[i];
    cout << endl;
}

template <typename T>
void FillWithRandom(T* a, const int size)
{
    for (int i=0; i<size; i++)
    {
        a[i] = -50 + rand() % 100;
    }
}

int FindBiggestEven(const int* a, const int size)
{
    int max = -1;
    for (int i = 0; i < size; i++)
        if (a[i] % 2 == 0 && (max == -1 || a[i] > max))
            max = a[i];
    return max;
}

template <typename T>
int FindBiggestEven(const T* a, const int size)
{
    int max = -1;
    for (int i = 0; i < size; i++)
        if (a[i] % 2 == 0 && (max == -1 || a[i] > max))
            max = a[i];
    return max;
}

#ifndef UNIT_TEST
int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
    
    int n;
    do {
        cout << "Enter the size of the array: ";
        cin >> n;

    } while (n <= 0 || n > 10);

    int* a = new int[n]; 
    FillWithRandom(a, n);

    PrintArray(a, n);

    int i1 = FindBiggestEven(a, n);
    if (i1 == -1)
        cout << "FindBiggestEven(a, n): nema parnuh" << endl;
    else
        cout << "FindBiggestEven(a, n) = " << i1 << endl;

    int i2 = FindBiggestEven<int>(a, n);
    if (i2 == -1)
        cout << "FindBiggestEven<int>(a, n): nema parnuh" << endl;
    else
        cout << "FindBiggestEven<int>(a, n) = " << i2 << endl;

    return 0;
}
#endif