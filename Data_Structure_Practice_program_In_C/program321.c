#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)                     // To Avoide padding
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;


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

void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)                  // LL is empty
    {
        (*first) = newn;
    }
    else                                // LL is contain at least one node
    {
        newn->next = (*first);
        (*first) = newn;
    }

}

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

void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;

    if(*first == NULL)                  // LL is empty
    {
        *first = newn;
    }
    else                                // LL is contain at least one node
    {
        temp = *first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

}

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

void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;

    if((*first) == NULL)          // Case 1
    {
        return;
    }
    else if((*first)->next == NULL)             // Case 2
    {
        free(*first);
        *first = NULL;
    }
    else                                // Case #
    {
        temp = *first;
        *first = (*first)->next;
        free(temp);
    }
}

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
{
    PNODE temp = NULL;
    temp = *first;

    if((*first) == NULL)          // Case 1
    {
        return;
    }
    else if((*first)->next == NULL)             // Case 2
    {
        free(*first);
        *first = NULL;
    }
    else                                   // Case 3
    {
        // temp = *first;
        
        // while(temp)
    }
}

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
        printf("| %d |->",first->data);
        first = first->next; 
    }
    printf("NULL\n");
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

int Count (PNODE first)
{
    int iCount = 0;

    while(first != NULL)
    {
        iCount++;
        first = first->next;
    }

    return iCount;
}

int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 75);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    Display(head);

    iRet = Count(head);

    printf("Number of Nodes are : %d\n",iRet);

    InsertLast(&head, 101);
    InsertLast(&head, 111);
    InsertLast(&head, 151);

    Display(head);

    iRet = Count(head);

    printf("Number of Nodes are : %d\n",iRet);

    DeleteFirst(&head);

    Display(head);

    iRet = Count(head);

    printf("Number of Nodes are : %d\n",iRet);


    return 0;
}