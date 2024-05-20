package testes;
import java.util.Scanner;

public class tryCath {
    public static void main(String[] args) {

        Scanner scan = new Scanner(System.in);
        
        System.err.println("Enter a number: ");
        int num1 = scan.nextInt();
        System.err.println("Enter another number: ");
        int num2 = scan.nextInt();

        try{
            //cod que pode lançar(throw) excessões

            int result = num1/num2;
            System.err.println("Result: " + result);

        }
        catch(Exception e)
        {
            //tratamento das ex
            System.err.println("Erro de divisão por zero!");

        }finally{

            System.err.println("Finaliando programing...");
            scan.close();
        }
    }
}
