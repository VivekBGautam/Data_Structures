#include<stdio.h>
#include<stdlib.h>


#pragma pach(1)
struct node
{
    int data;
    struct node *next;
    struct node *prev;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Displays all elements of the singly linked list.
//  Input         : PNODE first  →  Pointer to the first node of the linked list
//                  PNODE last  →  Pointer to the last node of the linked list
//  Output        : Prints all node data on screen
//  Author        : Vivek Bhauraj Gautam
//  Date          : 22/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void Display(PNODE first, PNODE last)
{
    printf(" <=> ");
    do
    {
        printf("| %d | <=> ",first->data);
        first = first->next;

    } while( first != last->next);

    printf("\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Counts the total number of nodes present in the linked list.
//  Input         : PNODE first  →  Pointer to the first node of the linked list
//                  PNODE last  →  Pointer to the last node of the linked list
//  Output        : Returns integer count of nodes
//  Author        : Vivek Bhauraj Gautam
//  Date          : 22/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    do
    {
        iCount++;
        first = first->next;

    } while( first != last->next);

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
//  Date          : 22/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == *last)             // LL is empty
    {
        *first = newn;
        *last = newn;
    }
    else                            // LL contain one or more
    {
        newn->next = *first;
        (*first)->prev = newn;
        *first = newn;

    }

    (*last)->next = *first;
    (*first)->prev = *last;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : Inserts a new node at the end of the linked list.
//  Input         : PPNODE first → Address of first pointer
//                  PPNODE last → Address of last pointer
//                  int no        → Data to be inserted in the node
//  Output        : Modifies linked list by adding new node at last position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 22/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertLast(PPNODE first, PPNODE last, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(*first == *last)             // LL is empty
    {
        *first = newn;
        *last = newn;
    }
    else                            // LL contain one or more
    {
    

    }

    (*last)->next = *first;
    (*first)->prev = *last;
}

void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{}

void DeleteFirst(PPNODE first, PPNODE last)
{}

void DeleteLast(PPNODE first, PPNODE last)
{}

void DeleteAtPos(PPNODE first, PPNODE last,int pos)
{}


// Segmentation fault due to display and count
int main()
{
    int iRet = 0;

    PNODE head = NULL;
    PNODE tail = NULL;

    // InsertFirst(&head,&tail,51);
    // InsertFirst(&head,&tail,21);
    // InsertFirst(&head,&tail,11);

    Display(head,tail);

    iRet = Count(head,tail);

    printf("Total node in Linked list is : %d\n",iRet);

    return 0;
}