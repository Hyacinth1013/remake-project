#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MAXSIZE 100

typedef struct
{
	char no[20];
	char name[50];
	float price;
}Book;

typedef struct StackNode
{
	Book book;
	struct StackNode* next;
}StackNode, * LinkStack;

bool Push(LinkStack& S, Book book)
{
	StackNode* p = new StackNode;
	p->book = book;
	p->next = S;
	S = p;
	return true;
}

bool Pop(LinkStack& S, Book& book)
{
	if (S == NULL) return false;
	book = S->book;
	StackNode* p = S;
	S = S->next;
	delete p;
	return true;
}

Book GetTop(LinkStack S)
{
	if (S != NULL)
	{
		return S->book;
	}
}

bool Free(LinkStack& S)
{
	delete S;
	return true;
}