#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    cout << "test";
    List<int> list1;
    
    list1.insertStart(1);
    cout << list1.getFirst();
    list1.insertEnd(2);
    cout << list1.getLast();
    list1.insertAt(3,2);
    cout << list1.getAt(2);


    list1.removeAt(2);

    

    return 0;
}