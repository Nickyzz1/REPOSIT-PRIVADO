import ListaItemAdcEmpregados;

class ListaEmpregados
{
    private ListaItemAdcEmpregados primeiroEmpregado = null;
    private int size = 0;

    //adc empregado a lista empregado
    void add(ClassEmpregados empregadoAdicionado)
    {
        size++;
        ListaItemAdcEmpregados item = new ListaItemAdcEmpregados
        (empregadoAdicionado); //adc o empregado adc a lista
        if (primeiroEmpregado == null) {
            primeiroEmpregado = item;
            return;
        }

        ListaItemAdcEmpregados atual = primeiroEmpregado;

        //como uma função recursiva que se o next!= vcai ver o próximo next
        while (atual.getNext() != null) {
            atual = atual.getNext();
        }
        //adc ao next, que é nulo o novo empregado
        atual.setNext(item);
    }

    
    ClassEmpregados get(int index)
    {
        ListaItemAdcEmpregados atual = primeiroEmpregado;

        for (int i = 0; i < index; i++)
            atual = atual.getNext();
        
        return atual.getEmpregado();
    }

    int getSize() {
        return size;
    }
}