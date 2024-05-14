public class Hash
{
    private LinkedList[] Data;
    private int Size;

    Hash()
    {
        Data = new LinkedList[10];
        Size = 10;
        for(int i = 0; i < Size; ++i)
        {
            Data[i] = new LinkedList();
        }
    }

    Hash(int Size)
    {
        Data = new LinkedList[Size];
        this.Size = Size;
        for(int i = 0; i < Size; ++i)
        {
            Data[i] = new LinkedList();
        }
    }

    void Add(Integer Value)
    {
        Data[Value % Size].Add(Value);
    }

    boolean Search(Integer Value)
    {
        return Data[Value % Size].Search(Value);
    }
}