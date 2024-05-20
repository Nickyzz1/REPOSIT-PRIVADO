package SaNiDuCollections;

import java.util.function.Function;

import SaNiDuCollections.collections.ArrayList;
import SaNiDuCollections.collections.Iterator;
import SaNiDuCollections.collections.LinkedList;
import SaNiDuCollections.exceptions.IteratorException;
import SaNiDuCollections.collections.Iterable;

public class Stream<E>
{
    Iterable<E> iterable;

    public Stream(Iterable<E> iterable) {
        this.iterable = iterable;
    }

    public <R> Stream<R> map(Function<E, R> function) throws IteratorException {
        LinkedList<R> data = new LinkedList<>();

        Iterator<E> iterator = iterable.iterator();

        while (iterator.hasNext()) {
            data.add(function.apply(iterator.next()));
        }

        return new Stream<R>(data);
    }

    public Stream<E> filter(Function<E, Boolean> function) throws IteratorException {
        LinkedList<E> data = new LinkedList<>();
        
        Iterator<E> iterator = iterable.iterator();

        while (iterator.hasNext()) {
            E e = iterator.next();

            if (function.apply(e)) {
                data.add(e);
            }
        }
        

        return new Stream<E>(data);
    }

    public ArrayList<E> collect() throws IteratorException {
        ArrayList<E> list = new ArrayList<>();

        Iterator<E> iterator = iterable.iterator();

        while (iterator.hasNext()) {
            list.add(iterator.next());
        }

        return list;
    }
    
}
