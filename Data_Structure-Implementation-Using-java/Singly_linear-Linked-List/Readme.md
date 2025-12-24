# Singly_Linear-Linked-List

This repository contains a Singly Linear Linked List implementation in Java, designed for learning and practicing Data Structures and Algorithms.
The project demonstrates how dynamic data structures work using object-oriented programming concepts.

## What is a Singly Linear Linked List?

A Singly Linear Linked List is a collection of nodes where:

Each node contains data

Each node stores a reference to the next node

The last node points to null

Memory is allocated dynamically


## Classes Overview
🔹 node

Represents a single node of the linked list.

### Data Members

int data – Stores node data

node next – Reference to next node

### SinglyLL

Implements all singly linear linked list operations.

Data Members

node first – Head of the list

int iCount – Number of nodes

Entry point class to demonstrate linked list operations using main().

## Operations
Operation	Description
InsertFirst(int no)	Insert node at beginning
InsertLast(int no)	Insert node at end
InsertAtPos(int no, int pos)	Insert node at specific position
DeleteFirst()	Delete first node
DeleteLast()	Delete last node
DeleteAtPos(int pos)	Delete node at specific position
Display()	Display all elements
Count()	Return total number of nodes

## Sample Output
| 11 | -> | 21 | -> | 51 | -> null
Total node in linked list are : 3

| 11 | -> | 21 | -> | 51 | -> | 101 | -> | 111 | -> | 121 | -> null
Total node in linked list are : 6


Data Structures

## Learning Outcomes

Understanding linked list internals

Implementing insert & delete operations

Traversing linked lists

Applying OOP concepts in Java

## How to Run

Compile the program:

javac Filename.java


Run the program:

java Filename

## Author

Vivek Bhauraj Gautam

 Email: Vivekbgautam@gmail.com

 GitHub: https://github.com/Vivekbgautam

