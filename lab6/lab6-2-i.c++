#include <iostream>
#include <iomanip>

using namespace std;

void FillWithRandom(int* a, const int size)
{
    for (int i=0; i<size; i++)
    {
        a[i] = -50 + rand() % 100;
    }
}

int FindIndexOfSmallestElement(int* a, const int size)
{
    int minIndex = -1;
    for (int i = 0; i < size; i++)
    {
        if (a[i] % 2 != 0 && (minIndex == -1 || a[i] < a[minIndex]))
        {
            minIndex = i;
        }
    }
    return minIndex;
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
    
    int n;
    do {
        cout << "Enter the size of the array: ";
        cin >> n;

    } while (n <= 0 || n > 10);

    int a[n];
    FillWithRandom(a, n);

    PrintArray(a, n);
    
    cout << "Index of the smallest element: " << FindIndexOfSmallestElement(a, n) << endl;
    
    return 0;
}

#endif