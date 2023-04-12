#include "CircularList.h"
template<class ItemType>
CircularList<ItemType>::CircularList() : listPtr(new LinkedList<ItemType>())
{
}

template<class ItemType>
CircularList<ItemType>::~CircularList()
{
    clear();
}

template<class ItemType>
bool CircularList<ItemType>::isEmpty() const
{
    return listPtr->isEmpty();
}

template<class ItemType>
int CircularList<ItemType>::getLength() const
{
    return listPtr->getLength();
}

template<class ItemType>
bool CircularList<ItemType>::insert(int newPosition, const ItemType& newEntry)
{
    bool isInserted = false;

    if (newPosition >= 1 && newPosition <= getLength() + 1)
    {
        isInserted = listPtr->insert(newPosition, newEntry);
    }

    return isInserted;
}

template<class ItemType>
bool CircularList<ItemType>::remove(int position)
{
    bool isRemoved = false;

    if (position >= 1 && position <= getLength())
    {
        isRemoved = listPtr->remove(position);
    }

    return isRemoved;
}

template<class ItemType>
void CircularList<ItemType>::clear()
{
    while (!isEmpty())
    {
        remove(1);
    }
}

template<class ItemType>
ItemType CircularList<ItemType>::getEntry(int position) const throw(PrecondViolatedExcep)
{
    return listPtr->getEntry(position);
}