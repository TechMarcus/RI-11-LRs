// Лабораторна робота № 5.4
#include <iostream>
#include <cmath>

using namespace std;

double S0(const int limit, const int N) {
    double s = 0;
    for (int k = N; k <= limit; k++) {
        s += sqrt(sin(1.*k)*sin(1.*k) + cos(N/k)*cos(N/k));
    }
    return s;
}

double S1(const int limit, const int N, const int i) {
    if (i > limit) {
        return 0;
    } else {
        return sqrt(sin(1.*i)*sin(1.*i) + cos(N/i)*cos(N/i)) + S1(limit, N, i + 1);
    }
}

double S2(const int limit, const int N, const int i) {
    if (i < N) {
        return 0;
    } else {
        return sqrt(sin(1.*i)*sin(1.*i) + cos(N/i)*cos(N/i)) + S2(limit, N, i - 1);
    }
}

double S3(const int limit, const int N, const int i, double t) {
    t = t + sqrt(sin(1.*i)*sin(1.*i) + cos(N/i)*cos(N/i));
    if (i >= limit) {
        return t;
    } else {
        return S3(limit, N, i + 1, t);
    }
}

double S4(const int limit, const int N, const int i, double t) {
    t = t + sqrt(sin(1.*i)*sin(1.*i) + cos(N/i)*cos(N/i));
    if (i <= N) {
        return t;
    } else {
        return S4(limit, N, i - 1, t);
    }
}

#ifndef UNIT_TEST

int main() {
    int N;
    int Limit = 19;
    cout << "N = "; 
    cin >> N;
    
    cout << "(iter) S0 = " << S0(Limit, N) << endl;
    cout << "(rec up ++) S1 = " << S1(Limit, N, N) << endl;
    cout << "(rec up --) S2 = " << S2(Limit, N, Limit) << endl;
    cout << "(rec down ++) S3 = " << S3(Limit, N, N, 0) << endl;
    cout << "(rec down --) S4 = " << S4(Limit, N, Limit, 0) << endl;
    
    return 0;
}

#endif