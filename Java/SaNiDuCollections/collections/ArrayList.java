package SaNiDuCollections.collections;

import SaNiDuCollections.Stream;
import SaNiDuCollections.collections.iterators.ArrayListIterator;

@SuppressWarnings("unchecked")
public class ArrayList<T> extends List<T> implements Iterable<T>
{
    // Construtor padrão, inicializa a lista com 10 posições
    protected T[] data;
    public ArrayList(){
        data = (T[]) new Object[10];
    }
    public ArrayList(int size){
        data = (T[]) new Object[size];
    }

    // Seta o elemento da posição informada para o valor informado
    public void set(int index, T value){
        data[index] = value;
    }

    // Retorna o valor que existe na posição informada
    public T get(int index){
        if(index >= size || index < 0){
            return null;
        }
        return data[index];
    }

    // Adiciona um elemento no final do vetor e aumenta ele caso não tenha mais espaço
    public void add(T value){
        if (size == data.length){
            T[ ] copy = (T[]) new Object[data.length * 2];

            for (int i = 0; i < size; i++){
                copy[i] = data[i];
            }
            data = copy;
        }
        data[size] = value;
        size++;
    }

    @Override
    public Iterator<T> iterator()
    {
        return new ArrayListIterator<T>(this);
    }

    @Override
    public Stream<T> stream()
    {
        return null;
    }
}