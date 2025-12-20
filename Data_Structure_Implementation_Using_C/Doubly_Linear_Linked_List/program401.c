#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)                     // To Avoide padding
struct node
{
    int data;
    struct node *next;
    struct node *prev;             // $
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

// Call By Value

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Displays all elements of the Doubly linear linked list.
//  Input         : PNODE first  →  Pointer to the first node of the linked list
//  Output        : Prints all node data on screen
//  Author        : Vivek Bhauraj Gautam
//  Date          : 18/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void Display(PNODE first)
{
    printf("\nNULL <=> ");
    while(first != NULL)
    {
        printf("| %d | <=>", first->data);
        first = first->next;
    }

    printf(" NULL\n");
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Count
//  Description   : Counts the total number of nodes present in the linked list.
//  Input         : PNODE first  →  Pointer to the first node of the linked list
//  Output        : Returns integer count of nodes
//  Author        : Vivek Bhauraj Gautam
//  Date          : 18/12/2025
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
//  Date          : 18/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE first, int no)
{
    PNODE newn = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;          //$

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        newn->next = *first;
        (*first)->prev = newn;          // $
        *first = newn;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : Inserts a new node at the end of the linked list.
//  Input         : PPNODE first  → Address of first pointer
//                  int no        → Data to be inserted in the node
//  Output        : Modifies linked list by adding new node at last position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 18/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertLast(PPNODE first, int no)
{
    PNODE newn = NULL;
    PNODE temp = NULL;

    newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;          // $

    if(*first == NULL)
    {
        *first = newn;
    }
    else
    {
        temp = *first;

        while(temp ->next != NULL)      // Type 2
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;              // $

    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Description   : Inserts a new node at a specific position in the linked list.
//  Input         : PPNODE first  → Address of first pointer
//                  int no        → Data to be inserted
//                  int pos       -> Position where node is to be inserted
//  Output        : Modifies linked list by placing new node at desired position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 18/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE first, int no, int pos)
{
    int iSize = 0;
    int iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;

    iSize = Count(*first);

    if((pos < 1) || (pos > iSize + 1))
    {
        printf("Invalid POsition\n");
        return;
    }
    
    if(*first == NULL)
    {
        InsertFirst(first, no);
    }
    else if(pos == iSize + 1)
    {
        InsertLast(first, no);
    }
    else
    {
        temp = *first;

        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;          // $

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        newn->prev = temp;
        
        temp->next->prev = newn;
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
//  Date          : 18/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE first)
{
    PNODE temp = NULL;
    
    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        *first = (*first)->next;
        free(temp);
        (*first)->prev = NULL;          // $

    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : Deletes the last node of the linked list.
//  Input         : PPNODE first → Address of first pointer
//  Output        : Removes last node and frees its memory
//  Author        : Vivek Bhauraj Gautam
//  Date          : 18/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteLast(PPNODE first)
{
    PNODE temp = NULL;

    if(*first == NULL)
    {
        return;
    }
    else if((*first)->next == NULL)
    {
        free(*first);
        *first = NULL;
    }
    else
    {
        temp = *first;

        while(temp->next->next != NULL)         // Type 3
        {
            temp = temp->next;
        }

        free(temp->next);
        temp->next = NULL;

    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : Deletes a node from a specific position in the linked list.
//  Input         : PPNODE first → Address of first pointer
//                  int pos       → Position of the node to be deleted
//  Output        : Removes node from given position and frees its memory
//  Author        : Vivek Bhauraj Gautam
//  Date          : 18/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE first, int pos)
{
    int iSize = 0;
    int iCnt = 0;
    PNODE newn = NULL;
    PNODE temp = NULL;
    PNODE target = NULL;

    iSize = Count(*first);

    if((pos < 1) || (pos > iSize))
    {
        printf("Invalid POsition\n");
        return;
    }
    
    if(pos == 1)
    {
        DeleteFirst(first);
    }
    else if(pos == iSize)
    {
        DeleteLast(first);
    }
    else
    {
        temp = *first;

        for(iCnt = 1; iCnt < pos -1; iCnt++)
        {
            temp = temp->next;
        }

        target = temp->next;
        temp->next = target->next;
        target->next->prev = temp;
        free(target);

    }
}

int main()
{
    int iRet = 0;
    PNODE head = NULL;

    InsertFirst(&head,51);
    InsertFirst(&head,21);
    InsertFirst(&head,11);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are %d \n",iRet);

    InsertLast(&head , 101);
    InsertLast(&head , 111);
    InsertLast(&head , 121);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are %d \n",iRet);

    DeleteFirst(&head);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are %d \n",iRet);

    DeleteLast(&head);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are %d \n",iRet);

    InsertAtPos(&head, 105,4);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are %d \n",iRet);

    DeleteAtPos(&head,3);

    Display(head);

    iRet = Count(head);
    printf("Number of nodes are %d \n",iRet);

    return 0;
}