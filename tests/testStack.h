#ifndef TEST_STACK_H
#define TEST_STACK_H

#include <assert.h>
#include "../Stack.h"

int MapFunc(int i);

int ReduceFunc(int a, int b);

bool WhereFunc(int a);

void testStackConstructors();

void testStackIsEmpty();

void testStackPeek();

void testStackTop();

void testStackPush();

void testStackMap();

void testStackReduce();

void testStackWhere();

void testStackConcat();

void testGetSubStack();

void testIsSubStackHere();

#endif