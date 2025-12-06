#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node 
{
    int data;
    struct note *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

// Call By Value
void Display(PNODE first)
{}

int Count(PNODE first)
{
    return 0;
}

// Call By Address

void InserFirst(PPNODE fisrt, int no)
{}

void InsertLast(PPNODE fisrt, int no)
{}

void InsertAtPos(PPNODE fisrt, int no, int pos)
{}

void DeleteFisrt(PPNODE fisrt)
{}

void DeleteLast(PPNODE first)
{}

void DeleteAtPos(PPNODE first, int pos)
{}

int main()
{
    PNODE head = NULL;

    Display(head);

    Count(head);

    InserFirst(&head,11);
    InsertLast(&head,21);
    InsertAtPos(&head,51,5);

    DeleteFisrt(&head);
    DeleteLast(&head);
    DeleteAtPos(&head,5);


    return 0;
}