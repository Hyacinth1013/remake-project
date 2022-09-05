#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MAXQSIZE 100

typedef struct
{
	char no[20];
	char name[50];
	float price;
}Book;

typedef struct
{
	Book* base;
	int front;
	int rear;
}SqQueue;

bool InitQueue(SqQueue& Q)
{
	Q.base = new Book[MAXQSIZE];
	if (!Q.base) exit(OVERFLOW);
	Q.front = Q.rear = 0;
	return true;
}

int QueueLength(SqQueue Q)
{
	return (Q.rear - Q.front + MAXQSIZE) % MAXQSIZE;
}

bool EnQueue(SqQueue& Q, Book book)
{
	if ((Q.rear + 1) % MAXQSIZE == Q.front)
	{
		return false;
	}
	Q.base[Q.rear] = book;
	Q.rear = (Q.rear + 1) % MAXQSIZE;
	return true;
}

bool DeQueue(SqQueue& Q, Book& book)
{
	if (Q.front == Q.rear) return false;
	book = Q.base[Q.front];
	Q.front = (Q.front + 1) % MAXQSIZE;
	return true;
}

Book GetHead(SqQueue Q)
{
	if (Q.front != Q.rear)
	{
		return Q.base[Q.front];
	}
}