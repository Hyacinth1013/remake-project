#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MAXSIZE 100

typedef struct
{
	char no[20];
	char name[50];
	float price;
}Book;

typedef struct DuLNode
{
	Book elem;
	struct DuLNode* prior;
	struct DuLNode* next;
}DuLNode,*DuLinkList;

void CreateList(DuLinkList& L, int n)
{
	L = (DuLNode*)malloc(sizeof(DuLNode));
	if (L == NULL) return;
	L->prior = NULL;
	L->next = NULL;
	DuLNode* r = L;
	for (int i = 0; i < n; ++i)
	{
		DuLNode* p = (DuLNode*)malloc(sizeof(DuLNode));
		if (p == NULL) return;
		scanf("%s %s %f", &p->elem.no, &p->elem.name, &p->elem.price);
		p->next = NULL;
		p->prior = r;
		r->next = p;
		r = p;
	}
}

int ListLength(DuLinkList& L)
{
	int length = 0;
	DuLNode* p = L;
	while (p->next)
	{
		++length;
		p = p->next;
	}
	return length;
}

bool GetElem(DuLinkList L, int i, Book& book)
{
	int j = 1;
	DuLNode* p = L->next;
	while (p && j < i)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i) return false;
	book = p->elem;
	return true;
}

DuLNode* LocateElem(DuLinkList& L, Book book)
{
	int j = 1;
	DuLNode* p = L->next;
	while (p)
	{
		if (*p->elem.no == *book.no &&
			*p->elem.name == *book.name &&
			 p->elem.price == book.price)
		{
			return p;
		}
		p = p->next;
	}
	return NULL;
}

bool ListInsert(DuLinkList& L, int i, Book book)
{
	int j = 0;
	DuLNode* p = L->next;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return false;
	DuLNode* s = new DuLNode;
	s->elem = book;
	s->prior = p->prior;
	p->prior->next = s;
	s->next = p;
	p->prior = s;
	return true;
}

bool ListDelete(DuLinkList& L, int i)
{
	int j = 0;
	DuLNode* p = L->next;
	while (p && j < i - 1)
	{
		p = p->next;
		++j;
	}
	if (!p || j > i - 1) return false;
	p->prior->next = p->next;
	p->next->prior = p->prior;
	delete p;
	return true;
}