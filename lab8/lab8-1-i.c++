// Дано літерний рядок, який містить послідовність символів s[0], ..., s[n], ...
// 1. Підрахувати загальне число входжень символів '+', '-', '=' в цій послідовності.
// 2. Замінити кожний із символів '+', '-', '=' парою зірочок "**".
#include <iostream>
using namespace std;

bool IsSign(char c)
{
    return c == '+' || c == '-' || c == '=';
}

int Count(const char* str)
{
    int k = 0;
    for (int i = 0; str[i] != 0; i++)
        if (IsSign(str[i]))
            k++;
    return k;
}

char* Change(char* dest, const char* str)
{
    int j = 0;
    for (int i = 0; str[i] != 0; i++)
        if (IsSign(str[i]))
        {
            dest[j++] = '*';
            dest[j++] = '*';
        }
        else
            dest[j++] = str[i];
    dest[j] = '\0';
    return dest;
}
#ifndef UNIT_TEST

int main()
{
    char str[101];
    cout << "Enter string:" << endl;
    cin.getline(str, 100);

    cout << "String contained " << Count(str) << " characters '+', '-', '='" << endl;

    char* dest1 = new char[201];
    char* dest2 = Change(dest1, str);

    cout << "Modified string (param) : " << dest1 << endl;
    cout << "Modified string (result): " << dest2 << endl;

    delete[] dest1;
    return 0;
}

#endif