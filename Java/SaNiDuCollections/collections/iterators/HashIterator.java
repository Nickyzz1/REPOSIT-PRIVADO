package SaNiDuCollections.collections.iterators;

//import SaNiDuCollections.collections.Hash;
import SaNiDuCollections.collections.Iterator;
import SaNiDuCollections.exceptions.IteratorException;
import SaNiDuCollections.collections.ArrayList;
import SaNiDuCollections.collections.LinkedList;
import SaNiDuCollections.collections.HashItem;

public class HashIterator<T> implements Iterator<T>
{
    ArrayList<LinkedList<HashItem<T>>> data;
    ArrayListIterator<LinkedList<HashItem<T>>> ALIterator;
    LinkedListIterator<HashItem<T>> LLIterator;

    public HashIterator(ArrayList<LinkedList<HashItem<T>>> data)
    {
        this.data = data;
        //ALIterator = data.iterator();
    }

    @Override
    public T next() throws IteratorException
    {
        throw new IteratorException();
    }

    @Override
    public boolean hasNext()
    {
        return false;
    }
    
}