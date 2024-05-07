public class Fila <type>{

    // a fila deve guardar os itens um atrás do outro
    //estanos criando o item e apontado para os outros, não criando uma estrutura únixca como uma lista, apenas apontando onde está o que deveria se ro próximo no enderço de memória
    //saber o tamanho
    //primeiro e último
    //para não processar a lista inteira ao fazer os métodos enqueeue, dequeue, peek, e size que mexem apenaS COM O PRIMEIRO E O ÚLTIMO preciso apenas saber o priemiro e o último(na stcak);
    int size;
    Item <type> head = null;
    Item <type> tail = null;

    void enqueue(type itemParameter) {

        size++;
        Item <type> item = new Item <type> (itemParameter); //chama o construtor da classde Item //colocando o parâmetro dado no item dessa função fila e no item da classe Item;

        if(tail == null) { // se tail for nulo não há itens na lista, então o item adc seria o primeiro e o último ao nmesmo tempo;
            head = item;
            tail = item;
            return;
        }
        tail.setNext(item); //tem um item depois do que anteirormente era o último logo
        tail = item; //precisamos colocar tail como o item que acabamos de adc, afinal, precisamos sa=ber o valor do ultimo de do primeiro
    }

    type dequeue() {
        if( head == null) {
            return null;
        }

        size--;
        type temp = head.getItem();

        if(head.getNext() == null) {

            head = null;
            tail = null;

        } else {

            head = head.getNext(); // agora head é igual e next
        }

        return temp;
    }
    
    type peek() {
        
        return head.getItem();
    }

    int size(){

        return size;
    }
    
}

