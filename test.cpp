
#include "tests/testComplex.h"
#include "tests/testVector.h"
#include "tests/testLinearForm.h"
#include "tests/testStack.h"

void testComplex()
{
    testComplexOperators();
    testComplexFunctions();
    testComplexConstructors();
}

void testVector()
{
    testVectorConstructors();
    testVectorSum();
    testVectorMultiOnScalar();
    testVectorScalarProduct();
    testVectorOperators();
}

void testLinearForm()
{
    testLinearFormConstructors();
    testLinearFormSum();
    testLinearFormSubtract();
    testLinearFormMultiOnScalar();
    testLinearFormCalcValue();
    testLinearFormOperators();
}

void testStack()
{
    testStackConstructors();
    testStackIsEmpty();
    testStackPeek();
    testStackTop();
    testStackPush();
    testStackMap();
    testStackReduce();
    testStackWhere();
    testStackConcat();
    testGetSubStack();
    testIsSubStackHere();
}

