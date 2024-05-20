package testes;

public class erros {
    public static void main(String args[])
    {
        try{

            String num = "1.4";
            int num2 = Integer.parseInt(num);
            System.out.println(num2);

        }
        catch(NumberFormatException e){
            System.err.println("Não é possível converter a string para um inteiro");
        }
    }
//InputMismatchException --?> vc pede um número e o user digita um aletra, por exemplo, ou se vc dá 1,2,3 de opçõese a pessoa digita 4
//numberFormatException  --/> Se o programa espera um número inteiro, mas o usuário insere uma String que não representa um número válido, como "abc" ou "123abc".
}
