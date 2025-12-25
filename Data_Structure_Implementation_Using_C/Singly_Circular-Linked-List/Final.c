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

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : Display
//  Description   : Displays all elements of the singly linked list.
//  Input         : PNODE first  →  Pointer to the first node of the linked list
//                  PNODE last  →  Pointer to the last node of the linked list
//  Output        : Prints all node data on screen
//  Author        : Vivek Bhauraj Gautam
//  Date          : 19/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void Display(PNODE first, PNODE last)
{
    do
    {
        printf("| %d | -> ",first->data);
        first= first->next;
    
    } while (first != last->next);

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
//  Date          : 19/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
int Count(PNODE first, PNODE last)
{
    int iCount = 0;

    do
    {
        iCount++;
        first= first->next;
    
    } while (first != last->next);

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

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertLast
//  Description   : Inserts a new node at the end of the linked list.
//  Input         : PPNODE first → Address of first pointer
//                  PPNODE last → Address of last pointer
//                  int no        → Data to be inserted in the node
//  Output        : Modifies linked list by adding new node at last position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 19/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
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
        (*last)->next = newn;               // @
        *last = newn;                       // @
    }

    (*last)->next = *first;                 // @ maintain circular nature
    
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : InsertAtPos
//  Description   : Inserts a new node at a specific position in the linked list.
//  Input         : PPNODE first → Address of first pointer
//                  PPNODE last → Address of last pointer
//                  int no        → Data to be inserted
//                  int pos       → Position where node is to be inserted
//  Output        : Modifies linked list by placing new node at desired position
//  Author        : Vivek Bhauraj Gautam
//  Date          : 05/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void InsertAtPos(PPNODE first, PPNODE last, int no, int pos)
{
    int iSize = 0;
    int iCnt = 0;

    iSize = Count(*first,*last);
    PNODE newn = NULL;
    PNODE temp = NULL;

    if((pos < 1) || (pos > iSize + 1))
    {
        printf("Invalid Position \nn");
        return;
    }
    else if(pos == 1)
    {
        InsertFirst(first,last,no);
    }
    else if(pos == iSize + 1)
    {
        InsertLast(first,last,no);
    }
    else
    {
        newn = (PNODE)malloc(sizeof(NODE));

        newn->data = no;
        newn->next = NULL;

        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp -> next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteFirst
//  Description   : Deletes the first node of the linked list.
//  Input         : PPNODE first → Address of first pointer
//                  PPNODE last → Address of last pointer
//  Output        : Removes first node and frees its memory
//  Author        : Vivek Bhauraj Gautam
//  Date          : 19/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteFirst(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL))    // Case 1
    {
        return;
    }
    else if(*first == *last)                  // Case 2
    {
        free(*first);

        *first = NULL;
        *last = NULL;
    }
    else                                      // Case 3
    {
        temp = *first;
        *first = (*first)->next;
        free(temp);
    }

    (*last)->next = *first;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteLast
//  Description   : Deletes the first node of the linked list.
//  Input         : PPNODE first → Address of first pointer
//                  PPNODE last → Address of last pointer
//  Output        : Removes last node and frees its memory
//  Author        : Vivek Bhauraj Gautam
//  Date          : 19/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteLast(PPNODE first, PPNODE last)
{
    PNODE temp = NULL;

    if((*first == NULL) && (*last == NULL))    // Case 1
    {
        return;
    }
    else if(*first == *last)                  // Case 2
    {
        free(*first);
        
        *first = NULL;
        *last = NULL;
    }
    else                                      // Case 3
    {
        temp = *first;

        while(temp->next != *last)
        {
            temp = temp->next;
        }

        free(*last);
        *last = temp;
    }

    (*last)->next = *first;
}

////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Function Name : DeleteAtPos
//  Description   : Deletes a node from a specific position in the linked list.
//  Input         : PPNODE first → Address of first pointer
//                  PPNODE last → Address of last pointer
//                  int pos       → Position of the node to be deleted
//  Output        : Removes node from given position and frees its memory
//  Author        : Vivek Bhauraj Gautam
//  Date          : 05/12/2025
//
////////////////////////////////////////////////////////////////////////////////////////////////////
void DeleteAtPos(PPNODE first, PPNODE last, int pos)
{
    int iSize = 0;
    int iCnt = 0;

    iSize = Count(*first,*last);

    PNODE temp =  NULL;
    PNODE target = NULL;

    if((pos < 1) || (pos > iSize + 1))
    {
        printf("Invalid position \n");
        return;
    }
    else if(pos == 1)
    {
        DeleteFirst(first,last);
    }
    else if(pos == iSize)
    {
        DeleteLast(first,last);
    }
    else 
    {
        temp = *first;

        for(iCnt = 1; iCnt < pos-1; iCnt++)
        {
            temp = temp->next;;
        }

        target = temp->next;

        temp->next = target->next;
        free(target);
    }
}

int main()
{
    int iRet = 0;

    PNODE head = NULL;
    PNODE tail = NULL;

    InsertFirst(&head,&tail,51);
    InsertFirst(&head,&tail,21);
    InsertFirst(&head,&tail,11);

    InsertLast(&head,&tail,101);
    InsertLast(&head,&tail,111);
    InsertLast(&head,&tail,121);


    Display(head,tail);

    iRet = Count(head,tail);

    printf("total node in linked list is : %d\n",iRet);

    DeleteFirst(&head,&tail);

    Display(head,tail);

    iRet = Count(head,tail);

    printf("total node in linked list is : %d\n",iRet);

    DeleteLast(&head,&tail);

    Display(head,tail);

    iRet = Count(head,tail);

    printf("total node in linked list is : %d\n",iRet);

    InsertAtPos(&head,&tail,105,4);

    Display(head,tail);

    iRet = Count(head,tail);

    printf("total node in linked list is : %d\n",iRet);

    DeleteAtPos(&head,&tail,4);

    Display(head,tail);

    iRet = Count(head,tail);

    printf("total node in linked list is : %d\n",iRet);

    return 0;
}