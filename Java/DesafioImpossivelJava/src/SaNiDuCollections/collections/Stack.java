package SaNiDuCollections.collections;

//import SaNiDuCollections.collections.iterators.StackIterator;

public class Stack<T> extends ArrayList<T>
{
    // Construtor
    public Stack()
    {
        super();
    }

    public Stack(int size)
    {
        super(size);
    }

    // Adiciona um novo elemento na lista
    public void push(T value)
    {
        super.add(value);
    }

    // Tira o último elemento da lista
    public T pop()
    {
        T value = data[--size];

        data[size] = null;

        return value;
    }

    /*@Override
    public Iterator<T> iterator() {
        return new StackIterator<>(this);
    }*/

}