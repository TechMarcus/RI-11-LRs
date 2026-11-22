//////////////////////////////////////////////////////////////////////////////
// dod.cpp
// файл реалізації функції
#include "dod.h"
#include "var.h"
using namespace nsVar;

void nsDod::dod(){
    a *= -x / n;   // a_n = a_(n-1) * (-x) / n  ->  (-1)^n * x^n / n!
}