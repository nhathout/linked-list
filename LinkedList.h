//
//  LinkedList.h
//  Linked_List
//
//  Copyright Â© Tali Moreshet. All rights reserved.
//
//  This is an implementation of an ordered Linked List class, which is made up of Nodes.
//  All classes are templated, such that their types may be provided at creation.
//  Nodes contain data (which doubles as key), and pointers to all directions.

#ifndef LinkedList_h
#define LinkedList_h

#include <iostream>
#include <cstdlib>
#include <time.h>

using namespace std;

template<class T>
class Node {
public:
    Node(const T& data);                            // constructor
    T data;                                         // node data, doubles as key
    Node<T> *next;                                  // node next pointer
    Node<T> *prev;                                  // node previous pointer
    Node<T> *up;                                    // node above pointer
    Node<T> *down;                                  // node below pointer
    void printData();                               // prints data value
    void print();                                   // prints entire node object content
};

template <class T>
class LinkedList {
public:
    LinkedList(T minVal, T maxVal);                 // constructor: accepts -infinity, +infinity values,
                                                    //  creates linked list with two corresponding nodes
    ~LinkedList();                                  // destructor
    Node<T>* search(Node<T>* location, T data);     // search for data starting at location, return node <= data
    Node<T>* insert(Node<T>* location, T data);     // insert node with data at new node to be placed directly 
                                                    //  after node with povided location, return new node
    void printData();                               // prints linked list data
    void print();                                   // prints linked list with all nodes pointers
    Node<T>* head;                                  // head of list
};

/********************** From here down is the content of the LinkedList.cpp file: ***********************/

/****** Implementation of Node ******/

// Constructor
template<class T>
Node<T>::Node(const T& data)
{
    this->data = data;
    this->next = nullptr;
    this->prev = nullptr;
    this->up = nullptr;
    this->down = nullptr;
}

// Print node's data value
template <class T>
void Node<T>::printData()
{
    cout << data << " ";
}

// Print entire node object content (data value, object's address, and all pointers)
template <class T>
void Node<T>::print()
{
    cout << " * " << data << ": [addr: " << this << " next: " << this->next << " prev: " << this->prev << " up: " << this->up << " down: " << this->down << "]  ";
}


/****** Implementation of linked list ******/

//Constructor
template <class T>
LinkedList<T>::LinkedList(T minVal, T maxVal){
	
	head = new Node<T>(minVal);
	Node<T> *tail = new Node<T>(maxVal);
	head -> next = tail;
	tail -> prev = head;
}

//Destructor
template <class T>
LinkedList<T>::~LinkedList(){
	
	Node<T> *current = head;

	while(current != nullptr){
		Node<T> *nextNode = current -> next;
		delete current;
		current = nextNode;
	}
}

//search - looking for next->data <= data to maintain order. So when conditions of while loop not satisfied
//		   either left with node containing data (if exists), or node before where new data should be inserted to maintain order
template <class T>
Node<T>* LinkedList<T>::search(Node<T>* location, T data){
	
	while(location && location -> next && (location -> next -> data <= data)){
		location = location -> next;
	}

	return location;
}

//insert - inserts new node with data 'data', at specified location 'location' if location exists, location->next exists,
//data at location is less than the new data, and the node after the new node's data should be greater than the new data.
template <class T>
Node<T>* LinkedList<T>::insert(Node<T>* location, T data){
	
	if((location) && (location->next) && (location->data < data) && (location->next->data > data)){
		Node<T> *newNode = new Node(data);
		newNode -> next = location -> next;
		newNode -> prev = location;
		location -> next -> prev = newNode;
		location -> next = newNode;
		return newNode;
	}else{
		return nullptr;
	}
}

//printData - prints data of all nodes in linked list seperated by a space.
template <class T>
void LinkedList<T>::printData(){
	Node<T> *current = head; //from beginning

	while(current){ //printing then moving, all the way to INT_MAX from INT_MIN
		current -> printData(); //includes the space

		current = current -> next;
	}
	cout << endl;
}

//print - prints entire contents of linked list including node addresses and pointers
template <class T>
void LinkedList<T>::print(){
	Node<T> *current = head; //from beginning

	while(current){
		current -> print();
		current = current -> next;
	}

	cout << endl;
}

#endif /* LinkedList_h */