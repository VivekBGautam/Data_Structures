#include<stdio.h>
#include<stdlib.h>

#pragma pack(1)
struct node 
{
    int data;
    struct note *next;
};

typedef struct node NODE;
typedef struct node * PNODE;
typedef struct node ** PPNODE;

// Call By Value
void Display(PNODE first)
{}

int Count(PNODE first)
{
    return 0;
}

int main()
{
    PNODE head = NULL;

    return 0;
}