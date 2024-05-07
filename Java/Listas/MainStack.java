import java.util.Scanner;
public class MainStack {
    public static void main(String args[]) {

        int amount;
        StackGenerico <Integer> lista = new StackGenerico<>(); //obj do tipo stack para poder usar a função add que é um métood do stack
        Scanner scan = new Scanner(System.in);
        System.out.printf("Enter how many items you want to add at list:  ");
        amount = scan.nextInt();

        for(int i = 0; i <amount; i++) {

            System.out.println("Enter a Integer Number: ");
            Integer item = scan.nextInt();
            lista.add(item);
        }

        //mostrando a lista
        lista.mostrar();

        int fla = 1;
        while( fla == 1 ) {

            System.out.printf("\nEnter the option:\n\n1-push\n2-pop\n3-peek\n4-size\n0-SAIR\n\n");
            int escolha = scan.nextInt();
            if(escolha == 1) {

                //input do user
                System.out.print("\n\nEnter a number to push: ");
                int number = scan.nextInt();

                //fazer o push e mostrar o push
                lista.push(number);
                lista.mostrar();
            }

            else if(escolha == 2) {

                lista.pop();
                System.out.print("\n\nLista com o pop: ");
                lista.mostrar();
            } 

            else if(escolha == 3) {

                lista.peek();
            } 

            else if(escolha == 4) {

                lista.size();
            } 

            else if(escolha == 0) {

                System.out.print("Okay!");
                fla = 0;
            }
            else {
                System.out.printf("Enter a valid option!");
            }

        }
        
        scan.close();
    }
}

//aqq a lista deve se rum stcak pq irá se reportar a classe stack
