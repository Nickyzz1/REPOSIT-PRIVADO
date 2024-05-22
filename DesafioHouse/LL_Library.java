public class LL_Library {

    LL_Node head;

    //add
    void addBooks(Book book)
    {
        //allocar memória para o novo livro
        LL_Node newBook = new LL_Node(book);
        if(head == null)
        {
            head = newBook;    
        }
        else{

            LL_Node temp = head;
            head = newBook;
            head.setNext(temp);
        }
    }

    void display(LL_Library list)
    {
        LL_Node current = head;

        while(current != null)
        {
            System.out.printf("\ntitle : %s", current.book.title);
            System.out.printf("\nauthor : %s", current.book.author);
            System.out.printf("\nyear : %s", current.book.year);
            System.out.printf("\nuser name : %s", current.book.user.name);
            System.out.printf("\nuser last name : %s", current.book.user.lastName);
            System.out.printf("\nuser phone number : %s", current.book.user.phone);

            current = current.getNext();
        }
        System.out.println();
    }
}