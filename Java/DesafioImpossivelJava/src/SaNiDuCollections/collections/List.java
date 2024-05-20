package SaNiDuCollections.collections;

public abstract class List<T> extends Base
{
    public abstract T get(int index);
    public abstract void set(int index, T value);
    public abstract void add(T value);
}