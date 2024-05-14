public class Queue<Type>
{
    private QueueNode<Type> Head = null;
    private QueueNode<Type> Tail = null;
    private int Size = 0;

    void Enqueue(Type Value)
    {
        ++Size;
        QueueNode<Type> Node = new QueueNode<Type>(Value);
        if(Head == null)
        {
            Head = Node;
            Tail = Node;
            return;
        }
        Tail.SetNext(Node);
        Tail = Node;
    }

    Type Dequeue()
    {
        if(Head == null){return null;}
        --Size;
        QueueNode<Type> Node = Head;
        if(Head.GetNext() == null)
        {
            Head = null;
            Tail = null;
        }else
        {
            Head = Head.GetNext();
        }
        return Node.GetObject();
    }

    Type Peek()
    {
        if(Head == null){return null;}
        return Head.GetObject();
    }

    int Size()
    {
        return Size;
    }
}