package SaNiDuCollections.collections;

public class Queue<T> extends LinkedList<T>
{
    public Queue()
    {
        super();
    }

    public void enqueue(T value)
    {
        super.add(value);
    }

    public T dequeue()
    {
        if(head == null){return null;}
        --size;
        Node<T> Node = head;
        if(head.getNext() == null)
        {
            head = null;
            tail = null;
        }else
        {
            head = head.getNext();
        }
        return Node.getValue();
        /*LinkedList<T> linkedList = new LinkedList<>();
        for(int i = 0; i < size-1; i++){
            linkedList.set(i, linkedList.get(i+1));
        }
        size--;

        return null;*/
    }
}