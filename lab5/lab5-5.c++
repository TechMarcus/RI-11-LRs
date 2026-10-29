// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>

using namespace std;

int f(int n, int level) {
    cout << "Potochnuy riven: " << level << endl;
    if (n == 0) {
        return 0;
    } else {
        level++;
        return 1 + f(n & (n-1), level);
    }
    // cout << "Непгавельний аргумент" << endl;
    // return -1;
}

#ifndef UNIT_TEST

int main() {
    int N;
    do {
        cout << "N = "; cin >> N;
    } while (N < 0);

    int deepInomer = f(N,0);
    cout << "Hlubuna i Kilkist 1 v n: " << deepInomer << endl;
    return 0;
}

#endif