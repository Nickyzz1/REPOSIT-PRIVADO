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

            System.out.printf("%s", "--------BEM VINDO-------\n\n|1-cadastrar usuário    |\n|2-logar                |\n|3-bater ponto          |\n|4-ver pontos           |\n|5-ver empregados       |\n|0-SAIR                 |\n\nDIGITE A OPÇÃO DESEJADA: ");

            escolha = scan.nextInt();
            scan.nextLine();

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
            else if(escolha == 2) {

                System.out.print("Digite seu cpf: ");
                cpf = scan.nextLine();
                System.out.print("Digite sua senha: ");
                senha = scan.nextInt();
                listaEmpregados.fazerLogin(cpf,senha);
            
            }
            else if(escolha == 3){
                continue;
            }
            else if(escolha == 4){
                continue;
            }
            else if (escolha == 5) {
                listaEmpregados.mostrarEmpregados();
            }
        }
        scan.close();
    }
}
