#ifndef DOUBLYLIST_H
#define DOUBLYLIST_H
class DLLNode {
public:
    DLLNode() : data(0), prev(nullptr), next(nullptr) {}
    DLLNode(int newData, DLLNode *newPrev, DLLNode *newNext)
        : data(newData), prev(newPrev), next(newNext) {}
    
    int getData() const { return data; }
    DLLNode* getPrev() const { return prev; }
    DLLNode* getNext() const { return next; } 
    
    void setData (int newData) { data = newData; }
    void setPrev (DLLNode *newPrev) { prev = newPrev; }
    void setNext (DLLNode *newNext) { next = newNext; } 
    
    
    ~DLLNode() {}
private:
    int data;
    DLLNode *prev;
    DLLNode *next;
};

class DoublyList {
public:
    DoublyList() : first(nullptr), last(nullptr), count(0) {}
    void insertFirst(int newData);
    void printForward() const;
    void printReverse() const;
    void deleteNode(int data);
    void insertBack(int data);
 
    void clearList();
    ~DoublyList();


private:
    DLLNode *first;
    DLLNode *last;
    int count;
};
#endif