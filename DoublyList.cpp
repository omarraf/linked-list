#include "DoublyList.h"
#include <iostream> 
#include <ostream>
using namespace std;

void DoublyList::insertFirst(int newData)
{
    if (count == 0) // list is empty
    {
        first = new DLLNode(newData, nullptr, nullptr);
        last = first;
        
    }
    else
    {
        first = new DLLNode(newData, nullptr, first);
        first->getNext()->setPrev(first);
    }
    count++;
}
void DoublyList::printForward() const
{
    DLLNode *current = first;
    while (current != nullptr)
    {
        cout << current->getData() << " "; 
        current = current->getNext();
    }
}
void DoublyList::printReverse() const
{
    DLLNode *current = last;
    while (current != nullptr)
    {
        cout << current->getData() << " ";
        current = current->getPrev();
    }
}

void DoublyList::deleteNode(int data)
{
    if (count == 0)
    {
        cerr << "THE LIST IS EMPTY";
    }
    else if (first->getData() == data)
    {
       if (count == 1) // only one element in the list
       {
           delete first;
           first = nullptr;
           last = nullptr;
       }
       else // more than one element in the list
       {
           DLLNode *temp = first;
           first->getNext()->setPrev(nullptr);
           first = first->getNext();
           delete temp;
           temp = nullptr;
       }
    }
    else if (last->getData() == data) 
    {
        // last needs to be deleted 
        //      ptr before lasts next needs to be set to nullptr
        DLLNode *temp = last;
        last->getPrev()->setNext(nullptr);
        last = last->getPrev();
        delete temp;
        temp = nullptr;
    }
    else // somewhere in the middle
    {
        DLLNode *current = first->getNext();
        bool found = false;
        while(current != last && !found)
        {
            if (current->getData() == data)
            {
                found = true;
                current->getPrev()->setNext(current->getNext());
                current->getNext()->setPrev(current->getPrev());
                delete current;
                current = nullptr;
                
            }
            else
            {
            current = current->getNext();
            }
        }
    }
    count--;
}
void DoublyList::insertBack(int valueToInsert)
{
   // 1 -> 2 -> 3  4
   last = new DLLNode(valueToInsert,last,nullptr);
   last->getPrev()->setNext(last);
   count++;
}
void DoublyList::swapFirstNode(DoublyList &paramNode)
{
    
    
    DLLNode *secondNode = first->getNext();
    first->setNext(paramNode.first->getNext());
    
    DLLNode *tempFirst = paramNode.first;
    paramNode.first = first;
    first = tempFirst;
    first->setNext(secondNode);
    
    
}
void DoublyList::clearList()
{
    DLLNode *temp = first;
    while (temp != nullptr)
    {
        first = first->getNext();
        delete temp;
        temp = first;
    }
    last = nullptr;
    count = 0;
}
//Replace the value of the second-to-last node of the calling object with the value passed by the parameter.

DoublyList::~DoublyList()
{
    if (first != nullptr)
		 clearList();
}
    
