package SaNiDuCollections.collections;

public class HashItem<T>
{
    private int key;
    private T value;

    public HashItem(int key, T value)
    {
        this.key = key;
        this.value = value;
    }

    public int getKey() {
        return key;
    }
    public void setKey(int key) {
        this.key = key;
    }
    public T getValue() {
        return value;
    }
    public void setValue(T value) {
        this.value = value;
    }
    
}
