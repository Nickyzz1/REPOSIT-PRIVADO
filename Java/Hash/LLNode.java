public class LLNode
{
    private LLNode Next = null;
    private Integer Value;

    LLNode(Integer Value)
    {
        this.Value = Value;
    }
    
    Integer GetValue()
    {
        return Value;
    }

    LLNode GetNext()
    {
        return Next;
    }
    
    void SetNext(LLNode Next)
    {
        this.Next = Next;
    }
}