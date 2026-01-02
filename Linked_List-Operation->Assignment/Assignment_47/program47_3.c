// Q - Write a program which Display Addition of digits ofall elements from linked list.

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
//  Function Name : SumDigits
//  Description   : Display Addition of digits of all element from Linked list
//  Input         : PNODE first → Pointer to first node
//  Output        : Display Addition of all digits
//  Author        : Vivek Bhauraj Gautam
//  Date          : 30/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void SumDigits(PNODE first)
{
    int temp = 0;
    int iSum = 0;
    int iDigit = 0;
    
    if(first == NULL)
    {
        printf("Linked list is empty\n");
        return;
    }

    while(first != NULL)
    {   
        iSum = 0;
        temp = first->data;

        if(temp < 0)
        {
            temp = -temp;
        }

        if(temp == 0)
        {
            iSum = 0;
        }
        else
        {
            while(temp != 0)
            {
                iDigit = temp % 10;
                iSum = iSum + iDigit;
                temp = temp / 10;
            }
        }

        printf("Sum of Digits of Value %d is -> %d \n",first->data,iSum);
        first = first->next;
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

    InsertFirst(&head,-212341);
    InsertFirst(&head,24440);
    InsertFirst(&head,-3411);
    InsertFirst(&head,23231);
    InsertFirst(&head,123);

    Display(head);
    iRet = Count(head);
    printf("Total node in Linked list is : %d \n",iRet);

    SumDigits(head);

    while(head != NULL)
    {
        PNODE temp = head;
        head = head->next;
        free(temp);
    }

    head = NULL;

    return 0;
}