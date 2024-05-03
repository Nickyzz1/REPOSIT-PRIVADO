import java.util.Scanner;

public class main {
    public static void main(String[] args)
    {
        //fiz um scanner para poder ler os inputs
        Scanner scan = new Scanner(System.in);
        
        //criei empregados provisórios
        ClassEmpregados emp0 = new ClassEmpregados("nicolle","1234567890", "26/02/2006", 123, true);
        ClassEmpregados emp1 = new ClassEmpregados("jorge","1234567890", "26/02/2006", 123, false);

        //criou uma var que guardará o novo item da lista de empregados
        ListaEmpregados varEmpregadosLista = new ListaEmpregados();  

        //adc o novo item na lista de empregados
        varEmpregadosLista.add(emp0);
        varEmpregadosLista.add(emp1);

        //crio as variáveis que guardarão os inputs
        String cpf;
        Integer senha;

        System.out.printf("----------BEM VINDO--------");
        
        //print
        System.out.printf("\n\nDigite o seu cpf: ");
        cpf = scan.nextLine();
        System.out.printf("\nDigite sua senha: ");
        senha = scan.nextInt();

        //var logado para guardar quem é que está acessando o sistema de pontos
        ClassEmpregados logado = null;

        //loop que irá percorrer a o tamanho inteiro da lista
        for (int i = 0; i < varEmpregadosLista.getSize(); i++)
        {
            //tipo da var emp é ClassEmpregados e ela gaudar o index do empregado na lista
            ClassEmpregados indexEmp = varEmpregadosLista.get(i);

            if (indexEmp.cpf.equals(cpf) && indexEmp.senha.equals(senha))
            {
                logado = indexEmp;
                break;
            }
        }
        
        if (logado == null) {
            System.out.println("Usuário não encontrado.");
            return;
        }
    
        ponto login = new ponto();
        
    }
}
