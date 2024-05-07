public class Item <type> {
    
    private Item <type> next = null;
    private type item;
    
    Item( type item ) {

        this.item = item;
        
    }

    type getItem() {

        return item;
    }

    Item <type> getNext() {  //o tipo da função é o que ele vai retornar

        return next;
    }

    void setNext(Item <type> next) {

        this.next = next;
    }
}
