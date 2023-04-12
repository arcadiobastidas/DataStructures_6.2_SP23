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


    friend std::ostream& operator<<(std::ostream& os, const CircularList<ItemType>& other) {
        if (other.isEmpty()) {
            os << "[]";
        } else {
            os << "[";
            
            for (int i = 0; i < other.listPtr->getLength() - 1; ++i) {
                os << other.listPtr->getEntry(i) << ", ";
            }
            os << other[other.listPtr->getLength()- 1] << "]";
        }
        return os;


    }
};// end CircularList
#endif