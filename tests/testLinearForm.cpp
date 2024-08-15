#ifndef TEST_LINEAR_FORM_H
#define TEST_LINEAR_FORM_H

#include <assert.h>
#include "../LinearForm.h"

void testLinearFormConstructors()
{
    int items[4] = {1, 2, 3, 4};
    LinearForm<int> test1(items, 4);
    assert(test1.GetSize() == 4);
    for (int i = 0; i < 4; i++)
    {
        assert(test1[i] == items[i]);
    }
    LinearForm<int> test2(test1);
    assert(test2.GetSize() == 4);
    for (int i = 0; i < 4; i++)
    {
        assert(test2[i] == items[i]);
    }
}

void testLinearFormSum()
{
    int items1[4] = {1, 7, 2, 4};
    int items2[4] = {0, 1, 1, 10};
    LinearForm<int> test1(items1, 4);
    LinearForm<int> test2(items2, 4);
    LinearForm<int> *test3 = test1.Sum(test2);
    assert(test3->GetSize() == test1.GetSize());
    for (int i = 0; i < 4; i++)
    {
        assert((*test3)[i] == (test1[i] + test2[i]));
    }
}

void testLinearFormSubtract()
{
    int items1[4] = {1, 7, 2, 4};
    int items2[4] = {0, 1, 1, 10};
    LinearForm<int> test1(items1, 4);
    LinearForm<int> test2(items2, 4);
    LinearForm<int> *test3 = test1.Subtract(test2);
    assert(test3->GetSize() == test1.GetSize());
    for (int i = 0; i < 4; i++)
    {
        assert((*test3)[i] == (test1[i] - test2[i]));
    }
}

void testLinearFormMultiOnScalar()
{
    int items[4] = {1, 3, 1, 1};
    int scalar = 7;
    LinearForm<int> test1(items, 4);
    LinearForm<int> *test2 = test1.MultiOnScalar(7);
    assert(test2->GetSize() == test1.GetSize());
    for (int i = 0; i < 4; i++)
    {
        assert((*test2)[i] == test1[i] * scalar);
    }
}

void testLinearFormCalcValue()
{
    int items[4] = {1, 7, 2, 4};
    int values[4] = {0, 1, 1, 10};
    LinearForm<int> test(items, 4);
    int result = test.CalcValue(values);
    assert(result == (0 + 7 + 2 + 40));
}

void testLinearFormOperators()
{
    int items1[4] = {1, 7, 2, 4};
    int items2[4] = {0, 1, 1, 10};
    LinearForm<int> test1(items1, 4);
    LinearForm<int> test2(items2, 4);
    LinearForm<int> *test3 = test1 + test2;
    assert(test3->GetSize() == test1.GetSize());
    for (int i = 0; i < 4; i++)
    {
        assert((*test3)[i] == (test1[i] + test2[i]));
    }
    LinearForm<int> *test4 = test1 * 7;
    assert(test4->GetSize() == test1.GetSize());
    for (int i = 0; i < 4; i++)
    {
        assert((*test4)[i] == (test1[i] * 7));
    }
    LinearForm<int> *test5 = test1 - test2;
    assert(test5->GetSize() == test1.GetSize());
    for (int i = 0; i < 4; i++)
    {
        assert((*test5)[i] == (test1[i] - test2[i]));
    }
    assert((test1 == test2) == false);
    assert((test1 != test2) == true);
}

#endif
