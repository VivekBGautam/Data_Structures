# Singly_Circular-Linked-List 

This repository contains a Singly Circular Linked List implementation in Java, designed for learning and practicing Data Structures and Algorithms.
The project demonstrates how circular dynamic data structures work using object-oriented programming concepts.

## What is a Singly Circular Linked List?

A Singly Circular Linked List is a collection of nodes where:

Each node contains data

Each node stores a reference to the next node

The last node points back to the first node

There is no NULL reference in the list

Memory is allocated dynamically

### Classes Overview
🔹 node

Represents a single node of the singly circular linked list.

Data Members

int data – Stores node data

node next – Reference to the next node

🔹 SinglyCL

Implements all singly circular linked list operations.

Data Members

node first – Reference to the first node

node last – Reference to the last node

int iCount – Number of nodes

Entry point class to demonstrate singly circular linked list operations using main().

## Operations Supported

Operation	Description

InsertFirst(int no)	Insert node at beginning

InsertLast(int no)	Insert node at end

InsertAtPos(int no, int pos)	Insert node at specific position

DeleteFirst()	Delete first node

DeleteLast()	Delete last node

DeleteAtPos(int pos)	Delete node at specific position

Display()	Display all elements

Count()	Return total number of nodes

### Sample Output
| 11 | <-> | 21 | <-> | 51 | <-> (Back to First)
Total node in linked list are : 3

| 11 | <-> | 21 | <-> | 51 | <-> | 101 | <-> | 111 | <-> | 121 | <-> (Back to First)
Total node in linked list are : 6

## Learning Outcomes

Understanding circular linked list internals

Difference between linear and circular linked lists

Implementing circular insert and delete operations

Traversing circular linked lists safely

Applying OOP concepts in Java

### How to Run

Compile the program

javac Filename.java


Run the program

java Filename

## Author

Vivek Bhauraj Gautam

📧 Email: Vivekbgautam@gmail.com

🐙 GitHub: https://github.com/Vivekbgautam
