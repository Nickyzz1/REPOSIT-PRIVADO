public class Elemento{

    String value;
    Elemento next = null;

    Elemento(String value){
        this.value = value;
    }

    void setNext(Elemento newNext){  //muda o valor do next
        this.next = newNext;
    }

    Elemento getNext(){ //pega o valor do next
        return next;
    }


}