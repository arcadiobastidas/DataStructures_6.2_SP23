﻿// The copy constructor and the method setEntry are left as exercises.
// ===================================================================

//  Created by Frank M. Carrano and Tim Henry.
//  Copyright (c) 2013 __Pearson Education__. All rights reserved.

/** Implementation file for the class LinkedList.
 @file LinkedList.cpp */

#include "LinkedList.h"  // Header file
#include <cassert>

template<class ItemType>
LinkedList<ItemType>::LinkedList() : headPtr(), itemCount(0)
{
   Node<ItemType>* dummyNode = new Node<ItemType>();
   dummyNode->setNext(dummyNode); // set the next pointer to itself
   headPtr = dummyNode; // set the head pointer to the dummy node
}
// end default constructor



template<class ItemType>
LinkedList<ItemType>::~LinkedList()
{
   clear();
}  // end destructor

template<class ItemType>
bool LinkedList<ItemType>::isEmpty() const
{
   return itemCount == 0;
}  // end isEmpty

template<class ItemType>
int LinkedList<ItemType>::getLength() const
{
   return itemCount;
}  // end getLength

template<class ItemType>
bool LinkedList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
   bool ableToInsert = (newPosition >= 1) && (newPosition <= itemCount + 1);
   if (ableToInsert) {
      Node<ItemType>* newNodePtr = new Node<ItemType>(newEntry);

      if (newPosition == 1) {
         newNodePtr->setNext(headPtr);
         headPtr = newNodePtr;
         getNodeAt(itemCount + 1)->setNext(headPtr); // update the dummy node's next pointer
      } else {
         Node<ItemType>* prevPtr = getNodeAt(newPosition - 1);
         newNodePtr->setNext(prevPtr->getNext());
         prevPtr->setNext(newNodePtr);
         if (newPosition == itemCount + 1) {
            getNodeAt(itemCount + 1)->setNext(headPtr); // update the dummy node's next pointer
         }
      }

      itemCount++;
   }

   return ableToInsert;
   
}  // end insert

template<class ItemType>
bool LinkedList<ItemType>::remove(int position)
{
   bool ableToRemove = (position >= 1) && (position <= itemCount);
   if (ableToRemove) {
      Node<ItemType>* curPtr = nullptr;
      if (position == 1) {
         curPtr = headPtr;
         headPtr = headPtr->getNext();
         getNodeAt(itemCount)->setNext(headPtr); // update the dummy node's next pointer
      } else {
         Node<ItemType>* prevPtr = getNodeAt(position - 1);
         curPtr = prevPtr->getNext();
         prevPtr->setNext(curPtr->getNext());
         if (position == itemCount) {
            getNodeAt(itemCount)->setNext(headPtr); // update the dummy node's next pointer
         }
      }

      curPtr->setNext(nullptr);
      delete curPtr;
      curPtr = nullptr;

      itemCount--;
   }

   return ableToRemove;

}  // end remove

template<class ItemType>
void LinkedList<ItemType>::clear()
{
   while (!isEmpty())
      remove(1);
}  // end clear

template<class ItemType>
ItemType LinkedList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToGet = (position >= 1) && (position <= itemCount);
   if (ableToGet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      return nodePtr->getItem();
   }
   else
   {
      string message = "getEntry() called with an empty list or "; 
      message  = message + "invalid position.";
      throw(PrecondViolatedExcep(message)); 
   }  // end if
}  // end getEntry

template<class ItemType>
Node<ItemType>* LinkedList<ItemType>::getNodeAt(int position) const
{
   assert((position >= 1) && (position <= itemCount + 1));

   if (position == itemCount + 1) {
      return headPtr; // return the dummy node
   } else {
      Node<ItemType>* curPtr = headPtr;
      for (int skip = 1; skip < position; skip++) {
         curPtr = curPtr->getNext();
      }
      return curPtr;
   }
}  // end getNodeAt

template<class ItemType>
LinkedList<ItemType>::LinkedList(const LinkedList<ItemType>& aList)
{
   itemCount = aList.itemCount;
   Node<ItemType>* origChainPtr = aList.headPtr;  // Points to nodes in original chain
 
   if (origChainPtr == nullptr)
      headPtr = nullptr;  // Original bag is empty
   else
   {
      // Copy first node
      headPtr = new Node<ItemType>();
      headPtr->setItem(origChainPtr->getItem());
 
      // Copy remaining nodes
      Node<ItemType>* newChainPtr = headPtr;      // Points to last node in new chain
      origChainPtr = origChainPtr->getNext();     // Advance original-chain pointer
 
      while (origChainPtr != nullptr)
      {
         // Get next item from original chain
         ItemType nextItem = origChainPtr->getItem();
 
         // Create a new node containing the next item
         Node<ItemType>* newNodePtr = new Node<ItemType>(nextItem);
 
         // Link new node to end of new chain
         newChainPtr->setNext(newNodePtr);
 
         // Advance pointer to new last node
         newChainPtr = newChainPtr->getNext();
 
         // Advance original-chain pointer
         origChainPtr = origChainPtr->getNext();
      }  // end while
 
      newChainPtr->setNext(nullptr);              // Flag end of chain
   }  // end if
}  // end copy constructor
template<class ItemType>
void LinkedList<ItemType>::setEntry(int position, const ItemType& newEntry)  throw(PrecondViolatedExcep)
{
   // Enforce precondition
   bool ableToSet = (position >= 1) && (position <= itemCount);
   if (ableToSet)
   {
      Node<ItemType>* nodePtr = getNodeAt(position);
      nodePtr->setItem(newEntry);
   }
   else
   {
      string message = "setEntry() called with an invalid position.";
      throw(PrecondViolatedExcep(message));
   } // end if
} // end setEntry

template<class ItemType>
void LinkedList<ItemType>::display() const{
 
   for (int skip = 1; skip <= itemCount; skip++){
      cout << getEntry(skip) << endl;
   }//end for
}


//  End of implementation file.
