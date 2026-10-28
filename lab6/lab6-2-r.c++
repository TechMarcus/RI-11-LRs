#include <iostream>
#include <iomanip>

using namespace std;

void FillWithRandom(int* a, const int size, int i = 0)
{
    if (i >= size) return;

    a[i] = -50 + rand() % 100;
    FillWithRandom(a, size,  i + 1);
}

int FindIndexOfSmallestElement(int* a, const int size, int i = 0, int minIndex = -1)
{
    if (i >= size) return minIndex;

    if (a[i] % 2 != 0 && (minIndex == -1 || a[i] < a[minIndex]))
        minIndex = i;   

    return FindIndexOfSmallestElement(a, size, i + 1, minIndex);
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
    
    int n;
    do {
        cout << "Enter the size of the array: ";
        cin >> n;

    } while (n <= 0 || n > 10);

    int a[n];
    FillWithRandom(a, n);

    PrintArray(a, n);
    
    cout << "Index of the smallest element: " << FindIndexOfSmallestElement(a, n,0,-1) << endl;

    return 0;
}

#endif