#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

typedef struct
{
	char no[20];
	char name[50];
	float price;
}Book;

typedef struct QNode
{
	Book elem;
	struct QNode* next;
}QNode, *QueuePtr;

typedef struct
{
	QueuePtr front;
	QueuePtr rear;
}LinkQueue;

bool InitQueue(LinkQueue& Q)
{
	Q.front = Q.rear = new QNode;
	Q.front->next = NULL;
	return true;
}

bool EnQueue(LinkQueue& Q, Book book)
{
	QNode* p = new QNode;
	p->elem = book;
	p->next = NULL;
	Q.rear->next = p;
	Q.rear = p;
	return true;
}

bool DeQueue(LinkQueue& Q, Book& book)
{
	if (Q.front == Q.rear) return false;
	QNode* p = Q.front->next;
	book = p->elem;
	Q.front->next = p->next;
	if (Q.rear == p) Q.rear = Q.front;
	delete p;
	return true;
}

Book GetHead(LinkQueue Q)
{
	if (Q.front != Q.rear)
	{
		return Q.front->next->elem;
	}
}