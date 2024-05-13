public class LikedList {
    //add valor ao item 
    //remover
    //mostrar
    private String head = null;
    private String tail = null;
    private String next = null;
   
    void add(String value){
        Elemento item = new Elemento(value);
        if(head == null && tail == null){
            head = value;
            tail = value;
        }
        tail = value;
        next = tail;
    }

    //get
    String getHead(){
        return head;
    }

    String getTail(){
        return tail;
    }
    
    String getNext(){
        return next;
    }

    //set

    void setHead(String valueHead){
        this.head = valueHead;
    }
    void setTail(String valueTail){
        this.tail = valueTail;
    }
    void setNext(String valueNext){
        this.next = valueNext;
    }

    
}
