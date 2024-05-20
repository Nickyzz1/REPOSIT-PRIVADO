package SaNiDuCollections.collections;

import SaNiDuCollections.Stream;

public interface Iterable<E>{

    //declaração de métodos, o corpo deve estar nos arquivos que usam a interface
    public Iterator<E> iterator();
    public Stream<E> stream();


}
