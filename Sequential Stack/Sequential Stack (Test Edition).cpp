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

int main()
{
	////[TEST] InitStack
	//SqStack St;
	//InitStack(St);

	////[TEST] Push
	//Book b1 = { "001","小王子",18 };
	//Book b2 = { "002","情人",20 };
	//Push(St, b1);
	//Push(St, b2);

	////[TEST] Pop
	//Book b3 = {};
	//Pop(St, b3);
	//printf("%s %s %.0f\n", b3.no, b3.name, b3.price);

	////[TEST] GetTop
	//Book b4 = GetTop(St);
	//printf("%s %s %.0f\n", b4.no, b4.name, b4.price);

	return 0;
}