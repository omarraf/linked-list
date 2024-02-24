#include "DoublyList.h"
#include "AnyList.h"
#include <iostream>
using namespace std;

int main()
{
    
    DoublyList DLL;
    AnyList AL;
    for (int i = 10; i > 0; i--)
    {
        AL.insertFront(i);
    }
    
    
    AL.print();
    cout << "\nExpected Result: 1 2 3 4 5 6 7 8 55 10 \n";
    AL.replaceSecondToLast(55);
    AL.print();
    
    return 0;
}
