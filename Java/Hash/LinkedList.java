public class LinkedList
{
    private LLNode Head = null;
    private int Size = 0;

    void Add(Integer Value)
    {
        ++Size;
        LLNode Node = new LLNode(Value);
        if(Head == null)
        {
            Head = Node;
            return;
        }
        LLNode Current = Head;
        while(Current.GetNext() != null)
        {
            Current = Current.GetNext();
        }
        Current.SetNext(Node);
    }

    boolean Search(Integer Value)
    {
        LLNode N = Head;
        while(N != null)
        {
            if(N.GetValue() == Value){return true;}
            N = N.GetNext();
        }
        return false;
    }

    Integer Get(int index)
    {
        if(index > Size){return null;}
        LLNode Current = Head;
        while(index != 0)
        {
            --index;
            Current = Current.GetNext();
        }
        return Current.GetValue();
    }

    int getSize()
    {
        return Size;
    }
}