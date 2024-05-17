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
        try
        {
            return list.get(++index);
        }
        catch(Exception e)
        {
            throw new IteratorException();
        }
    }

    @Override
    public boolean hasNext()
    {
        return list.getSize() >= index + 1;
    }
}