package oldPonto;

public class ListaEmpregados {
    // Atributo da classe que representa o primeiro nó da lista encadeada. Ele começa com null pq a lista está vazia.
    private NoEmpregados head = null;
    // Atributo que armazena o tamanho da lista.
    private int size = 0;

    // Essa função adiciona um novo empregado à lista, se a lista estiver vazia, ele cria um novo nó com o empregado fornecido, senão, ele procura o último nó e define o próximo como o novo.
    void add(Empregado empregado){
        // Soma mais 1 ao tamanho da lista.
        size++;
        // Essa linha de código cria um novo nó na lista encadeada, que contém as informações do empregado fornecido como argumento para o construtor.
        NoEmpregados node = new NoEmpregados(empregado);

        // Se a lista estiver vazia, ele define o primeiro índice como 'node', que é uma variável que armazena os dados do novo empregado
        if (head == null){
            head = node;
            return;
        }
        // Declara uma variável chamada 'atual' e inicializa com o valor do primeiro nó da lista, que no momento está armazenado na 'head'. Agora 'atual' aponta para o início da lista.
        NoEmpregados atual = head;
        // Inicia um loop que procura pela lista até que o valor seja 'null'
        while (atual.getNext() != null){
            // 'atual' vai passando de posição em posição até que ela seja 'null', o método 'getNext' está na classe NoEmpregados.
            atual = atual.getNext();
        }

        // Depois de sair do loop, 'atual' contém o último nó da lista, então essa linha adiciona 'node' (que é uma variável que contém os dados do novo empregado) no último índice da lista
        atual.setNext(node);
    }
    // Empregado get(int index){

    // }

    // Retorna o tamanho da lista
    int getSize(){
        return size;
    }

    // Método para conferir se os dados do usuário existem na lista
    void conferirDados(String cpfUsuario, String senhaUsuario){
        // Criando uma instância para poder usar um método de outra classe
        Empregado empregado = new Empregado();

        int tamanho = getSize();
        cpfUsuario = empregado.getCpf();
        senhaUsuario = empregado.getSenha();

        // For para percorrer cada índice da lista e conferir os dados
        int posicaoAtual = 0;
        for(int i = 0; i<tamanho;i++){
            // Descobrir pq isso ta errado:
            // posicaoAtual = posicaoAtual.getNext();
        }
    }
}
