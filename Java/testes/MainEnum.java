package testes;

public class MainEnum {
       public static void main(String args[])
    {
        DiaSemana hoje = DiaSemana.DOMINGO;

        switch (hoje) {
            case SEGUNDA:
            case TERÇA:
            case QUARTA:
            case QUINTA:
            case SEXTA:
                System.out.println("\ndia util");
                break;

            case SABADO:
            case DOMINGO:
            System.out.println("Final de semana");
                break;
        }
        System.out.println("Dias da semana:");
        for (DiaSemana dia : DiaSemana.values()) { // oq ue eu itero eu coloco denrero da var dia
            System.out.println(dia); //printo o valor da var dia toda vez
        }
    }
    
}
