package SaNiDuCollections.collections;

import SaNiDuCollections.Stream;
import SaNiDuCollections.collections.iterators.HashIterator;

public class Hash<T> implements Iterable<T>
{
    ArrayList<LinkedList<HashItem<T>>> data;

    public Hash()
    {
        data = new ArrayList<LinkedList<HashItem<T>>>();
        for(int i = 0; i < 10; ++i)
        {
            data.add(new LinkedList<HashItem<T>>());
        }
    }
    public Hash(int size)
    {
        data = new ArrayList<LinkedList<HashItem<T>>>(size);
        for(int i = 0; i < size; ++i)
        {
            data.add(new LinkedList<HashItem<T>>());
        }
    }

    public void add(int key, T value)
    {
        HashItem<T> HI = new HashItem<T>(key, value);
        if(data.get(key % data.getSize()).getSize() == 10)
        {
            Hash<T> NewHash = new Hash<T>(data.getSize()*2);
            for(int i = 0; i < data.getSize(); ++i)
            {
                LinkedList<HashItem<T>> LL = data.get(i);
                for(int j = 0; j < LL.getSize(); ++j)
                {
                    NewHash.add(LL.get(i).hashCode(), LL.get(i).getValue());
                }
            }
        }
        data.get(key % data.getSize()).add(HI);
    }

    public T get(int key)
    {
        for(int i = 0; i < data.get(key % data.getSize()).getSize(); ++i)
        {
            HashItem<T> HI = data.get(key % data.getSize()).get(i);
            if(HI.getKey() == key)
            {
                return HI.getValue();
            }
        }
        return null;
    }
    

    //Método para saber se certo valor existe dentro do hash
    public boolean contains(T value){
        //Primeiro é pego o hash code do valor informado
        int key = value.hashCode();
        //Usa o key para calcular o índice no hash
        int index = key % data.getSize();
        //Pega o linked list no índice calculado
        LinkedList<HashItem<T>> list = data.get(index);
        //Verifica se o valor informado é igual ao valor existente, se for retorna true
        for (int i = 0; i < list.getSize(); i++){
            if(list.get(i).getValue().equals(value)){
                return true;
            }
        }
        //Se não, retorna false
        return false;
    }

    @Override
    public Iterator<T> iterator()
    {
        return new HashIterator<T>(data);
    }
    @Override
    public Stream<T> stream()
    {
        return null;
    }
}
