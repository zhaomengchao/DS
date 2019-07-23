#pragma once
#include<stdio.h>
#include<assert.h>
#include<stdlib.h>
#include<stdbool.h>

typedef int STDataType;
typedef struct Stack
{
	STDataType* _a;
	int _top;
	int _capacity;
}Stack;

void StackInit(Stack* ps);
void StackDestory(Stack* ps);
void StackPush(Stack* ps, STDataType x);
void StackPop(Stack* ps);
STDataType StackTop(Stack* ps);
bool StackEmpty(Stack* ps);
int StackSize(Stack* ps);




void StackInit(Stack* ps)
{
	assert(ps);
	ps->_a = NULL;
	ps->_capacity = ps->_top = 0;
}

void StackDestory(Stack* ps)
{
	assert(ps);
	ps->_capacity = ps->_top = 0;
	free(ps->_a);
}
void StackPush(Stack* ps, STDataType x)
{
	assert(ps);
	if (ps->_capacity == ps->_top)
	{
		size_t newsize = (ps->_capacity == 0) ? 2 : 2 * ps->_capacity;
		ps->_a = realloc(ps->_a, sizeof(STDataType)*newsize);
		ps->_capacity = newsize;
	}
	ps->_a[ps->_top] = x;
	ps->_top++;
}
void StackPop(Stack* ps)
{
	assert(ps && ps->_top > 0);
	if (ps->_top != 0)
		ps->_top--;
}
STDataType StackTop(Stack* ps)
{
	assert(ps && ps->_top != 0);
	return ps->_a[ps->_top - 1];
}
bool StackEmpty(Stack* ps)
{
	assert(ps);
	if (ps->_top == 0)
		return true;
	else
		return false;
}
int StackSize(Stack* ps)
{
	assert(ps);
	return ps->_top;
}
void Teststack1()
{
	Stack s;
	StackInit(&s);
	StackPush(&s, 1);
	StackPush(&s, 2);
	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	StackPush(&s, 3);
	StackPush(&s, 4);
	while (!StackEmpty(&s))
	{
		printf("%d ", StackTop(&s));
		StackPop(&s);
	}
	printf("\n");
	//StackDestory(&s);
}