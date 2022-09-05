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

int main()
{
	////[TEST] Push
	//LinkStack ls;
	//Book b1 = { "001","小王子",18 };
	//Book b2 = { "002","情人",20 };
	//Push(ls, b1);
	//Push(ls, b2);

	////[TEST] Pop
	//Book b3 = {};
	//Pop(ls, b3);
	//printf("%s %s %.0f\n", b3.no, b3.name, b3.price);

	////[TEST] GetTop
	//Book b4 = GetTop(ls);
	//printf("%s %s %.0f\n", b4.no, b4.name, b4.price);
	//
	////[TEST] Free
	//Free(ls);
	//printf("%s %s %.0f\n", ls[0].book.no, ls[0].book.name, ls[0].book.price);

	return 0;
}