package SaNiDuCollections.collections.iterators;

import SaNiDuCollections.collections.Iterator;
import SaNiDuCollections.collections.LinkedList;
import SaNiDuCollections.collections.Node;
import SaNiDuCollections.exceptions.IteratorException;

public class LinkedListIterator<T> implements Iterator<T>
{
    private LinkedList<T> list;
    private Node<T> node = null;

    public LinkedListIterator(LinkedList<T> list)
    {
        this.list = list;
    }

    @Override
    public T next() throws IteratorException
    {
        try
        {
            if(node != null)
            {
                node = node.getNext();
            }else
            {
                node = list.getHead();
            }
            return node.getValue();
        }
        catch(Exception e)
        {
            throw new IteratorException();
        }
    }

    @Override
    public boolean hasNext()
    {
        return node.getNext() != null;
    }
    
}