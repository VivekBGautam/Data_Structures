#include<stdio.h>
#include<stdlib.h>

#define TRUE 1
#define FALSE 0

typedef int BOOL;

////////////////////////////////////////////////////////////////////////
//
// Structure Name  : node
// Description     : Represents a node of singly linked list
// Members         :
//      data  - Stores integer data
//      next  - Pointer to next node
//
////////////////////////////////////////////////////////////////////////
struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

////////////////////////////////////////////////////////////////////////
//
// Function Name   : InsertFirst
// Description     : Inserts a new node at the beginning of the linked list
// Input           : Address of head pointer, integer value
// Output          : Updates linked list by adding new node at first position
// Author          : Vivek Bhauraj Gautam
//
////////////////////////////////////////////////////////////////////////
void InsertFirst(PPNODE first, int no)
{
    PNODE newn = (PNODE)malloc(sizeof(NODE));

    newn->data = no;
    newn->next = *first;
    *first = newn;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name   : SearchFirstOCC
// Description     : Searches for the first occurrence of given element
//                   in the linked list
// Input           : Head pointer of linked list, integer value to search
// Output          : Returns index (0-based) if element is found
//                   Returns -1 if element is not found
// Author          : Vivek Bhauraj Gautam
//
////////////////////////////////////////////////////////////////////////
int SearchFirstOCC(PNODE first , int no)
{
    int iIndex = 0;

    while(first != NULL)
    {
        if(first->data == no)
        {
            return iIndex;
        }
        first = first->next;
        iIndex++;
    }

    return -1;
}

////////////////////////////////////////////////////////////////////////
//
// Function Name   : SearchLastOCC
// Description     : Searches for the last occurrence of given element
//                   in the singly linked list
// Input           : Head pointer of linked list, integer value to search
// Output          : Returns index (0-based) of last occurrence if found
//                   Returns -1 if element is not found
// Author          : Vivek Bhauraj Gautam
//
////////////////////////////////////////////////////////////////////////
int SearchLastOcc(PNODE first, int no)
{
    
    int iIndex = 0;
    int iPos = -1;

    while(first != NULL)
    {
        if(first->data == no)
        {
            iPos = iIndex;
        }
        first = first->next;
        iIndex++;
    }

    return iPos;
}

////////////////////////////////////////////////////////////////////////
//
// Entry Point Function : main
// Description          : Demonstrates singly linked list operations
//                        and searches first and Last occurrence of an element
// Input                : None
// Output               : Displays index of searched element
// Author               : Vivek Bhauraj Gautam
//
////////////////////////////////////////////////////////////////////////
int main()
{
    PNODE head = NULL;
    int iRet = 0;

    InsertFirst(&head, 101);
    InsertFirst(&head, 51);
    InsertFirst(&head, 21);
    InsertFirst(&head, 11);

    iRet = SearchFirstOCC(head, 51);

    if(iRet != -1)
    {
        printf("51 occurs at index number : %d\n", iRet);
    }
    else
    {
        printf("51 not found in the linked list\n");
    }

    iRet = SearchLastOcc(head, 51);

    if(iRet != -1)
    {
        printf("Last occurrence of 51 is at index : %d\n", iRet);
    }
    else
    {
        printf("51 not found in the linked list\n");
    }

    return 0;
}
