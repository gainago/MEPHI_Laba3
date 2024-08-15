

#include <assert.h>
#include "../Complex.h"

void testComplexConstructors()
{
    Complex test1;
    assert(test1.GetImPart() == 0 && test1.GetRealPart() == 0);
    Complex test2(18, 24);
    assert(test2.GetRealPart() == 18 && test2.GetImPart() == 24);
    Complex test3(test2);
    assert(test3.GetRealPart() == 18 && test3.GetImPart() == 24);
}

void testComplexFunctions()
{
    Complex test1(3, 4);
    assert(test1.Abs() == 5);
    Complex test2(18, 24);
    assert(test2.GetRealPart() == 18 && test2.GetImPart() == 24);
}

void testComplexOperators()
{
    Complex test1(3, 7);
    Complex test2(9, 12);
    Complex test3 = test1 + test2;
    assert(test3.GetImPart() == 7 + 12 && test3.GetRealPart() == 3 + 9);
    Complex test4 = test1 - test2;
    assert(test4.GetRealPart() == 3 - 9 && test4.GetImPart() == 7 - 12);
    Complex test5 = test1 * test2;
    assert(test5.GetRealPart() == -57 && test5.GetImPart() == 99);
    assert((test5 != test4) == true);
    assert((test1 == test2) == false);
}


