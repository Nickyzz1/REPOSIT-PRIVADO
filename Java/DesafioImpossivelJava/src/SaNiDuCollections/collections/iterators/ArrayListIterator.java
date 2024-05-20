package SaNiDuCollections.collections.iterators;

import SaNiDuCollections.collections.ArrayList;
import SaNiDuCollections.collections.Iterator;
import SaNiDuCollections.exceptions.IteratorException;

public class ArrayListIterator<T> implements Iterator<T>
{
    private ArrayList<T> list;
    private int index;

    public ArrayListIterator(ArrayList<T> list)
    {
        this.list = list;
        this.index = -1;
    }

    @Override
    public T next() throws IteratorException
    {
        T value = list.get(++index);

        if (null == value) {
            throw new  IteratorException();
        }
        
        return value;
    }

    @Override
    public boolean hasNext()
    {
        return index < list.getSize()-1;
    }
}