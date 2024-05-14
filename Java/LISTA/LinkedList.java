public class LinkedList {

    //preciso poder add
    //preciso poder remover
    //poreciso poder ver o item

    private Elemento head = null;
    private Elemento tail = null;

    void add(String value)
    {

        Elemento item = new Elemento(value); //crio lo item, a partird e agora só trabalho com ele
        if(head == null && tail == null)
        {
            head = item;
            tail = item;

        }
        tail.setNext(item); ///tail aponta para o último , pois o next apostan para o último
        tail = item; //deppis eu mudo o valu do tail
    }

    //get

    Elemento getHead(){
        return head;
    }

    Elemento getTail(){
        return tail;
    }

    //set

    void setHead(Elemento newHead){
        this.head = newHead;
    }

    void setTail(Elemento newTail){
        this.tail = newTail;
    }  
    
}
