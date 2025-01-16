# linked-list

This repository contains an implementation of an ordered doubly-linked list in C++. The list supports numerical values and characters and is implemented in a single LinkedList.h file.

Features:
- Constructor: Creates a list with two elements: minimum (-∞) and maximum (+∞) values.
- Destructor: Deletes all nodes and frees memory.
- Search: Finds the position of a given value or where it should be inserted.
- Insert: Adds a new node in the correct position if the list remains sorted (no duplicates allowed).
- printData: Outputs the list values (separated by spaces).
- print: Outputs the list structure, including node addresses and pointers (for debugging).

Example Output:<br>
Linked list data:<br>
-2147483648 1 2 3 2147483647
