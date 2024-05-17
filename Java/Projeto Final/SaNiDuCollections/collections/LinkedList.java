package SaNiDuCollections.collections;

import SaNiDuCollections.Stream;
import SaNiDuCollections.collections.iterators.LinkedListIterator;

public class LinkedList<T> extends List<T> implements Iterable<T>
{
    Node<T> head = null;
    Node<T> tail = null;
    // private int size;

    //add items
    
    void add(T value)
    {
        Node<T> item = new Node<T>(value);

        if(head == null && tail == null)
        {
            
            head = item;
            tail = item;
        }else
        {
            tail.setNext(item);
            tail = item;
        }
        ++size;
    }

    //retornar por index

    T get(int index)
    {
        if(index > size){return null;}
        Node<T> current = head;

        while(index != 0)
        {
            --index;
            current = current.getNext();
        }
        return current.getValue();
    }

    //mudando o valor em um certo index
    void set(int index, T value)
    {
        Node<T> current = head;
        while(index != 0)
        {
            --index;
            current = current.getNext();
        }
        current.setValue(value);
    }

    //getter e setters

    public Node<T> getHead() {
        return head;
    }

    public void setHead(Node<T> head) {
        this.head = head;
    }

    public Node<T> getTail() {
        return tail;
    }

    public void setTail(Node<T> tail) {
        this.tail = tail;
    }
    
    @Override
    public Iterator<T> iterator()
    {
        return new LinkedListIterator<T>(this);
    }
    
    @Override
    public Stream<T> stream()
    {
        return null;
    }
}
