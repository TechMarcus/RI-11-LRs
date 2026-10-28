#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Базові функції
template <typename T>
void PrintArray(const T* a, const int size, int i = 0)
{
    if (i >= size) { cout << endl; return; }
    cout << setw(5) << a[i];
    PrintArray(a, size, i + 1);
}

template <typename T>
void FillWithRandom(T* a, const int size, int i = 0)
{
    if (i >= size) return;

    a[i] = -50 + rand() % 100;
    FillWithRandom(a, size,  i + 1);
}

// 1.1
template <typename T>
T SumPositive(const T* a, const int size, int i = 0)
{
    if (i == size)
        return 0;
    T current = a[i] > 0 ? a[i] : 0;
    return current + SumPositive(a, size, i + 1);
}

// 1.2
template <typename T>
int IndexOfBiggestByModule(const T* a, const int size, int index = 0, int i = 1)
{
    if (i >= size)
        return index;
    if (abs(a[i]) > abs(a[index]))
        index = i;
    return IndexOfBiggestByModule(a, size, index, i + 1);
}

template <typename T>
int IndexOfSmallestByModule(const T* a, const int size, int index = 0, int i = 1)
{
    if (i >= size)
        return index;
    if (abs(a[i]) < abs(a[index]))
        index = i;
    return IndexOfSmallestByModule(a, size, index, i + 1);
}

template <typename T>
T ProductRange(const T* a, int min, const int max)
{
    if (min >= max)
        return 1;
    return a[min] * ProductRange(a, min + 1, max);
}

template <typename T>
T MultiplyInRange(const T* a, const int size)
{
    int indexMax = IndexOfBiggestByModule(a, size);
    int indexMin = IndexOfSmallestByModule(a, size);

    if (indexMax < indexMin)
        swap(indexMin, indexMax);

    if (indexMax - indexMin <= 1)
    {
        return 1;
    }

    return ProductRange(a, indexMin + 1, indexMax);
}

// 2.0

template <typename T>
void SwapWithLargerOdd(T* a, const int size, const int i, int j)
{
    if (j >= size)
        return;
    if (a[j] == floor(a[j]) && fmod(a[j], 2) != 0 && a[j] > a[i])
        swap(a[i], a[j]);
    SwapWithLargerOdd(a, size, i, j + 1);
}

template <typename T>
void SortOddDescending(T* a, const int size, int i = 0)
{
    if (i >= size - 1)
        return;
    if (a[i] == floor(a[i]) && fmod(a[i], 2) != 0)
        SwapWithLargerOdd(a, size, i, i + 1);
    SortOddDescending(a, size, i + 1);
}

#ifndef UNIT_TEST

int main()
{
    srand((unsigned)time(NULL)); // ініціалізація генератора випадкових чисел
    
    int n;
    do {
        cout << "Enter the size of the array: ";
        cin >> n;

    } while (n <= 0);

    double* a = new double[n]; 
    FillWithRandom(a, n);

    PrintArray(a, n);

    cout << "Sum of positive elements: " << SumPositive(a, n) << endl;
    if (MultiplyInRange(a, n) == 1)
        cout << "No elements between max and min by module." << endl;
    else
    cout << "Res of multiplying between max and min by module: " << MultiplyInRange(a, n) << endl;
    cout << "Array after sorting odd elements in descending order: ";
    SortOddDescending(a, n); PrintArray(a, n);

    delete[] a;


    return 0;
}

#endif