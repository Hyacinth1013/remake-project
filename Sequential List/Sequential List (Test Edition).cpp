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
        ////[TEST] "=="
        //printf("%s == %s\n", L.elem[i].no, book.no);
        //printf("%s == %s\n", L.elem[i].name, book.name);
        //printf("%f == %f\n", L.elem[i].price, book.price);
        //if (L.elem[i].no == book.no) printf("1 working\n");
        //if (L.elem[i].name == book.name) printf("2 working\n");
        //if (L.elem[i].price == book.price) printf("3 working\n");
        
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

int main()
{
    ////[TEST] InitList
    //SqList L;
    //InitList(L);
    //printf("Length: %d\n", L.length);
    //printf("--------------------\n");

    ////[TEST] ListInsert
    //Book b2 = { "002","Ulysses",35 };
    //ListInsert(L, 1, b2);
    //Book b1 = { "001","Castle",20 };
    //ListInsert(L, 1, b1);
    //Book b3 = { "003","Lolita",99 };
    //ListInsert(L, 3, b3);
    //printf("Length: %d\n", L.length);
    //printf("--------------------\n");

    ////[TEST] GetElem
    //Book b7;
    //bool flag = GetElem(L, 2, b7);
    //printf("%s %s %.1f\n", b7.no, b7.name, b7.price);
    //printf("--------------------\n");

    ////[Test] LocateElem
    //int num = LocateElem(L, b2);
    //printf("Position: %d\n", num);
    //printf("--------------------\n");

    ////[TEST] Delete
    //ListDelete(L, 1);
    //printf("Length: %d\n", L.length);
    //printf("--------------------\n");

    ////[TEST] Output
    //for (int i = 0; i < L.length; i++)
    //{
    //    printf("%s %s %.1f", L.elem[i].no, L.elem[i].name, L.elem[i].price);
    //    printf("\n");
    //}
    //printf("--------------------\n");

    //////[TEST] FreeList
    ////FreeList(L);
    ////printf("%s %s %.0f\n", L.elem[0].no, L.elem[0].name, L.elem[0].price);

    return 0;
}