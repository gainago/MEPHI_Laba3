#ifndef TEST_STACK_H
#define TEST_STACK_H

#include <assert.h>
#include "../Stack.h"

int MapFunc(int i)
{
    return i * i;
}

int ReduceFunc(int a, int b)
{
    return a + b;
}

bool WhereFunc(int a)
{
    return a % 2 == 0;
}

void testStackConstructors()
{
    int items[4] = {1, 2, 3, 4};
    Stack<int> test1(items, 4);
    Stack<int> test2(test1);
    for (int i = 3; i >= 0; i--)
    {
        assert(test1.Peek(i) == items[i]);
    }
    for (int i = 3; i >= 0; i--)
    {
        assert(test2.Peek(i) == items[i]);
    }
}

void testStackIsEmpty()
{
    int items[4] = {1, 2, 3, 4};
    Stack<int> test1(items, 4);
    Stack<int> test2;
    assert(test1.IsEmpty() == false);
    assert(test2.IsEmpty() == true);
}

void testStackPeek()
{
    int items[4] = {1, 2, 3, 4};
    Stack<int> test1(items, 4);
    for (int i = 3; i >= 0; i--)
    {
        assert(test1.Peek(i) == items[i]);
    }
}

void testStackTop()
{
    int items[4] = {1, 2, 3, 4};
    Stack<int> test1(items, 4);
    assert(test1.Top() == items[3]);
}

void testStackPush()
{
    int items[4] = {1, 2, 3, 4};
    Stack<int> test1(items, 4);
    test1.Push(12);
    assert(test1.GetSize() == 5);
    assert(test1.Top() == 12);
}

void testStackMap()
{
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[8] = {1, 4, 9, 16, 25, 36, 49, 64};
    Stack<int> test1(a, 8);
    Stack<int> *test2 = test1.Map(&MapFunc);
    assert(test1.GetSize() == test2->GetSize());
    for (int i = 7; i >= 0; i--)
    {
        assert(test2->Peek(i) == b[i]);
    }
}

void testStackReduce()
{
    int a[8] = {1, 2, 3, 4, 5, 6, 7, 8};
    Stack<int> test1(a, 8);
    int res = test1.Reduce(&ReduceFunc, 0);
    assert(res == 36);
}

void testStackWhere()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {2, 4, 6, 8};
    Stack<int> test1(a, 8);
    Stack<int> *test2 = test1.Where(&WhereFunc);
    assert(test1.GetSize() != test2->GetSize());
    for (int i = 3; i >= 0; i--)
    {
        assert(test2->Peek(i) == b[i]);
    }
}

void testStackConcat()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {2, 4, 6, 8};
    int c[] = {1, 2, 3, 4, 5, 6, 7, 8, 2, 4, 6, 8};
    Stack<int> test1(a, 8);
    Stack<int> test2(b, 4);
    test1.Concat(test2);
    assert(test1.GetSize() == 8 + 4);
    for (int i = 11; i >= 0; i--)
    {
        assert(test1.Peek(i) == c[i]);
    }
}

void testGetSubStack()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    Stack<int> test1(a, 8);
    Stack<int> *test2 = test1.GetSubStack(0, 3);
    assert(test2->GetSize() == 4);
    for (int i = 3; i >= 0; i--)
    {
        assert(test2->Peek(i) == a[i]);
    }
}

void testIsSubStackHere()
{
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int b[] = {2, 3, 4};
    Stack<int> test1(a, 8);
    Stack<int> test2(b, 3);
    assert(test1.IsSubStackHere(test2) == true);
}

#endif
