// USE of this->

#include<iostream>
using namespace std;

#pragma pack(1)

struct node
{
    int data;
    struct node *next;
};

typedef struct node NODE;
typedef struct node * PNODE;

class SinglyLL
{
    private:                        // IMPORTANT
        PNODE first;                // head
        int iCount;

    public:
        SinglyLL()
        {
            cout<<"Object of SinglyLL get created.\n";
            this->first = NULL;
            this->iCount = 0;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : Display
        //  Description   : Displays all elements of the singly linked list.
        //  Input         : void
        //  Output        : Prints all node data on screen
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void Display()          // Updated
        {
            int iCnt = 0;
            PNODE temp = NULL;

            temp = this->first;

            for(iCnt = 1; iCnt <= this->iCount; iCnt++)      // Updated
            {
                cout<<"| "<<temp->data<<" | -> ";
                temp = temp->next;
            }

            cout<<" NULL\n";
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : Count
        //  Description   : Returns total number of nodes present in linked list.
        //  Input         : void
        //  Output        : Integer count of nodes
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        int Count()
        {
            return this->iCount;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : InsertFirst
        //  Description   : Inserts a new node at the beginning of linked list.
        //  Input         : int no → Data to be inserted
        //  Output        : Modifies linked list by adding node at first position
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void InsertFirst(int no)                // Updated
        {
            PNODE newn = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if(newn == NULL)
            {
                cout<<"Unable to alocate memory \n";
                return;
            }

            newn->next = this->first;
            this->first = newn;
            

            this->iCount++;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : InsertLast
        //  Description   : Inserts a new node at the end of linked list.
        //  Input         : int no → Data to be inserted
        //  Output        : Modifies linked list by adding node at last position
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void InsertLast(int no)
        {
            PNODE newn = NULL;
            PNODE temp = NULL;

            newn = new NODE;

            newn->data = no;
            newn->next = NULL;

            if(newn == NULL)
            {
                cout<<"Unable to alocate memory \n";
                return;
            }

            if(this->iCount == 0)             // Updated
            {
                this->first = newn;
            }
            else
            {
                temp = this->first;

                while(temp->next != NULL)
                {
                    temp = temp->next;
                }

                temp->next = newn;
            }

            this->iCount++;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : InsertAtPos
        //  Description   : Inserts a new node at a specific position in linked list.
        //  Input         : int no  → Data to be inserted
        //                  int pos → Position where node is to be inserted
        //  Output        : Modifies linked list by inserting node at given position
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void InsertAtPos(int no,int pos)
        {
            int iCnt = 0;

            PNODE newn = NULL;
            PNODE temp = NULL;

            if(pos < 1 || pos > this->iCount + 1)
            {
                cout<<"Invalid position\n";
                return;
            }

            if(pos == 1)
            {
                this->InsertFirst(no);
            }
            else if(pos == this->iCount + 1)
            {
                this->InsertLast(no);
            }
            else
            {
                newn = new NODE;
                newn->data = no;
                newn->next = NULL;

                temp = this->first;

                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp->next;
                }

                newn->next = temp->next;
                temp->next = newn;

                this->iCount++;
            }
            
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : DeleteFirst
        //  Description   : Deletes the first node of linked list.
        //  Input         : void
        //  Output        : Removes first node and frees its memory
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void DeleteFirst()
        {
            PNODE temp = NULL;

            if(this->first == NULL)
            {
                return;
            }
            else if(this->first->next == NULL)            // if(this->iCount == 1)
            {
                delete this->first;
                this->first = NULL;
            }
            else
            {
                temp = this->first;
                
                this->first = this->first->next;
                delete temp;
            }

            this->iCount--;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : DeleteLast
        //  Description   : Deletes the last node of linked list.
        //  Input         : void
        //  Output        : Removes last node and frees its memory
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void DeleteLast()
        {
            PNODE temp = NULL;

            if(this->first == NULL)
            {
                return;
            }
            else if(this->first->next == NULL)            // if(this->iCount == 1)
            {
                delete this->first;
                this->first = NULL;
            }
            else
            {
                temp = this->first;

                while(temp->next->next != NULL)
                {
                    temp = temp->next;
                }
                
                delete temp->next;
                temp->next = NULL;
            }

            this->iCount--;
        }

        ////////////////////////////////////////////////////////////////////////////////////////////////////
        //
        //  Function Name : DeleteAtPos
        //  Description   : Deletes node from a specific position in linked list.
        //  Input         : int pos → Position of node to be deleted
        //  Output        : Removes node from given position and frees its memory
        //  Author        : Vivek Bhauraj Gautam
        //  Date          : 23/12/2025
        //
        ////////////////////////////////////////////////////////////////////////////////////////////////////
        void DeleteAtPos(int pos)
        {
            int iCnt = 0;

            PNODE temp = NULL;
            PNODE target = NULL;

            if(pos < 1 || pos > this->iCount)
            {
                cout<<"Invalid position\n";
                return;
            }

            if(pos == 1)
            {
                this->DeleteFirst();
            }
            else if(pos == iCount)
            {
                this->DeleteLast();
            }
            else
            {
                temp = this->first;

                for(iCnt = 1; iCnt < pos-1; iCnt++)
                {
                    temp = temp->next;
                }

                target = temp->next;

                temp->next = target->next;
                delete target;

                this->iCount--;
            }
        }
};

int main()
{
    SinglyLL obj;
    int iRet = 0;

    obj.InsertFirst(51);
    obj.InsertFirst(21);
    obj.InsertFirst(11);

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.InsertLast(101);
    obj.InsertLast(111);
    obj.InsertLast(121);

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.first = NULL;     // RISkY Syntax    ERROR
    obj.iCount = 0;       // RISKY Syntax    ERROR

    obj.DeleteFirst();

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteLast();

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.InsertAtPos(105,4);

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    obj.DeleteAtPos(4);

    obj.Display();

    iRet = obj.Count();

    cout<<"total node in linked list is : "<<iRet<<"\n";

    return 0;
}
