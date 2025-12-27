# Singly Linear Linked List (C++)
Overview

This repository contains an implementation of a Singly Linear Linked List using C++ (Object-Oriented Programming).
The program is designed for learning and practicing Data Structures, focusing on pointers, dynamic memory allocation, and class-based design.

A singly linked list is a collection of nodes where:

Each node stores data

Each node contains a pointer to the next node

The last node points to NULL

## Author

Author Name : Vivek Bhauraj Gautam

Language : C++

Date : 23/12/2025

🧱 Data Structure Used
🔹 Node Structure

Each node consists of:

data → Stores integer value

next → Pointer to the next node

struct node
{
    int data;
    struct node *next;
};

## Class Used
🔹 SinglyLL

This class encapsulates all operations of the singly linked list and maintains:

first → Head pointer of the linked list

iCount → Number of nodes in the list

## Supported Operations
Operation Name	Description
InsertFirst	Inserts a node at the beginning
InsertLast	Inserts a node at the end
InsertAtPos	Inserts a node at a specific position
DeleteFirst	Deletes the first node
DeleteLast	Deletes the last node
DeleteAtPos	Deletes a node from a specific position
Display	Displays all elements of the list
Count	Returns total number of nodes


## How to Run the Program
Compile
g++ SinglyLL.cpp -o SinglyLL

Execute
./SinglyLL

## Sample Output
| 11 | | 21 | | 51 | NULL
Total node in linked list is : 3

## Learning Outcomes

Understanding linked list concepts

Working with dynamic memory allocation

Applying Object-Oriented Programming

Implementing menu-free functional testing

Writing industry-standard documentation