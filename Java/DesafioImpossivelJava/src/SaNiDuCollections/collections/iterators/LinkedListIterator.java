package SaNiDuCollections.collections.iterators;

import SaNiDuCollections.collections.Iterator;
import SaNiDuCollections.collections.LinkedList;
import SaNiDuCollections.collections.Node;
import SaNiDuCollections.exceptions.IteratorException;

public class LinkedListIterator<T> implements Iterator<T> {
    private LinkedList<T> list;
    private Node<T> node = null;

    public LinkedListIterator(LinkedList<T> list) {
        this.list = list;
    }

    @Override
    public T next() throws IteratorException {
        if (node == null) {
            node = list.getHead();
        } else {
            node = node.getNext();

            if (node == null) {
                throw new IteratorException();
            }
        }
        return node.getValue();
    }

    @Override
    public boolean hasNext() {
        if (node == null && list.getSize() > 0) {
            return true;
        }

        return node != list.getTail(); 
    }

}