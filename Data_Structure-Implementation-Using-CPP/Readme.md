# Data_Structure_Implementations-Using- (C++) 

This repository contains multiple Linked List implementations in C++, designed for learning and practicing Data Structures and Algorithms using Object-Oriented Programming.
Each linked list demonstrates different pointer relationships, traversal techniques, and dynamic memory management concepts.

## Types of Linked Lists Implemented

### Singly Linear Linked List

A collection of nodes where:
 
Each node stores data

Each node points to the next node

The last node points to NULL

### Singly Circular Linked List

A collection of nodes where:

Each node stores data

Each node points to the next node

The last node points back to the first node

There is no NULL pointer

### Doubly Linear Linked List

A collection of nodes where:

Each node stores data

Each node points to the next node

Each node points to the previous node

First node’s prev is NULL

Last node’s next is NULL

### Doubly Circular Linked List

A collection of nodes where:

Each node stores data

Each node points to the next node

Each node points to the previous node

Last node’s next points to the first node

First node’s prev points to the last node

There is no NULL pointer

### Data Structures Used
Singly Linked List Node
```cpp
struct node
{
    int data;
    node *next;
};
```

### Doubly Linked List Node
```cpp
struct node
{
    int data;
    node *next;
    node *prev;
};
```

## Common Operations Implemented

✔ Insert node at first position

✔ Insert node at last position

✔ Insert node at given position

✔ Delete node from first position

✔ Delete node from last position

✔ Delete node from given position

✔ Display all elements

✔ Count number of nodes

✔ Search element (First / Last Occurrence)

(Forward and backward traversal included where applicable)

## How to Compile and Run

g++ Filename.cpp -o Myexe

./Myexe

## Concepts Covered

Dynamic memory allocation (new, delete)

Pointers and references

Classes and Objects

Encapsulation

Linear and circular data structures

Forward and backward traversal

Object-Oriented Programming (OOP)

## Author

Vivek B. Gautam

📧 Email: vivekbgautam@gmail.com

🔗 GitHub: https://github.com/viivekbgautam

⭐ If you find this repository helpful, consider giving it a star!
