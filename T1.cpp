#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    List<int> list1;
    list1.insertStart(1);
    cout << list1.getFirst();
    list1.insertEnd(2);
    cout << "test" << endl;
    cout << list1.getLast();


    list1.removeStart();
    
    list1.removeEnd();
    

    return 0;
}