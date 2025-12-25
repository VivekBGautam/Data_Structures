#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

void Display(PNODE first, PNODE last)
{}

int Count(PNODE fiirst, PNODE last)
{
    int iCount = 0;

    return iCount;
}

void InsertFirst(PPNODE first, PPNODE last, int no)
{

}

void InsertLast(PPNODE first, PPNODE last, int no)
{
    
}

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    
}

void DeleteFirst(PPNODE first, PPNODE last)
{

}

void DeleteLast(PPNODE first, PPNODE last)
{
    
}

void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
    
}

int main()
{
    PNODE head = NULL;
    PNODE tail = NULL;

    return 0;
}