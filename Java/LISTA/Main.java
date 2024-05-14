public class Main {
    public static void main(String args[]){

        LinkedList lista = new LinkedList();

        lista.add("Carlos");
        lista.add("Eduardo");

        System.out.println("o primeiro: " + lista.getHead());
        System.out.println("o ultimo: " + lista.getTail());

    }
    
}
