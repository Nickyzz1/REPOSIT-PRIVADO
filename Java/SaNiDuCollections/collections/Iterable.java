package SaNiDuCollections.collections;

import SaNiDuCollections.Stream;

public interface Iterable<T>{

    //declaração de métodos, o corpo deve estar nos arquivos que usam a interface
    Iterator<T> iterator();
    Stream<T> stream();

}
