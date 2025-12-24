# Doubly_Linear-Linked-List

This repository contains a Doubly Linear Linked List implementation in Java, designed for learning and practicing Data Structures and Algorithms.
The project demonstrates how bidirectional dynamic data structures work using object-oriented programming concepts.

## What is a Doubly Linear Linked List?

A Doubly Linear Linked List is a collection of nodes where:

Each node contains data

Each node stores a reference to the next node

Each node stores a reference to the previous node

The first node’s previous pointer is NULL

The last node’s next pointer is NULL

Memory is allocated dynamically

## Classes Overview
🔹 node

Represents a single node of the doubly linear linked list.

Data Members

int data – Stores node data

node next – Reference to the next node

node prev – Reference to the previous node

🔹 DoublyLL

Implements all doubly linear linked list operations.

Data Members

node first – Reference to the first node

int iCount – Number of nodes

Entry point class to demonstrate doubly linear linked list operations using main().

## Operations Supported

Operation	Description

InsertFirst(int no)	Insert node at beginning

InsertLast(int no)	Insert node at end

InsertAtPos(int no, int pos)	Insert node at specific position

DeleteFirst()	Delete first node

DeleteLast()	Delete last node

DeleteAtPos(int pos)	Delete node at specific position

Display()	Display all elements (Forward traversal)

Count()	Return total number of nodes

### Sample Output
null <- | 11 | <-> | 21 | <-> | 51 | -> null
Total node in linked list are : 3

null <- | 11 | <-> | 21 | <-> | 51 | <-> | 101 | <-> | 111 | <-> | 121 | -> null
Total node in linked list are : 6

## Learning Outcomes

Understanding doubly linked list internals

Forward and backward traversal

Implementing insert and delete operations

Memory management using references

Applying OOP concepts in Java

## How to Run

Compile the program

javac Filename.java


Run the program

java Filename

## Author

Vivek Bhauraj Gautam

 Email: Vivekbgautam@gmail.com

 GitHub: https://github.com/Vivekbgautam
