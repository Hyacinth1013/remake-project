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

int main()
{
	////[TEST] InitQueue
	//SqQueue sq;
	//InitQueue(sq);

	////[TEST] QueueLength
	//Book b1 = { "001","小王子",18 };
	//Book b2 = { "002","情人",20 };
	//int length = QueueLength(sq);
	//printf("%d\n", length);

	////[TEST] EnQueue
	//EnQueue(sq, b1);
	//EnQueue(sq, b2);
	//length = QueueLength(sq);
	//printf("%d\n", length);
	//
	////[TEST] DeQueue
	//Book b3 = {};
	//DeQueue(sq, b3);
	//printf("%s %s %.0f\n", b3.no, b3.name, b3.price);

	////[TEST] GetHead
	//Book b4 = GetHead(sq);
	//printf("%s %s %.0f\n", b4.no, b4.name, b4.price);

	return 0;
}