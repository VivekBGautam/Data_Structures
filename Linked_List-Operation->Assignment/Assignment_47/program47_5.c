// Q - Write a program which Count of prime number from linked list.

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
//  Function Name : Display
//  Description   : Displays all elements of the singly linked list.
//  Input         : PNODE first  →  Pointer to the first node of the linked list
//  Output        : Prints all node data on screen
//  Author        : Vivek Bhauraj Gautam
//  Date          : 29/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void Display(PNODE first)
{
    if(first == NULL)
    {
        printf("Linked List is Empty\n");
        return;
    }

    while(first != NULL)
    {
        printf("| %d | -> ",first->data);
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
//  Function Name : CountPrime
//  Description   : Count Prime Number from Linked list
//  Input         : PNODE first → Pointer to first node
//  Output        : Return Count of prime number
//  Author        : Vivek Bhauraj Gautam
//  Date          : 30/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
int CountPrime(PNODE first)
{
    int iCount = 0;
    int iCnt = 0;
    int iCountPrime = 0;
    int temp = 0;
    
    if(first == NULL)
    {
        printf("Linked list is empty\n");
        return -1;
    }

    while(first != NULL)
    {   
        temp = first->data;
        iCount = 0;

        if(temp < 0)
        {
            temp = -temp;
        }

        if(temp > 1)
        {
            for(iCnt = 2; iCnt<= temp/2; iCnt++)
            {
                if(temp % iCnt == 0)
                {
                    iCount++;
                }
            }
        }

        if(iCount == 0)
        {
            iCountPrime++;
        }

        first = first->next;
    }

    return iCountPrime;
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

    InsertFirst(&head,29);
    InsertFirst(&head,66);
    InsertFirst(&head,61);
    InsertFirst(&head,10);
    InsertFirst(&head,7);

    Display(head);
    iRet = Count(head);
    printf("Total node in Linked list is : %d \n",iRet);

    iRet = CountPrime(head);
    printf("Count of prime number in linked list is %d",iRet);

    while(head != NULL)
    {
        PNODE temp = head;
        head = head->next;
        free(temp);
    }

    head = NULL;

    return 0;
}