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

void CreateList_H(LinkList& L, int n)
{
    L = (LNode*)malloc(sizeof(LNode));
    L->next = NULL;
    for (int i = 0; i < n; ++i)
    {
        LNode* p = (LNode*)malloc(sizeof(LNode));
        scanf("%s %s %f", &p->elem.no, &p->elem.name, &p->elem.price);
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

int ListLength(LinkList& L)
{
    int length = 0;
    LNode* p = L;
    while (p->next)
    {
        ++length;
        p = p->next;
    }
    return length;
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

bool FreeList(LinkList& L)
{
    free(L);
    L = NULL;
    return true;
}

int main()
{
    ////[TEST] InitList
    //LinkList L;
    //InitList(L);

    ////[TEST] CreateList_H
    //CreateList_H(L, 3);
    //printf("--------------------\n");

    ////[TEST] CreateList_R
    //CreateList_R(L, 3);
    //printf("--------------------\n");

    ////[TEST] ListLength
    //int length = ListLength(L);
    //printf("Length: %d\n", length);
    //printf("--------------------\n");

    ////[TEST] ListInsert
    //Book b1 = { "004","Ulysses",18 };
    //ListInsert(L, 4, b1);
    //length = ListLength(L);
    //printf("Length: %d\n", length);
    //printf("--------------------\n");

    ////[TEST] ListDelete
    //ListDelete(L, 2);
    //length = ListLength(L);
    //printf("Length: %d\n", length);
    //printf("--------------------\n");

    ////[TEST] GetElem
    //Book temp_Get;
    //bool flag = GetElem(L, 2, temp_Get);
    //printf("%s %s %.0f\n", temp_Get.no, temp_Get.name, temp_Get.price);
    //printf("--------------------\n");

    ////[TEST] LocateElem
    //Book temp_Locate = { "004","Ulysses",18 };
    //LNode* node = LocateElem(L, temp_Locate);
    //printf("%s %s %.0f\n", node->elem.no, node->elem.name, node->elem.price);
    //printf("--------------------\n");

    ////[TEST] Output
    //LNode* temp_Out = L;
    //while (temp_Out->next)
    //{
    //    temp_Out = temp_Out->next;
    //    printf("%s %s %.1f\n", temp_Out->elem.no, temp_Out->elem.name, temp_Out->elem.price);
    //}
    //printf("--------------------\n");

    //////[TEST] FreeList
    ////FreeList(L);
    ////printf("%s %s %.1f\n", L->elem.no, L->elem.name, L->elem.price);

    return 0;
}