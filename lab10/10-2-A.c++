#include <iostream>
#include <string>
#include <limits>
#include <algorithm>
#include <iomanip>
#ifdef _WIN32
#include <windows.h>
#endif
using namespace std;

enum Spec { CS, INF, ME, FI, TN };
const int SPEC_COUNT = 5;
const string SPEC_NAME[SPEC_COUNT] = {
    "Комп'ютерні науки", "Інформатика", "Математика та економіка",
    "Фізика та інформатика", "Трудове навчання"};

struct Student {
    string surname;
    int course;
    Spec spec;
    int phys, math, inf;
};

int readInt(const string& msg, int lo, int hi) {
    int x;
    while (true) {
        cout << msg;
        if (cin >> x && x >= lo && x <= hi) {
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
            return x;
        }
        cout << "Помилка! Введіть ціле число від " << lo << " до " << hi << ".\n";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }
}

string readSurname(const string& msg) {
    string s;
    while (true) {
        cout << msg;
        cin >> s;
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        bool ok = !s.empty();
        for (unsigned char c : s)
            if (isdigit(c)) ok = false;
        if (ok) return s;
        cout << "Помилка! Прізвище не може містити цифр.\n";
    }
}

Spec readSpec() {
    for (int i = 0; i < SPEC_COUNT; i++)
        cout << "  " << i + 1 << " - " << SPEC_NAME[i] << "\n";
    return (Spec)(readInt("Спеціальність (1-5): ", 1, SPEC_COUNT) - 1);
}

void createArray(Student*& a, int*& idx, int& n) {
    delete[] a;
    delete[] idx;
    n = readInt("Кількість студентів: ", 1, 1000);
    a = new Student[n];
    idx = new int[n];
    for (int i = 0; i < n; i++) {
        cout << "\n--- Студент " << i + 1 << " ---\n";
        a[i].surname = readSurname("Прізвище: ");
        a[i].course = readInt("Курс (1-6): ", 1, 6);
        a[i].spec = readSpec();
        a[i].phys = readInt("Оцінка з фізики (1-5): ", 1, 5);
        a[i].math = readInt("Оцінка з математики (1-5): ", 1, 5);
        a[i].inf = readInt("Оцінка з інформатики (1-5): ", 1, 5);
        idx[i] = i;
    }
}

// ---------- виведення таблиці ----------
void printTable(const Student* a, int n, const int* idx, const string& title) {
    cout << "\n" << title << "\n";
    string line(84, '-');
    cout << line << "\n";
    cout << left;
    cout << "|" << setw(4) << "№" << "|" << setw(14) << "Прізвище" << "|" << setw(6) << "Курс"
         << "|" << setw(25) << "Спеціальність" << "|" << setw(9) << "Фізика"
         << "|" << setw(9) << "Матем." << "|" << setw(9) << "Інформ." << "|\n";
    cout << line << "\n";

    for (int i = 0; i < n; i++) {
        int k = idx ? idx[i] : i;
        const Student& s = a[k];
        cout << "|" << setw(4) << k + 1 << "|" << setw(14) << s.surname
             << "|" << setw(6) << s.course << "|" << setw(25) << SPEC_NAME[s.spec]
             << "|" << setw(9) << s.phys << "|" << setw(9) << s.math
             << "|" << setw(9) << s.inf << "|\n";
    }
    cout << line << "\n";
}


int compare(const Student& a, const Student& b, bool surnameDesc) {
    if (a.course != b.course) return a.course < b.course ? -1 : 1;
    int c = SPEC_NAME[a.spec].compare(SPEC_NAME[b.spec]);
    if (c != 0) return c < 0 ? -1 : 1;
    c = a.surname.compare(b.surname);
    if (c == 0) return 0;
    if (surnameDesc) c = -c;
    return c < 0 ? -1 : 1;
}

// фізично впорядкування
void sortPhysical(Student* a, int n) {
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (compare(a[j], a[j + 1], true) > 0) swap(a[j], a[j + 1]);
}

// іедексний масив
void buildIndex(const Student* a, int n, int* idx) {
    for (int i = 0; i < n; i++) idx[i] = i;
    for (int i = 0; i < n - 1; i++)
        for (int j = 0; j < n - 1 - i; j++)
            if (compare(a[idx[j]], a[idx[j + 1]], false) > 0) swap(idx[j], idx[j + 1]);
}


int binarySearch(const Student* a, int n, const int* idx, const Student& key) {
    int lo = 0, hi = n - 1;
    while (lo <= hi) {
        int mid = (lo + hi) / 2;
        int c = compare(key, a[idx[mid]], false);
        if (c == 0) return idx[mid];
        if (c < 0) hi = mid - 1;
        else lo = mid + 1;
    }
    return -1;
}

void searchStudent(const Student* a, int n, int* idx) {
    Student key;
    key.surname = readSurname("Прізвище: ");
    key.course = readInt("Курс (1-6): ", 1, 6);
    key.spec = readSpec();
    buildIndex(a, n, idx);
    int pos = binarySearch(a, n, idx, key);
    if (pos >= 0)
        cout << "Так, студент навчається (№ " << pos + 1 << " у списку).\n";
    else
        cout << "Такого студента немає.\n";
}

#ifndef UNIT_TEST

int main() {
#ifdef _WIN32
    SetConsoleOutputCP(65001);
    SetConsoleCP(65001);
#endif
    Student* a = nullptr;
    int* idx = nullptr;
    int n = 0, choice;
    do {
        cout << "\n===== МЕНЮ =====\n"
                "1 - Ввести масив\n"
                "2 - Показати таблицю\n"
                "3 - Фізичне впорядкування\n"
                "4 - Індексне впорядкування (вивід)\n"
                "5 - Бінарний пошук\n"
                "0 - Вихід\n";
        choice = readInt("Ваш вибір: ", 0, 5);
        if (choice >= 2 && n == 0) {
            cout << "Спочатку введіть масив (пункт 1).\n";
            continue;
        }
        switch (choice) {
            case 1: createArray(a, idx, n); break;
            case 2: printTable(a, n, nullptr, "СПИСОК СТУДЕНТІВ"); break;
            case 3:
                sortPhysical(a, n);
                printTable(a, n, nullptr, "ФІЗИЧНО ВПОРЯДКОВАНИЙ МАСИВ");
                break;
            case 4:
                buildIndex(a, n, idx);
                printTable(a, n, idx, "ІНДЕКСНЕ ВПОРЯДКУВАННЯ");
                break;
            case 5: searchStudent(a, n, idx); break;
        }
    } while (choice != 0);

    delete[] a;
    delete[] idx;
    return 0;
}

#endif