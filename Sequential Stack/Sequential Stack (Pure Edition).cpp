#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MAXSIZE 100

typedef struct
{
	char no[20];
	char name[50];
	float price;
}Book;

typedef struct
{
	Book* base;
	Book* top;
	int stacksize;
}SqStack;

bool InitStack(SqStack& S)
{
	S.base = new Book[MAXSIZE];
	if (!S.base) exit(OVERFLOW);
	S.top = S.base;
	S.stacksize = MAXSIZE;
	return true;
}

bool Push(SqStack& S, Book& book)
{
	if (S.top - S.base == S.stacksize) return false;
	*S.top++ = book;
	return true;
}

bool Pop(SqStack& S, Book& book)
{
	if (S.top == S.base) return false;
	book = *--S.top;
	return true;
}

Book GetTop(SqStack S)
{
	if (S.top != S.base)
	{
		return *(S.top - 1);
	}
}