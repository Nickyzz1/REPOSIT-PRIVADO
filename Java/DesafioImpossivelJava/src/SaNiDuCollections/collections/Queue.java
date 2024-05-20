package SaNiDuCollections.collections;

//import SaNiDuCollections.collections.iterators.QueueIterator;

public class Queue<T> extends LinkedList<T>  {
    public Queue() {
        super();
    }

    public void enqueue(T value) {
        super.add(value);
    }

    public T dequeue() {
        if (head == null) {
            return null;
        }

        --size;

        Node<T> Node = head;

        if (head.getNext() == null) {
            head = null;
            tail = null;
        } else {
            head = head.getNext();
        }

        return Node.getValue();
        
    }

    /*@Override
    public Iterator<T> iterator() {
        return new QueueIterator<>(this);
    }*/
}