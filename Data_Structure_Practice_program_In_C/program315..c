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

// Call By Value

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Displays all elements of the singly linked list.
//  Input         : PNODE first  →  Pointer to the first node of the linked list
//  Output        : Prints all node data on screen
//  Author        : Vivek Bhauraj Gautam
//  Date          : 05/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////

void Display(PNODE first)
{
    while(first != NULL)
    {
        printf("%d\t",first->data);
        first = first -> next;
    }
    printf("\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Counts the total number of nodes present in the linked list.
//  Input         : PNODE first  →  Pointer to the first node of the linked list
//  Output        : Returns integer count of nodes
//  Author        : Vivek Bhauraj Gautam
//  Date          : 05/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////


int Count(PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first -> next;
    }
    
    return iCount;
}

// Call By Address

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertFirst
//  Description   : Inserts a new node at the beginning of the linked list.
//  Input         : PPNODE first → Address of first pointer
//                  int no        → Data to be inserted in the node
//  Output        : Modifies linked list by adding new node at first position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 05/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////

void InserFirst(PPNODE fisrt, int no)
{}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : Inserts a new node at the end of the linked list.
//  Input         : PPNODE first → Address of first pointer
//                  int no        → Data to be inserted in the node
//  Output        : Modifies linked list by adding new node at last position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 05/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertLast(PPNODE fisrt, int no)
{}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Description   : Inserts a new node at a specific position in the linked list.
//  Input         : PPNODE first → Address of first pointer
//                  int no        → Data to be inserted
//                  int pos       → Position where node is to be inserted
//  Output        : Modifies linked list by placing new node at desired position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 05/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////

void InsertAtPos(PPNODE fisrt, int no, int pos)
{}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : Deletes the first node of the linked list.
//  Input         : PPNODE first → Address of first pointer
//  Output        : Removes first node and frees its memory
//  Author        : Vivek Bhauraj Gautam
//  Date          : 05/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteFisrt(PPNODE fisrt)
{}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : Deletes the last node of the linked list.
//  Input         : PPNODE first → Address of first pointer
//  Output        : Removes last node and frees its memory
//  Author        : Vivek Bhauraj Gautam
//  Date          : 05/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////

void DeleteLast(PPNODE first)
{}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : Deletes a node from a specific position in the linked list.
//  Input         : PPNODE first → Address of first pointer
//                  int pos       → Position of the node to be deleted
//  Output        : Removes node from given position and frees its memory
//  Author        : Vivek Bhauraj Gautam
//  Date          : 05/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////

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