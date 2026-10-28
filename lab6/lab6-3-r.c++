#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T>
void PrintArray(const T* a, const int size, int i = 0)
{
    if (i >= size) { cout << endl; return; }
    cout << setw(4) << a[i];
    PrintArray(a, size, i + 1);
}

template <typename T>
void FillWithRandom(T* a, const int size, int i = 0)
{
    if (i >= size) return;

    a[i] = -50 + rand() % 100;
    FillWithRandom(a, size,  i + 1);
}


int FindBiggestEven(const int* a, const int size, int i = 0, int max = -1)
{
    if (i >= size) return max;

    if (a[i] % 2 == 0 && (max == -1 || a[i] > max))
        max = a[i];
    return FindBiggestEven(a, size, i + 1, max);
}

template <typename T>
int FindBiggestEven(const T* a, const int size, int i = 0, int max = -1)
{
    if (i >= size) return max;

    if (a[i] % 2 == 0 && (max == -1 || a[i] > max))
        max = a[i];
    return FindBiggestEven<T>(a, size, i + 1, max);
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