# data-structures-assignment-3-
Overview
This project consists of three parts:

Part 1: Template Queue Implementation
A custom template queue (Queue<T>) was created using a singly linked list with the following capabilities:

push(const T&) – Adds a new element to the end of the queue.

pop() – Removes the element at the front of the queue.

front() – Retrieves the value at the front of the queue.

empty() – Checks whether the queue is empty.

size() – Returns the number of elements in the queue.

move_to_rear() – Moves the element at the front of the queue to the rear using only front(), pop(), and push() (as required by the instructions).

display_all() – Displays all elements in the queue using only queue operations.

This implementation maintains internal pointers to both the front and back nodes, as well as a counter for num_items.

------------------------------------------------------------

Part 2: Recursive Linear Search
A recursive function was written to find the last occurrence of a target element in a vector. It uses a backward recursive step to compare from the end of the vector to the beginning.

Function Signature:

linear_search_last(const vector<T>& items, const T& target, size_t pos_last);
If the target is found, it returns the index of its last occurrence; otherwise, it returns -1.

------------------------------------------------------------

Part 3: Insertion Sort Using a Queue
Insertion sort was implemented using queue operations. A temporary queue was used to maintain sorted order:

Each element from the original queue is dequeued and inserted in the correct position in the sorted queue.

After sorting is complete, elements are transferred back to the original queue.

This satisfies the requirement to sort a list structure (a queue backed by a linked list) without using arrays or vectors.



------------------------------------------------------------
How to Run the Code
Steps in Visual Studio
Open Visual Studio and create a new C++ project.

Add main.cpp and main.h to the project.

Build the solution (Ctrl + Shift + B).

Run the program (Ctrl + F5).
