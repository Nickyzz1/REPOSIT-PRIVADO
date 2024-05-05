public class ListaEmpregados {
    private ListaItemAdcEmpregados primeiroEmpregado = null;
    private int size = 0;

    // adc empregado a lista empregado
    public void add(ClassEmpregados empregadoAdicionado) {
        size++;
        ListaItemAdcEmpregados item = new ListaItemAdcEmpregados(empregadoAdicionado); // adc o empregado adc a lista
        if (primeiroEmpregado == null) {
            primeiroEmpregado = item;
        }

        ListaItemAdcEmpregados atual = primeiroEmpregado;

        // como uma função recursiva que se o next!= vcai ver o próximo next
        while (atual.getNext() != null) {
            atual = atual.getNext();
        }
        // adc ao next, que é nulo o novo empregado
        atual.setNext(item);
    }

    public ClassEmpregados get(int index) {
        ListaItemAdcEmpregados atual = primeiroEmpregado;

        for (int i = 0; i < index; i++)
            atual = atual.getNext();

        return atual.getEmpregado();
    }

    public int getSize() {
        return size;
    }

    public void mostrarEmpregados() {
        ListaItemAdcEmpregados atual = primeiroEmpregado;

        System.out.println("Lista de empregados:");
        while (atual != null) {
            System.out.println("Nome: " + atual.getEmpregado().getNome());
            System.out.println("CPF: " + atual.getEmpregado().getCpf());
            System.out.println("Data de nascimento: " + atual.getEmpregado().getDataNascimento());
            System.out.println("Senha: " + atual.getEmpregado().getSenha());
            System.out.println("Administrador: " + atual.getEmpregado().getIsadm());

            System.out.println();
            atual = atual.getNext();
        }
    }
}
