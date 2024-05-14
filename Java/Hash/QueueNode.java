public class QueueNode<Type>
{
    private QueueNode<Type> Next = null;
    private Type Value;

    QueueNode(Type Value)
    {
        this.Value = Value;
    }
    
    Type GetObject()
    {
        return Value;
    }

    QueueNode<Type> GetNext()
    {
        return Next;
    }
    
    void SetNext(QueueNode<Type> Next)
    {
        this.Next = Next;
    }
}