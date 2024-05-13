import java.util.Scanner;

public class Main {
    public static void main(String args[]){

        LikedList lista = new LikedList();
        Scanner scan = new Scanner(System.in);
        String value;
    
        System.out.println("Enter a name to add on linked list:");
        value = scan.nextLine();
        lista.add(value);

        System.out.println("The first: " + lista.getHead());
        System.out.println("The tail: " + lista.getTail());
        System.out.println("The next: " + lista.getNext());
        
        scan.close();

    }
    
}
