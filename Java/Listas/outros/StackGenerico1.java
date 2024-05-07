package outros;
@SuppressWarnings("unchecked")
public class StackGenerico1 <type> {

    int size = 0;
    type lista[];
    
    StackGenerico1() {

        lista = (type[]) new Object[3];
    }

    void add(type item) {

        if(size == lista.length) {
            type copy[] = (type[]) new Object[lista.length*2];
            for(int i = 0; i < lista.length; i++) {
                copy[i] = lista[i];
            }
            lista = copy;
        }

        lista[size] = item;
        size++;

    }

    void mostrar() {

        System.out.printf("Lista: ");
        for(int i = 0; i <lista.length; i++) {
            if(lista[i] != null) {
                System.out.printf("[%d]", lista[i]);
            }
        }
    }

    void push(type number) {
        //aumentar a lista em 1 a cada push
        //colocar na posição 0 o número
        type listaMaior[] = (type[]) new Object[lista.length + 1];
        listaMaior[0] = number;
        for(int i = 1; i < lista.length; i++) {
            listaMaior[i] = lista[i-1];
        }
        lista = listaMaior;
    }
    void pop(){

        System.out.printf("The pop remove: [%d]\n", lista[0]);
        type listaMenor[] = (type[]) new Object [lista.length - 1];
        for(int i = 0; i <lista.length - 1 ; i++) {
            listaMenor[i] = lista[i+1]; 
        }
        lista = listaMenor;

        // //mosytrando a lista com o pop
        // for(int i = 0 ; i < lista.length; i++) {
        //     System.out.printf("%d", lista[i]);
        // }

    }

    void peek() {

        System.out.printf("Peek lista[0]: %d\n", lista[0]);
    }
    void size() {
        System.out.printf("Size : %d\n" , lista.length);
    }
    
    
}
