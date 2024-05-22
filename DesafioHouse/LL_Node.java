public class LL_Node {

    Book book; //criei um objeto book
    User user;
    private LL_Node next; //criei um next

    LL_Node(Book book)
    {
        this.book = book; 
        this.next = null;
    }

    void createUser(User user)
    {
        this.user = user;
    }


    public Book getBook() {
        return book;
    }

    public void setBook(Book book) {
        this.book = book;
    }

    public LL_Node getNext() {
        return next;
    }

    public void setNext(LL_Node next) {
        this.next = next;
    }
}
