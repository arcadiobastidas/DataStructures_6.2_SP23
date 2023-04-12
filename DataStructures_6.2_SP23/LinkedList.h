//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** ADT list: Link-based implementation.
    Listing 9-2.
    @file LinkedList.h */

#ifndef _LINKED_LIST
#define _LINKED_LIST
#include <iostream>
#include "ListInterface.h"
#include "Node.cpp"
#include "PrecondViolatedExcep.h"

using namespace std;

template<class ItemType>
class LinkedList : public ListInterface<ItemType>
{
private:
    Node<ItemType>* headPtr; // Pointer to first node in the chain;
    // (contains the first entry in the list)
    int itemCount;           // Current count of list items 
   
    // Locates a specified node in this linked list.
    // @pre  position is the number of the desired node;
    //       position >= 1 and position <= itemCount.
    // @post  The node is found and a pointer to it is returned.
    // @param position  The number of the node to locate.
    // @return  A pointer to the node at the given position.
    Node<ItemType>* getNodeAt(int position) const;

public:
    LinkedList();
    LinkedList(const LinkedList<ItemType>& aList);
    virtual ~LinkedList();

    bool isEmpty() const override;
    int getLength() const override;
    bool insert(int newPosition, const ItemType& newEntry) override;
    bool remove(int position) override;
    void clear() override;
   
    /** @throw PrecondViolatedExcep if position < 1 or 
                                       position > getLength(). */
    ItemType getEntry(int position) const throw(PrecondViolatedExcep) override;

    /** @throw PrecondViolatedExcep if position < 1 or 
                                       position > getLength(). */
    void setEntry(int position, const ItemType& newEntry)
                                throw(PrecondViolatedExcep) override;

    void display() const;
}; // end LinkedList


#endif 
