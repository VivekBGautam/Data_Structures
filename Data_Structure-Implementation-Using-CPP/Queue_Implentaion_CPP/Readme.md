# Queue_Implementation in C++

## Overview

This project demonstrates the implementation of a **Generic Queue data structure** using **C++ templates**. The queue follows the **FIFO (First In First Out)** principle and is implemented using a **singly linked list**. The program is **menu-driven** and supports basic queue operations.

---

## Concepts Used

* Queue Data Structure (FIFO)
* Singly Linked List
* Templates (Generic Programming)
* Dynamic Memory Allocation
* Menu-driven Console Application

---

## Features

* Generic (Template-based) Queue
* Insert element into Queue (**EnQueue**)
* Remove element from Queue (**DeQueue**)
* Display Queue elements
* Count number of elements
* Efficient **O(1)** EnQueue and DeQueue operations

---

##  Operations Supported

| Operation | Description                                    |
| --------- | ---------------------------------------------- |
| EnQueue   | Inserts an element at the rear of the queue    |
| DeQueue   | Removes an element from the front of the queue |
| Display   | Displays all elements from front to rear       |
| Count     | Returns total number of elements in the queue  |

---

## File Structure

```
├── DiffrentQueueFile
├── README.md
```

---

## How to Compile and Run

### Compile

```bash
g++ GenericQueue.cpp -o Queue
```

### Run

```bash
./Queue
```

---

## Sample Menu Output

```
------------------------------------------------------------
1 : Insert element into Queue
2 : Remove element from Queue
3 : Display Queue elements
4 : Count elements in Queue
0 : Exit
------------------------------------------------------------
```

---

## Example

**Input:**

```
Insert: 10
Insert: 20
Insert: 30
```

**Output:**

```
| 10 | -> | 20 | -> | 30 |
Count : 3
Removed element : 10
```

---

## Notes

* Queue is implemented using a singly linked list
* FIFO order is strictly maintained
* Generic design allows use with different data types like `int`, `float`, etc.

---

## Author

**Name:** Vivek Bhauraj Gautam
**Date:** 08/01/2026

---
 
