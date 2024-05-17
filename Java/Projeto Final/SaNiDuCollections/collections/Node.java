package SaNiDuCollections.collections;

public class Node<T> {

    // Objeto do tipo T, representa dos valores que serão armazenados no nó da lista
    private T value;
    // Atributo next
    private Node<T> next;

    // Construtor da classe
    public Node(T value) {
        this.value = value;
        this.next = null;
    }

    public T getValue() {
        return value;
    }

    public void setValue(T value) {
        this.value = value;
    }

    public Node<T> getNext() {
        return next;
    }

    public void setNext(Node<T> next) {
        this.next = next;
    }
}
