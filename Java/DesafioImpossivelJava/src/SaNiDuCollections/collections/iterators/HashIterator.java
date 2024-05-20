package SaNiDuCollections.collections.iterators;

import SaNiDuCollections.collections.Iterator;
import SaNiDuCollections.exceptions.IteratorException;
import SaNiDuCollections.collections.ArrayList;
import SaNiDuCollections.collections.LinkedList;
import SaNiDuCollections.collections.HashItem;

public class HashIterator<T> implements Iterator<T>
{
    ArrayList<LinkedList<HashItem<T>>> data;
    Iterator<LinkedList<HashItem<T>>> arrayIterator;
    Iterator<HashItem<T>> linkedListIterator;

    public HashIterator(ArrayList<LinkedList<HashItem<T>>> data)
    {
        this.data = data;

        arrayIterator = this.data.iterator();
    }

    @Override
    public T next() throws IteratorException
    {
        if (linkedListIterator == null) {
            linkedListIterator = arrayIterator.next().iterator();
        }

        while (!linkedListIterator.hasNext()) {
            if (!arrayIterator.hasNext())
                throw new IteratorException();

            linkedListIterator = arrayIterator.next().iterator();
        }

        return linkedListIterator.next().getValue();
    }

    @Override
    public boolean hasNext()
    {
        if (linkedListIterator != null && linkedListIterator.hasNext()) {
            return true;
        }

        while (arrayIterator.hasNext()) {
            try {
                linkedListIterator = arrayIterator.next().iterator();

                if (linkedListIterator.hasNext()) {
                    return true;
                }
            } catch (IteratorException e) {
                e.printStackTrace();
            }
        }

        return false;
    }
    
}