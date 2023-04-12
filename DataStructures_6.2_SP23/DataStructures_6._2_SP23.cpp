#include <iostream>
#include "LinkedList.cpp"
#include "Node.h"
#include "PrecondViolatedExcep.h"


using namespace std;

int main()
{

    LinkedList<int> *integerList = new LinkedList<int>();

    integerList->insert(1,1);
    integerList->display();



    return 0;
}
