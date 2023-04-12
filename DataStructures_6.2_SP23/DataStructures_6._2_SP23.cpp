#include <iostream>
#include "LinkedList.cpp"
#include "Node.h"
#include "PrecondViolatedExcep.h"
#include "CircularList.cpp"

using namespace std;

int main()
{

    LinkedList<int> *integerList = new LinkedList<int>();
    CircularList<int> *circularList = new CircularList<int>();
    circularList->insert(1,2);
    
    
    integerList->insert(1,1);
    integerList->display();
    cout << circularList;



    return 0;
}
