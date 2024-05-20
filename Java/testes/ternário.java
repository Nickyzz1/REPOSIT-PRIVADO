package testes;

public class ternário {
    public static void main(String args[])
    {
        int num1 = 2;
        int num2 = -9;
        String parimpar = (num1%2 == 0) ? "É par" : "É impar";
        System.out.println(parimpar);

        String classe = (num2 > 0) ? "Positivo" : "negativo";
        System.err.println(classe);
    }
}
