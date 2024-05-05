import java.util.Scanner;

public class Main {
    public static void main(String args[]) {
        ListaEmpregados listaEmpregados = new ListaEmpregados();
        Scanner scan = new Scanner(System.in);
        String nome;
        String cpf;
        String dataNascimento;
        Integer senha;
        boolean isadm;

        int escolha;
        int fla = 1;
        while (fla == 1) {

            System.out.printf("%s", "|-------------BEM VINDO---------------|\n1 - cadastrar usuário\n2-logar\n3-bater ponto\n4-ver pontos\n5-ver empregados\n\nDIGITE A OPÇÃO DESEJADA: ");
            escolha = scan.nextInt();

            scan.nextLine(); // Consumindo a quebra de linha pendente

            if (escolha == 1) {
                System.out.print("Nome do empregado: ");
                nome = scan.nextLine();
                System.out.print("CPF do empregado (será utilizado para login): ");
                cpf = scan.nextLine();
                System.out.print("Data de nascimento do empregado: ");
                dataNascimento = scan.nextLine();
                System.out.print("Senha: ");
                senha = scan.nextInt();
                System.out.print("É administrador? Digite true ou false: ");
                isadm = scan.nextBoolean();
                ClassEmpregados emp = new ClassEmpregados(nome, cpf, dataNascimento, senha, isadm);
                listaEmpregados.add(emp);
            }
            if (escolha == 5) {
                listaEmpregados.mostrarEmpregados();
                fla=0;
            }
        }
        scan.close();
    }
}
