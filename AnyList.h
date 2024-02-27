#ifndef ANYLIST_H
#define ANYLIST_H

#include<iostream>
#include <string> // Need to include for nullptr.			

class Node
{
public:
	Node() : data(0), next(nullptr) {}
	Node(int theData, Node *newNext) 
		: data(theData), next(newNext){}
	Node* getNext() const { return next; }
	int getData( ) const { return data; }
	void setData(int theData) { data = theData; }
	void setNext(Node *newNext) { next = newNext; }
	~Node(){}
private:
	int data;		
	Node *next; // Pointer that points to next node.
};


class AnyList
{
public:
	AnyList() : first(nullptr), count(0) {}

	void insertFront(int);	

	void print() const;

	void clearList();
	
	void replaceSecondToLast(int);

	//Replace the value of the second node of the calling object 
    //with the value passed by the parameter.
    void swapSecondToLast(int paramValue);
	~AnyList();

private:
	Node *first;
	// Pointer to point to the first node in the list.
	int count;
	// Variable to keep track of number of nodes in the list.
};




#endif
