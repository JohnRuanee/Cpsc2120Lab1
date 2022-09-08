#include <iostream>


using namespace std;

int main()
{
    
    double total;
    for(double i = 1; i < 1000000; i++){
        total = total + (1/(i*i));

    }
    cout << total << endl;
   

    return 0;
}