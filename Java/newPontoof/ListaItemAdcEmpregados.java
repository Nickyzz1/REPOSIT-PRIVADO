public class ListaItemAdcEmpregados {
    // cria a var que representará 1 empregado
    private ClassEmpregados unidadeDeEmpregado;

    // Construtor que eu adc um empregado como parÂmetro para colocar na lista
    public ListaItemAdcEmpregados(ClassEmpregados novoEmpregadoNaLista) {
        this.unidadeDeEmpregado = novoEmpregadoNaLista;
        // define 1 empregado como o novo empregado
    }

    // retorna o empregado
    public ClassEmpregados getEmpregado() {
        return unidadeDeEmpregado;
    }

    // define next com nulo primeiramente
    private ListaItemAdcEmpregados next = null;

    // coloca um valor no next(que é o próximo elemento), dado como parâmetro na main
    public void setNext(ListaItemAdcEmpregados next) {
        this.next = next;
    }

    // quando rodar, vai retornar o next;
    public ListaItemAdcEmpregados getNext() {
        return next;
    }
}
