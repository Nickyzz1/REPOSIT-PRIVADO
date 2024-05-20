package SaNiDuCollections.collections;

import SaNiDuCollections.exceptions.IteratorException;

public interface Iterator<T>
{
    public T next() throws IteratorException;
    public boolean hasNext();

}