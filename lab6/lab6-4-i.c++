#include <iostream>
#include <iomanip>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;



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

template <typename T>
T SumPositive(const T* a, const int size)
{
    T sum = 0;
    for (int i = 0; i < size; i++)
        if (a[i] > 0)
            sum += a[i];
    return sum;
}

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

template <typename T>
T SetMinAndMaxInd(const T* a, const int size)
{
    int indexMax = IndexOfBiggestByModule(a, size);
    int indexMin = IndexOfSmallestByModule(a, size);

    if (indexMax < indexMin)
        swap(indexMin, indexMax);

    return indexMin, indexMax;
}

template <typename T>
T MultiplyInRange(const T* a, const int size)
{
    int indexMin, indexMax = SetMinAndMaxInd(a, size);

    if (indexMax - indexMin <= 1) 
    {
        return 1; 
    }
    T multipRes = 1;
    for (int i = indexMin + 1; i < indexMax; i++) {
        multipRes *= a[i];
    }

    return multipRes;
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