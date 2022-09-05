#define _CRT_SECURE_NO_WARNINGS
#include <iostream>

#define MAXSIZE 100

typedef struct
{
    char no[20];
    char name[50];
    float price;
}Book;

typedef struct LNode
{
    Book elem;
    struct LNode* next;
}LNode,*LinkList;

bool InitList(LinkList& L)
{
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    return true;
}

bool GetElem(LinkList L, int i, Book& book)
{
    int j = 1;
    LNode* p = L->next;
    while (p && j < i)
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i) return false;
    book = p->elem;
    return true;
}

LNode* LocateElem(LinkList L, Book book)
{
    LNode* p = L->next;
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

bool ListInsert(LinkList& L, int i, Book book)
{
    int j = 0;
    LNode* p = L;
    while (p && (j < i - 1))
    {
        p = p->next;
        ++j;
    }
    if (!p || j > i - 1) return false;
    LNode* s = (LNode*)malloc(sizeof(LNode));
    s->elem = book;
    s->next = p->next;
    p->next = s;
    return true;
}

bool ListDelete(LinkList& L, int i)
{
    int j = 0;
    LNode* p = L;
    while ((p->next) && (j < i - 1))
    {
        p = p->next;
        ++j;
    }
    if (!(p->next) || (j > i - 1)) return false;
    LNode* q = p->next;
    p->next = p->next->next;
    free(q);
    q = NULL;
    return true;
}

void CreateList_H(LinkList& L, int n)
{
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = 0; i < n; ++i)
    {
        LNode* p = (LNode*)malloc(sizeof(LNode));
        scanf("%s %s %f", &p->elem.no,&p->elem.name,&p->elem.price);
        p->next = L->next;
        L->next = p;
    }
}

void CreateList_R(LinkList& L, int n)
{
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    LNode* r = L;
    for (int i = 0; i < n; ++i)
    {
        LNode* p = (LNode*)malloc(sizeof(LNode));
        scanf("%s %s %f", &p->elem.no, &p->elem.name, &p->elem.price);
        p->next = NULL;
        r->next = p;
        r = p;
    }
}

bool FreeList(LinkList& L)
{
    free(L);
    L = NULL;
    return true;
}