public class Book {

    //creatingt a book

    String title;
    String author;
    String year;
    User user;

    void newBook(String title, String author, String year, User user)
    {
        this.title = title;
        this.author = author;
        this.year = year;
        this.user = user;
    } 
}
