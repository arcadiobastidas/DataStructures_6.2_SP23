#ifndef CIRCULAR_LIST_H
#define CIRCULAR_LIST_H

#include "LinkedList.h"

template<class ItemType>
class CircularList
{
private:
    LinkedList<ItemType>* listPtr;  // Pointer to the circular linked list
public:
    CircularList();
    ~CircularList();
    bool isEmpty() const;
    int getLength() const;
    bool insert(int newPosition, const ItemType& newEntry);
    bool remove(int position);
    void clear();
    ItemType getEntry(int position) const throw(PrecondViolatedExcep);


};
#endif