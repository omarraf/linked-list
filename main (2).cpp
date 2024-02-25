#include "DoublyList.h"
#include "AnyList.h"
#include <iostream>
using namespace std;

int main()
{
    AnyList AL;
    for (int i = 10; i > 0; i--)
    {
        AL.insertFront(i);
    }
    
    AL.print();
    return 0;
}
