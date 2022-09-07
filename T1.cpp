#include "ListStack.h"
#include "List.h"
#include "Node.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

int main()
{
    ListStack<int> list1;

    for(int i = 0; i < 10; i++){
        list1.push(i);
    }
    int j = list1.pop();
    int k = list1.pop();

    list1.print("woop");



   

    return 0;
}