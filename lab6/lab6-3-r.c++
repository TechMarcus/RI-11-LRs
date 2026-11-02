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

void PrintArray(int* a, const int size, int i = 0)
{
    if (i >= size) {
        cout << endl;
        return;
    }
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

void FillWithRandom(int* a, const int size, int i = 0)
{
    if (i >= size) return;

    a[i] = -50 + rand() % 100;
    FillWithRandom(a, size,  i + 1);
}


int FindBiggestEven(const int* a, const int size, bool* found = nullptr,
                    int i = 0, int max = 0, bool hasMax = false)
{
    if (i >= size)
    {
        if (found)
            *found = hasMax;
        return max;
    }

    if (a[i] % 2 == 0 && (!hasMax || a[i] > max))
    {
        max = a[i];
        hasMax = true;
    }
    return FindBiggestEven(a, size, found, i + 1, max, hasMax);
}

template <typename T>
T FindBiggestEven(const T* a, const int size, bool* found = nullptr,
                  int i = 0, T max = T{}, bool hasMax = false)
{
    if (i >= size)
    {
        if (found)
            *found = hasMax;
        return max;
    }

    if (a[i] % 2 == 0 && (!hasMax || a[i] > max))
    {
        max = a[i];
        hasMax = true;
    }
    return FindBiggestEven<T>(a, size, found, i + 1, max, hasMax);
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
    
    cout << "Standart funcs: ";
    FillWithRandom(a, n);
    PrintArray(a, n);
    
        bool found1;
    int i1 = FindBiggestEven(a, n, &found1);
    if (!found1)
        cout << "FindBiggestEven(a, n): nema parnuh" << endl;
    else
        cout << "FindBiggestEven(a, n) = " << i1 << endl;

    cout << endl;

    int* b = new int[n];

    cout << "Template funcs: ";
    FillWithRandom<int>(b, n);
    PrintArray<int>(b, n);

    bool found2;
    int i2 = FindBiggestEven<int>(b, n, &found2);
    if (!found2)
        cout << "FindBiggestEven<int>(b, n): nema parnuh" << endl;
    else
        cout << "FindBiggestEven<int>(b, n) = " << i2 << endl;

    delete[] b;

    return 0;
}

#endif