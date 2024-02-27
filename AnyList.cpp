#include "AnyList.h"

using namespace std;

void AnyList::insertFront(int newData)
{	
	first = new Node(newData, first);
	++count;
}

void AnyList::print() const
{
	if (first == nullptr) 
	// Check if the list is empty.
	// You can also use: if (count == 0)
		cerr << "List is empty.";  
		// Use cerr, instead of cout. Why?
	else
	{
        	Node *current = first;   
		// Create a pointer to traverse the list.		
		// This pointer will point to the first node in the list.

		while (current != nullptr)	
		// While the current pointer is NOT a nullptr,
		// that is, while the current pointer has not reached  
		// the end of the list.
		{	                        
			// Output the data. 
			cout << current->getData() << " "; 
			// Move the pointer current forward.
			current = current->getNext();                         
		}		
	}
}

// This function does not delete the 
// list object; it ONLY deletes the nodes.
void AnyList::clearList()
{ 	
	Node  *temp = first; 	
	// Pointer to delete the node, which	
	// starts by pointing to the first node.
	
	while (first != nullptr)
	{
		first = first->getNext();
		delete temp;
		temp = first;
	}

	// Update the count outside the loop.
   	count = 0;
}
//Replace the value of the second-to-last node of the calling object with the value passed by the parameter.
void AnyList::replaceSecondToLast(int paramValue)
{
    Node *current = first;
    Node *prev = nullptr;
    while (current->getNext() != nullptr) //1 2 3 4 -> null
    {
        prev = current;
        current = current->getNext();
    }
    prev->setData(paramValue);
     
    
}
void AnyList::swapSecondToLast(int paramValueToSwap)
{
    Node* current = first;
    for (int i = 0; i < count - 2; i++)
    {
        current = current->getNext();
    }
    current->setData(paramValueToSwap);
}
AnyList::~AnyList()
{
	if (first != nullptr)
		 clearList();
}
