////////////////////////////////////////////////////////////////////////////////////////////////
//
// Program Name : Generic Queue Implementation
// Description  : This program demonstrates the implementation of a Queue data structure
//                using a generic (template-based) approach in C++.
//                The Queue follows the FIFO (First In First Out) principle and is
//                implemented using a singly linked list.
//                The program supports EnQueue, DeQueue, Display, and Count operations
//                using a menu-driven approach.
// Author       : Vivek Bhauraj Gautam
// Date         : January 2026
//
////////////////////////////////////////////////////////////////////////////////////////////////

#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class Name  : Queuenode
// Description : Represents a single node of the Queue.
// Template    : T (Generic data type)
// Members     :
//      data  - Stores the value
//      next  - Pointer to next node
//
////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class Queuenode
{
    public:
        T data;
        Queuenode<T> * next;

        ////////////////////////////////////////////////////////////////////////
        //
        // Constructor Name : Queuenode
        // Description      : Initializes a new queue node with given data.
        //                    Sets next pointer to NULL.
        // Input            : T no → Value to be stored
        // Output           : Queue node is created
        //
        ////////////////////////////////////////////////////////////////////////
        Queuenode(T no)
        {
            this->data = no;
            this->next = NULL;
        }
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
// Class Name  : Queue
// Description : Implements Queue data structure using linked list.
// Features    :
//      - EnQueue
//      - DeQueue
//      - Display
//      - Count
//
////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
class Queue
{
    private:
        Queuenode<T> * first;
        Queuenode<T> * last;
        int iCount;

    public:
        Queue();
        void EnQueue(T);
        T DeQueue();
        void Display();
        int Count();
};

////////////////////////////////////////////////////////////////////////////////////////////////
//
// Constructor Name : Queue
// Description      : Initializes an empty queue.
//                    Sets first and last pointers to NULL and count to zero.
// Input            : void
// Output           : Queue object gets created successfully
//
////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
Queue<T>::Queue()
{
    cout<<"Queue gets Created successfully\n";
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : EnQueue
// Description   : Inserts a new element at the end of the queue.
//                 Maintains FIFO (First In First Out) principle.
// Input         : T no → Element to be inserted
// Output        : Queue is updated
//
////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Queue<T>::EnQueue(T no)
{
    Queuenode<T> * newn = NULL;
    newn = new Queuenode<T>(no);

    if(this->first == NULL)
    {
        this->first = newn;
        this->last = newn;
    }
    else
    {
        this->last->next = newn;
        this->last = newn;
    }
    this->iCount++;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : DeQueue
// Description   : Removes the first element from the queue and returns it.
//                 Handles underflow condition if queue is empty.
// Input         : void
// Output        : Returns removed element
//
////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
T Queue<T>::DeQueue()
{
    T Value;
    Queuenode<T> * temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is Empty\n";
        return (T)-1;
    }

    Value = this->first->data;
    this->first = this->first->next;

    delete temp;
    this->iCount--;

    if(this->first == NULL)
    {
        this->last = NULL;
    }

    return Value;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Display
// Description   : Displays all elements of the queue from front to rear.
// Input         : void
// Output        : Prints queue elements
//
////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
void Queue<T>::Display()
{
    Queuenode<T> * temp = this->first;

    if(this->first == NULL && this->last == NULL)
    {
        cout<<"Queue is Empty\n";
        return;
    }

    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<" | -> ";
        temp = temp->next;
    }
    cout<<"\n";
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
// Function Name : Count
// Description   : Returns total number of elements in the queue.
// Input         : void
// Output        : Integer count
//
////////////////////////////////////////////////////////////////////////////////////////////////
template <class T>
int Queue<T>::Count()
{
    return this->iCount;
}

////////////////////////////////////////////////////////////////////////////////////////////////
//
// Entry Point Function : main
// Description          : Menu-driven function to demonstrate all Queue operations.
// Input                : User choice and values
// Output               : Executes selected operations
//
////////////////////////////////////////////////////////////////////////////////////////////////
int main()
{
    Queue<int> * qobj = new Queue<int>();

    int iChoice = 0;
    int Value = 0;
    int iRet = 0;

    while(1)
    {
        cout<<"------------------------------------------------------------\n";
        cout<<"Please select the option\n";
        cout<<"1 : Insert element into Queue\n";
        cout<<"2 : Remove element from Queue\n";
        cout<<"3 : Display Queue elements\n";
        cout<<"4 : Count elements in Queue\n";
        cout<<"0 : Exit\n";
        cout<<"------------------------------------------------------------\n";

        cin>>iChoice;

        switch(iChoice)
        {
            case 1:
                cout<<"Enter element to insert : ";
                cin>>Value;
                qobj->EnQueue(Value);
                cout<<"Element inserted successfully\n";
                break;

            case 2:
                iRet = qobj->DeQueue();
                if(iRet != -1)
                {
                    cout<<"Removed element is : "<<iRet<<"\n";
                }
                break;

            case 3:
                cout<<"Queue elements are : \n";
                qobj->Display();
                break;

            case 4:
                iRet = qobj->Count();
                cout<<"Number of elements in queue : "<<iRet<<"\n";
                break;

            case 0:
                cout<<"Thank you for using the application\n";
                delete qobj;
                return 0;

            default:
                cout<<"Invalid option\n";
        }
    }
    return 0;
}
