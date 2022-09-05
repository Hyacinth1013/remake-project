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
    Book* elem;
    int length;
}SqList;

bool InitList(SqList& L)
{
    L.elem = (Book*)malloc(sizeof(Book) * MAXSIZE);
    if (!L.elem) exit(OVERFLOW);
    L.length = 0;
    return true;
}

bool GetElem(SqList L, int i, Book& book)
{
    if (i<1 || i>L.length) return false;
    book = L.elem[i - 1];
    return true;
}

int LocateElem(SqList L, Book book)
{
    for (int i = 0; i < L.length; i++)
    {
        if (*L.elem[i].no == *book.no && 
            *L.elem[i].name == *book.name && 
             L.elem[i].price == book.price)
        {
            return i + 1;
        }
    }
    return 0;
}

bool ListInsert(SqList& L, int i, Book book)
{
    if ((i < 1) || (i > L.length + 1)) return false;
    if (L.length == MAXSIZE) return false;
    for (int j = L.length - 1; j >= i - 1; j--)
    {
        L.elem[j + 1] = L.elem[j];
    }
    L.elem[i - 1] = book;
    ++L.length;
    return true;
}

bool ListDelete(SqList& L, int i)
{
    if ((i < 1) || (i > L.length)) return false;
    for (int j = i; j <= L.length - 1; j++)
        L.elem[j - 1] = L.elem[j];
    --L.length;
    return true;
}

void FreeList(SqList L)
{
    free(L.elem);
    L.elem = NULL;
}