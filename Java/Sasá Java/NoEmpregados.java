package oldPonto;

class NoEmpregados
{
    // Atributos são variáveis e métodos são funções

    // Atributo next
    private NoEmpregados next = null;

    // Funções get e set
    
    // Get retorna o próximo nó da lista
    NoEmpregados getNext() {
        return next;
    }
    // Set define o próximo nó da lista
    void setNext(NoEmpregados next) {
        this.next = next;
    }

    // Objeto Empregado. Esta variável representa os dados que serão armazenados no nó da lista encadeada.
    private Empregado value;

    // Esse método retorna o objeto 'Empregado' armazenado no nó da lista encadeada
    Empregado getEmpregado() {
        return value;
    }

    // Construtor
    // Esse método recebe como parâmetro o objeto 'Empregado' e o armazena no atributo 'value'
    NoEmpregados(Empregado value) {
        this.value = value;
    }
}
