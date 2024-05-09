import java.util.Scanner;
import java.util.Random;
import java.util.List;

public class Main{
    public static void main(String args[])
    {
        //criando scanner
        Scanner scan = new Scanner(System.in);
        Random random = new Random();

        //criando instancias
        Category category = new Category();
        Person listaPlay[] = new Person[6];
        

        //criando var
        String randomCategory;
        String name1;
        String name2;
        String name3;
        String name4;
        String name5;
        String name6;

        int popCooperatives = 0;
        int popcheaters = 0;
        int totalCoins = 60;
        int positive = 1;
        
        randomCategory = category.random();
    
        //printando
        System.out.printf("-----------Bem vindo!-----------\n\nDigite um nome para o jogador 1: ");
        name1 = scan.nextLine();
        System.out.printf("\nDigite um nome para o jogador 2: ");
        name2 = scan.nextLine();
        System.out.printf("\nDigite um nome para o jogador 3: ");
        name3 = scan.nextLine();
        System.out.printf("\nDigite um nome para o jogador 4: ");
        name4 = scan.nextLine();
        System.out.printf("\nDigite um nome para o jogador 5: ");
        name5 = scan.nextLine();
        System.out.printf("\nDigite um nome para o jogador 6: ");
        name6 = scan.nextLine();
        System.out.printf("\n\n ");

        //criando jogadores

        Person player1 = new Person(name1, randomCategory, 10);
        Person player2 = new Person(name2, randomCategory, 10);
        Person player3 = new Person(name3, randomCategory, 10);
        Person player4 = new Person(name4, randomCategory, 10);
        Person player5 = new Person(name5, randomCategory, 10);
        Person player6 = new Person(name6, randomCategory, 10);

        listaPlay[0] = player1;
        listaPlay[1] = player2;
        listaPlay[2] = player3;
        listaPlay[3] = player4;
        listaPlay[4] = player5;
        listaPlay[5] = player6;

        //criar uma lista que guarde os players cooperrativos, e cheaters
        ///escolher aleatóruiamente na lista quem vai jogar com quem e colocar dentro do if;
        //num loop

        while(totalCoins > 0){

            int index1 = random.nextInt(listaPlay.length);
            int index2 = random.nextInt(listaPlay.length); 

                if(listaPlay[index1].category == "cheater"){
                    popcheaters +=1;
                }
                else{
                    popCooperatives +=1;
                }
                if(listaPlay[index2].category == "cheater"){
                    popcheaters += 1;
                }
                else{
                    popCooperatives += 1;
                }
                //possibilidade 1
                if(listaPlay[index1].category == "Cheater" && listaPlay[index2].category == "Cheater") {


                if(listaPlay[index1].coin == 0 ){

                    System.out.print("O jogador " + listaPlay[index1].name + " foi eliminado");
                    listaPlay = Remove.removeElement(listaPlay, index1);
                }
                else if(listaPlay[index2].coin == 0 ){

                    System.out.print("O jogador " + listaPlay[index2].name + " foi eliminado");
                    listaPlay = Remove.removeElement(listaPlay, index2);
                }
                else{

                        positive = 0;
                        listaPlay[index1].coin -= 1;
                        listaPlay[index2].coin -= 1;
                        totalCoins -= 2;

                        System.out.print("Moedas de " + listaPlay[index1].name + ": "+ listaPlay[index1].coin +"\nMoedas de " + listaPlay[index2].name + ": "+ listaPlay[index2].coin + "\n Total coins: " + totalCoins + "   confiança: " + positive + "   População cooperativa: " + popCooperatives + "   População trapaceira: " + popcheaters + "\n\n");
                }
                //possibilidade 2
                if(listaPlay[index1].category == "Cheater" && listaPlay[index2].category == "Cooperative")
                {if(listaPlay[index1].coin == 0 ){

                    System.out.print("O jogador " + listaPlay[index1].name + " foi eliminado");
                    listaPlay = Remove.removeElement(listaPlay, index1);
                }
                else if(listaPlay[index2].coin == 0 ){

                    System.out.print("O jogador " + listaPlay[index2].name + " foi eliminado");
                    listaPlay = Remove.removeElement(listaPlay, index2);
                }
                else
                {
                    positive = 1;
                    int flagg = 1;

                    while(flagg == 1){

                        if(positive == 0)
                        {
                            System.out.print("O jogador " + player2.name + " não confia mais em você! ");
                            flagg = 0;

                        }
                        else{

                            listaPlay[index1].coin += 1;
                            listaPlay[index2].coin -= 1;
                            totalCoins -= 1;
                            System.out.print("Moedas de " + listaPlay[index1].name + ": "+ listaPlay[index1].coin +"\nMoedas de " + listaPlay[index2].name + ": "+ listaPlay[index2].coin + "\n Total coins: " + totalCoins + "    Confiança: " + positive+ "   População cooperativa: " + popCooperatives + "   População trapaceira: " + popcheaters + "\n\n");
        
                            Integer lista[] = new Integer[4];
                            lista[0] = 1;
                            lista[1] = 1;
                            lista[2] = 1;
                            lista[3] = 0;
        
                            int index = random.nextInt(lista.length);
                            positive = lista[index];
                        }
                    }
                }
                //possibilidade 3
                if(listaPlay[index1].category == "Cooperative" && listaPlay[index2].category == "Cheater")
                {
                    if(listaPlay[index1].coin == 0 ){

                        System.out.print("O jogador " + listaPlay[index1].name + " foi eliminado");
                        listaPlay = Remove.removeElement(listaPlay, index1);
                    }
                    else if(listaPlay[index2].coin == 0 ){
    
                        System.out.print("O jogador " + listaPlay[index2].name + " foi eliminado");
                        listaPlay = Remove.removeElement(listaPlay, index2);
                    }
                    else{
                    positive = 1;
                    int flagg = 1;

                    while(flagg == 1){

                        if(positive == 0)
                        {
                            System.out.print("O jogador " + player1.name + " não confia mais em você! ");
                            flagg = 0;

                        }
                        else{

                            listaPlay[index1].coin -= 1;
                            listaPlay[index2].coin += 1;
                            totalCoins -= 1;
                            System.out.print("Moedas de " + listaPlay[index1].name + ": "+ listaPlay[index1].coin +"\nMoedas de " + listaPlay[index2].name + ": "+ listaPlay[index2].coin + "\n Total coins: " + totalCoins + "    Confiança: " + positive + "   População cooperativa: " + popCooperatives + "   População trapaceira: " + popcheaters + "\n\n");
        
                            Integer lista[] = new Integer[4];
                            lista[0] = 1;
                            lista[1] = 1;
                            lista[2] = 1;
                            lista[3] = 0;
        
                            int index = random.nextInt(lista.length);
                            positive = lista[index];
                        }
                    }
                }
                //possibilidade 4
                if(listaPlay[index1].category == "Cooperative" && listaPlay[index2].category == "Cooperative")
                {
                    if(listaPlay[index1].coin == 0 ){

                        System.out.print("O jogador " + listaPlay[index1].name + " foi eliminado");
                        listaPlay = Remove.removeElement(listaPlay, index1);
                    }
                    else if(listaPlay[index2].coin == 0 ){
    
                        System.out.print("O jogador " + listaPlay[index2].name + " foi eliminado");
                        listaPlay = Remove.removeElement(listaPlay, index2);
                    }
                    else{
        
                    positive = 1;

                    System.out.print("Moedas de " + listaPlay[index1].name + ": "+ listaPlay[index1].coin +"\nMoedas de " + listaPlay[index2].name + ": "+ listaPlay[index2].coin + "\nTotal coins: " + totalCoins + "   confiança: " + positive + "   População cooperativa: " + popCooperatives + "   População trapaceira: " + popcheaters + "\n\n");
            }

            scan.close();
        }
        }
    }
    }}
}}
        
