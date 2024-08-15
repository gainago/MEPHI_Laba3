

#include <assert.h>
#include "../Vector.h"

void testVectorConstructors()
{
    int items[4] = {1, 2, 3, 4};
    Vector<int> test1(items, 4);
    assert(test1.GetSize() == 4);
    for (int i = 0; i < 4; i++)
    {
        assert(test1[i] == items[i]);
    }
    Vector<int> test2(test1);
    assert(test2.GetSize() == 4);
    for (int i = 0; i < 4; i++)
    {
        assert(test2[i] == items[i]);
    }
}

void testVectorSum()
{
    int items1[4] = {1, 7, 2, 4};
    int items2[4] = {0, 1, 1, 10};
    Vector<int> test1(items1, 4);
    Vector<int> test2(items2, 4);
    Vector<int> *test3 = test1.Sum(test2);
    assert(test3->GetSize() == test1.GetSize());
    for (int i = 0; i < 4; i++)
    {
        assert((*test3)[i] == (test1[i] + test2[i]));
    }
}

void testVectorMultiOnScalar()
{
    int items[4] = {1, 3, 1, 1};
    int scalar = 7;
    Vector<int> test1(items, 4);
    Vector<int> *test2 = test1.MultiOnScalar(7);
    assert(test2->GetSize() == test1.GetSize());
    for (int i = 0; i < 4; i++)
    {
        assert((*test2)[i] == test1[i] * scalar);
    }
}

void testVectorScalarProduct()
{
    int items1[4] = {1, 7, 2, 4};
    int items2[4] = {0, 1, 1, 10};
    Vector<int> test1(items1, 4);
    Vector<int> test2(items2, 4);
    int result = test1.scalarProduct(test2);
    assert(result == (0 + 7 + 2 + 40));
}


void testVectorOperators()
{
    int items1[4] = {1, 7, 2, 4};
    int items2[4] = {0, 1, 1, 10};
    Vector<int> test1(items1, 4);
    Vector<int> test2(items2, 4);
    Vector<int> *test3 = test1 + test2;
    assert(test3->GetSize() == test1.GetSize());
    for (int i = 0; i < 4; i++)
    {
        assert((*test3)[i] == (test1[i] + test2[i]));
    }
    Vector<int> *test4 = test1 * 7;
    assert(test4->GetSize() == test1.GetSize());
    for (int i = 0; i < 4; i++)
    {
        assert((*test4)[i] == (test1[i] * 7));
    }
    int test5 = test1 * test2;
    assert(test5 == (0 + 7 + 2 + 40));
    assert((test1 == test2) == false);
    assert((test1 != test2) == true);
}