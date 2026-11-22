#include <cmath>
#include "dod.h"
#include "sum.h"
#include "var.h"
using namespace nsDod;
using namespace nsVar;

void nsSum::sum(){
    n = 0;
    a = 1;
    s = a;
    do{
        n++;
        dod();      // обчислення наступного доданку
        s += a;
    } while (fabs(a) > e);
}