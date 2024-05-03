package oldPonto;
import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
    Scanner scanner = new Scanner(System.in);

    // // Exemplo de scanner com string:
    // System.out.print("Digite seu nome: ");
    // String nome = scanner.nextLine();
    // // Exemplo de scanner com int:
    // System.out.print("Digite sua idade: ");
    // int idade = scanner.nextInt();

    System.out.print("Digite seu CPF: ");
    String cpfUsuario = scanner.nextLine();
    System.out.print("Digite sua senha: ");
    String senhaUsuario = scanner.nextLine();
    // Colocar a função pra conferir os dados
    // Colocar a função pra bater o ponto
    scanner.close();
    }
}
