public class ListaGenerica <Type> {
    private Type[] lista; // No lugar de Integer, coloque Type
    private int index = 0; // Usando int em vez de Integer para o índice

    ListaGenerica() {
        lista = (Type[]) new Object[10]; // Mudança para Type[]
    }

    void add(Type value) {
        if(index == lista.length) { // Adicionando chaves ao redor do bloco if
            Type[] copy = (Type[]) new Object[lista.length * 2]; // Corrigindo a declaração e a inicialização
            for(int i = 0; i < lista.length; i++) {
                copy[i] = lista[i];
            }
            lista = copy;
        }

        lista[index] = value;
        index++;
        get(index); // Este método não está sendo usado corretamente, o índice deveria ser index - 1
    }

    Type get(int indexGet) { // Mudando o retorno para Type
        if(indexGet >= index || indexGet < 0) { // Adicionando verificação para índice negativo
            return null;
        }
        return this.lista[indexGet]; 
    }
}
