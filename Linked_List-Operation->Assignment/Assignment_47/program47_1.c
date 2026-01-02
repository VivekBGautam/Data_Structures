// Q - Write a program which Display linked list in reverse oredr.

////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Required header File
//
////////////////////////////////////////////////////////////////////////////////////////////////////
#include<stdio.h>
#include<stdlib.h>

struct node 
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DisplayReverse
//  Description   : Displays all elements of the singly linked list in reverse order.
//  Input         : PNODE first  →  Pointer to the first node of the linked list
//  Output        : Prints all node data on screen in reverse order
//  Author        : Vivek Bhauraj Gautam
//  Date          : 29/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void DisplayReverse(PNODE first)
{
    int iCount = 0;
    int iCnt = 0;
    PNODE temp = NULL;

    temp = first;

    if(first == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }

    printf(" NULL ->");

    DisplayReverse(first->next);
    printf("| %d | ->", first->data);
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Counts the total number of nodes present in the linked list.
//  Input         : PNODE first  →  Pointer to the first node of the linked list
//  Output        : Returns integer count of nodes
//  Author        : Vivek Bhauraj Gautam
//  Date          : 29/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    printf("\n");
    return iCount;
}
////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Inserts a new node at the beginning of the linked list.
//  Input         : PPNODE first → Address of first pointer
//                  int no        → Data to be inserted in the node
//  Output        : Modifies linked list by adding new node at first position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 29/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    if(newn == NULL)
    {
        return;
    }

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)
    {
        *first = newn;
    }
    else 
    {
        newn->next = *first;
        *first = newn;
    }
}



////////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Entry Point Function (main)
// Description   : It is user to demonstrate the Deffrent opration on Linked list
// Date          : 29/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    int iRet = 0;
    PNODE head = NULL;

    InsertFirst(&head,241);
    InsertFirst(&head,240);
    InsertFirst(&head,311);
    InsertFirst(&head,231);
    InsertFirst(&head,110);

    DisplayReverse(head);
    iRet = Count(head);
    printf("Total node in Linked list is : %d \n",iRet);

    while(head != NULL)
    {
        PNODE temp = head;
        head = head->next;
        free(temp);
    }

    head = NULL;

    return 0;
}