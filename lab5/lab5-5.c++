// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>

using namespace std;

int f(int n) {
    if (n == 0) {
        return 0;
    } else {
        return 1 + f(n & (n-1));
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
    
    cout << f(N) << endl;
    return 0;
}

#endif