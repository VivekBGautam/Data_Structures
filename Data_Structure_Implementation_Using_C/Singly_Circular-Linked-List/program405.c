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

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Inserts a new node at the beginning of the linked list.
//  Input         : PPNODE first → Address of first pointer
//                  PPNODE last  → Address of last pointer
//                  int no       → Data to be inserted in the node
//  Output        : Modifies linked list by adding new node at first position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 19/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first == NULL) && (*last == NULL))   // @
    {
        *first = newn;
        *last = newn;
    }
    else
    {
        newn->next = *first;
        *first = newn;
    }

    (*last)->next = *first;             // @ maintain circular nature
}

void InsertLast(PPNODE first, PPNODE last, int no)   // @
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if((*first == NULL) && (*last == NULL))
    {
        *first = newn;
        *last = newn;
    }
    else
    {

    }

    (*last)->next = *first;                 // @ maintain circular nature
    
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

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    return 0;
}