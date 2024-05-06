public class ListaEmpregados {

    private ListaItemAdcEmpregados primeiroEmpregado = null;
    private int size = 0;

    // adc empregado a lista empregado

   public void add(ClassEmpregados empregadoAdicionado) {

        size++;
        ListaItemAdcEmpregados item = new ListaItemAdcEmpregados(empregadoAdicionado);
    
        if (primeiroEmpregado == null) {
            // Se a lista estiver vazia, definir o novo item como o primeiro
            primeiroEmpregado = item;
        } else {
            // Se a lista não estiver vazia, percorrer até o final e adicionar o novo item lá
            ListaItemAdcEmpregados atual = primeiroEmpregado;
            while (atual.getNext() != null) {
                atual = atual.getNext();
            }
            // Adiciona o novo item após o último item da lista
            atual.setNext(item);
        }
    }
    

    public ClassEmpregados get(int index)
    {
        ListaItemAdcEmpregados atual = primeiroEmpregado;

        for (int i = 0; i < index; i++)
        {
            atual = atual.getNext();
        }

        return atual.getEmpregado();
    }

    public int getSize() 
    {
        return size;
    }

    public void mostrarEmpregados() 
    {
        ListaItemAdcEmpregados atual = primeiroEmpregado;

        System.out.println("\n\nLista de empregados:");

        for(int i =0; i <size; i++){

            System.out.println("\n\nNome: " + atual.getEmpregado().getNome());
            System.out.println("CPF: " + atual.getEmpregado().getCpf());
            System.out.println("Data de nascimento: " + atual.getEmpregado().getDataNascimento());
            System.out.println("Senha: " + atual.getEmpregado().getSenha());
            System.out.println("Administrador: " + atual.getEmpregado().getIsadm());
            System.out.println();
            atual = atual.getNext();

        }
       
    }

    public void fazerLogin(String cpf, int senha) 
    {
        ListaItemAdcEmpregados atual = primeiroEmpregado;
        boolean usuarioEncontrado = false;
    
        while (atual != null) 
        {
            ClassEmpregados empregado = atual.getEmpregado();
    
            // Verifica se o CPF fornecido corresponde ao CPF do empregado atual
            if (empregado.getCpf().equals(cpf)) 
            {
                // Se o CPF corresponde, verifica se a senha corresponde à senha do empregado
                if (empregado.getSenha().equals(senha)) 
                {
                    // Se a senha corresponder, o usuário é encontrado
                    usuarioEncontrado = true;
                    System.out.println("\n\nLogin bem-sucedido!");
                     break;
                }
    
            // Avança para o próximo empregado na lista
            atual = atual.getNext();
            }
            // Se o usuário não foi encontrado, exibe uma mensagem de erro
            if (!usuarioEncontrado) 
            {
                System.out.println("\n\nUsuário não encontrado.");
                break;
            }
        }
    }   
}
