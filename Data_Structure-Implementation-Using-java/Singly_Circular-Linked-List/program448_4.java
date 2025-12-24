// SINGLY CIRCULAR LINKED LIST

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  : node
//  Description : Represents a single node of singly circular linked list
//  Data Members:
//      int data  → Stores integer data
//      node next → Reference to next node
//  Author      : Vivek Bhauraj Gautam
//  Date        : 24/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
class node
{
    public int data;
    public node next;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Constructor Name : node
    //  Description      : Initializes a node with given data and null link
    //  Input            : int no → Data value
    //  Author           : Vivek Bhauraj Gautam
    //  Date             : 24/12/2025
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    public node(int no)
    {
        this.data = no;
        this.next = null;
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  : SinglyCL
//  Description : Implements singly circular linked list operations
//  Data Members:
//      node first → Reference to first node
//      node last  → Reference to last node
//      int iCount → Stores total number of nodes
//  Author      : Vivek Bhauraj Gautam
//  Date        : 24/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
class SinglyCL
{
    private node first;
    private node last;
    private int iCount;

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Constructor Name : SinglyCL
    //  Description      : Initializes an empty singly circular linked list
    //  Author           : Vivek Bhauraj Gautam
    //  Date             : 24/12/2025
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    public SinglyCL()
    {
        System.out.println("Object of SinglyCL get created.");
        this.first = null;
        this.last = null;
        this.iCount = 0;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name : Display
    //  Description   : Displays all nodes in the singly circular linked list
    //  Input         : None
    //  Output        : Prints node data on the screen
    //  Author        : Vivek Bhauraj Gautam
    //  Date          : 24/12/2025
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    public void Display()
    {
        node temp = null;

        temp = first;

        if(first != null)
        {
            do
            {
                System.out.print("| "+temp.data+" | <->");
                temp = temp.next;

            }while(temp != last.next);

            System.out.println();
        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name : Count
    //  Description   : Returns total number of nodes in the list
    //  Input         : None
    //  Output        : int → Total node count
    //  Author        : Vivek Bhauraj Gautam
    //  Date          : 24/12/2025
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    public int Count()
    {
        return this.iCount;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name : InsertFirst
    //  Description   : Inserts a new node at the beginning of the list
    //  Input         : int no → Data to be inserted
    //  Output        : Modifies linked list
    //  Author        : Vivek Bhauraj Gautam
    //  Date          : 24/12/2025
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    public void InsertFirst(int no)
    {
        node newn = null;

        newn = new node(no);

        if(first == null)
        {
            first = newn;
            last = newn;
        }
        else 
        {
            newn.next = first;
            first = newn;
        }

        last.next = first;
        iCount++;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name : InsertLast
    //  Description   : Inserts a new node at the end of the list
    //  Input         : int no → Data to be inserted
    //  Output        : Modifies linked list
    //  Author        : Vivek Bhauraj Gautam
    //  Date          : 24/12/2025
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    public void InsertLast(int no)
    {
        node newn = null;
        newn = new node(no);

        if(first == null)
        {
            first = newn;
            last = newn;
        }
        else 
        {
            last.next = newn;
            last = newn;
        }

        last.next = first;
        iCount++;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name : InsertAtPos
    //  Description   : Inserts a new node at a specific position
    //  Input         : int no → Data to be inserted
    //                  int pos → Position
    //  Output        : Modifies linked list
    //  Author        : Vivek Bhauraj Gautam
    //  Date          : 24/12/2025
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    public void InsertAtPos(int no, int pos)
    {
        int iCnt = 0;

        node newn = null;
        node temp = null;

        if(pos < 1 || pos > iCount + 1)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            InsertFirst(no);
        }
        else if(pos == iCount + 1)
        {

            InsertLast(no);
        }
        else 
        {
            newn = new node(no);

            temp = first;

            for(iCnt = 1; iCnt < pos -1; iCnt++)
            {
                temp = temp.next;
            }

            newn.next = temp.next;
            temp.next = newn;

            iCount++;

        }
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name : DeleteFirst
    //  Description   : Deletes the first node of the list
    //  Input         : None
    //  Output        : Modifies linked list
    //  Author        : Vivek Bhauraj Gautam
    //  Date          : 24/12/2025
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    public void DeleteFirst()
    {
        if(first == null && last == null)
        {
            return;
        }
        if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            first = first.next;
            last.next = first;
        }

        iCount--;
        //System.gc();;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name : DeleteLast
    //  Description   : Deletes the last node of the list
    //  Input         : None
    //  Output        : Modifies linked list
    //  Author        : Vivek Bhauraj Gautam
    //  Date          : 24/12/2025
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    public void DeleteLast()
    {
        node temp = null;

        if(first == null && last == null)
        {
            return;
        }
        if(first == last)
        {
            first = null;
            last = null;
        }
        else
        {
            temp = first;

            while(temp.next != last)
            {
                temp = temp.next;
            }

            last = temp;
        }

        last.next = first;

        iCount--;
        //System.gc();;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name : DeleteAtPos
    //  Description   : Deletes node from a specific position
    //  Input         : int pos → Position
    //  Output        : Modifies linked list
    //  Author        : Vivek Bhauraj Gautam
    //  Date          : 24/12/2025
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    public void DeleteAtPos(int pos)
    {
        int iCnt = 0;

        node temp = null;

        if(pos < 1 || pos > iCount)
        {
            System.out.println("Invalid Position");
            return;
        }

        if(pos == 1)
        {
            DeleteFirst();
        }
        else if(pos == iCount)
        {

            DeleteLast();
        }
        else 
        {
            temp = first;

            for(iCnt = 1; iCnt < pos -1; iCnt++)
            {
                temp = temp.next;
            }

            temp.next = temp.next.next;

            iCount--;
        }
    }
}

//////////////////////////////////////////////////////////////////////////////////////////////////////
//
//  Class Name  : program448_4
//  Description : Entry point class to demonstrate Singly Circular Linked List operations
//  Author      : Vivek Bhauraj Gautam
//  Date        : 24/12/2025
//
//////////////////////////////////////////////////////////////////////////////////////////////////////
class program448_4
{
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    //
    //  Function Name : main
    //  Description   : Demonstrates usage of Singly Circular Linked List operations
    //  Input         : Command line arguments
    //  Output        : Displays linked list contents and node counts
    //  Author        : Vivek Bhauraj Gautam
    //  Date          : 24/12/2025
    //
    ////////////////////////////////////////////////////////////////////////////////////////////////////
    public static void main(String A[])
    {
        int iRet = 0;

        SinglyCL obj = null;
    
        obj = new SinglyCL(); 

        obj.InsertFirst(51);
        obj.InsertFirst(21);
        obj.InsertFirst(11);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Total node in linked list are : "+iRet);

        obj.InsertLast(101);
        obj.InsertLast(111);
        obj.InsertLast(121);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Total node in linked list are : "+iRet);

        obj.DeleteFirst();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Total node in linked list are : "+iRet);

        obj.DeleteLast();

        obj.Display();

        iRet = obj.Count();

        System.out.println("Total node in linked list are : "+iRet);

        obj.InsertAtPos(105,4);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Total node in linked list are : "+iRet);

        obj.DeleteAtPos(4);

        obj.Display();

        iRet = obj.Count();

        System.out.println("Total node in linked list are : "+iRet);

        // Important for memory deallocation
        obj = null;
        System.gc();

    }
}
