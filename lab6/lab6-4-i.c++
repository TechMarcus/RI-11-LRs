#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

// Базові функції
template <typename T>
void PrintArray(const T* a, const int size)
{
    for (int i = 0; i < size; i++)
        cout << setw(5) << a[i];
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

// 1.1
template <typename T>
T SumPositive(const T* a, const int size)
{
    T sum = 0;
    for (int i = 0; i < size; i++)
        if (a[i] > 0)
            sum += a[i];
    return sum;
}

// 1.2
template <typename T>
int IndexOfBiggestByModule(const T* a, const int size)
{
    int index = 0;
    for (int i = 1; i < size; i++)
        if (abs(a[i]) > abs(a[index]))
            index = i;
    return index;
}

template <typename T>
int IndexOfSmallestByModule(const T* a, const int size)
{
    int index = 0;
    for (int i = 1; i < size; i++)
        if (abs(a[i]) < abs(a[index]))
            index = i;
    return index;
}

template <typename T>
bool MultiplyInRange(const T* a, const int size, T& result)
{
    int indexMax = IndexOfBiggestByModule(a, size);
    int indexMin = IndexOfSmallestByModule(a, size);

    if (indexMax < indexMin)
        swap(indexMin, indexMax);

    if (indexMax - indexMin <= 1)
        return false;               // nothing between them, result is not set

    result = 1;
    for (int i = indexMin + 1; i < indexMax; i++)
        result *= a[i];

    return true;
}

// 2.0
template <typename T>
void SortOddDescending(T* a, const int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        if (a[i] == floor(a[i]) && fmod(a[i], 2) != 0)
        {
            for (int j = i + 1; j < size; j++)
            {
                if (a[j] == floor(a[j]) && fmod(a[j], 2) != 0 && a[j] > a[i])
                {
                    swap(a[i], a[j]);
                }
            }
        }
    }
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

    double result;
    if (MultiplyInRange(a, n, result))
        cout << "Product of elements between max and min by module: " << result << endl;
    else
        cout << "No elements between max and min by module." << endl;

    cout << "Array after sorting odd elements in descending order: ";
    SortOddDescending(a, n); PrintArray(a, n);

    delete[] a;
    return 0;
}
#endif