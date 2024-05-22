import java.util.Scanner;

public class Main{

    static void addUser(User user, User list[], Integer loans)  //static para usar funções fora da main na MAin
    {
        for(int i = 0; i <list.length; i++)
        {
            if(i+1 == list.length)
            {
                User newList[] = new User[list.length*2];
                //copiar
                for(int j = 0; j < list.length; j++)
                {
                    newList[j] = list[j];
                }

                list = newList;
                break;
            }
            else if(list[i] == null)
            {
                list[i] = user;
                user.loans += 1;
                break;
            }
            else if(list[i].name.equals(user.name))
            {
                list[i].loans += user.loans;
                break;
            }
        }
    }
    public static void main(String args[])
    {
        Scanner scan = new Scanner(System.in);

        int size = 2;
        LL_Library library = new LL_Library();
        User listUsers[] = new User[size];

            int fla = 1;
            while(fla == 1)
            {
                try
                {

                int option;
                System.out.print("+-----------------------------------+\n");
                System.out.print("|             WELCOME               |\n");
                System.out.print("+===================================+\n");
                System.out.print("| OPTION   | CHOSE                  |\n");
                System.out.print("+===================================+\n");
                System.out.print("| 1  -     | ADD LOANS              |\n");
                System.out.print("| 2  -     | REMOVE LOANS           |\n");
                System.out.print("| 3  -     | SEE LOANS              |\n");
                System.out.print("| 4  -     | GERENCE USERS AND LOANS|\n");
                System.out.print("| 5  -     | EXIT                   |\n");
                System.out.print("+-----------------------------------+\n");

                option = scan.nextInt();
                scan.nextLine();

                switch (option) 
                {
                    case 1:
                    {
                        System.out.print("============ ADD BOOKS ============\n");
                        System.out.print("\nEnter a tilte: ");
                        String name = scan.nextLine();
                        System.out.print("\nEnter an author: ");
                        String author = scan.nextLine();
                        System.out.print("\nEnter a year: ");
                        String year = scan.nextLine();
                        System.out.print("============ ENTER YOUR CREDENTIALS ============\n\n");
                        System.out.print("Enter your name :");
                        String nameUser = scan.nextLine();
                        System.out.print("Enter your last name :");
                        String lastNameUser = scan.nextLine();
                        System.out.print("Enter your phone number:");
                        String phoneNumberUser = scan.nextLine();
                
                        Book book = new Book();
                        User user = new User(nameUser, lastNameUser, phoneNumberUser, 0);
                        addUser(user, listUsers, null);
                        book.newBook(name, author, year, user);
                        library.addBooks(book);

                        break;
                    } 
                    case 2:
                    {

                        break;
                    }
                    case 3:
                    {
                        library.display(library);
                        break;
                    } 
                    case 4:
                    {
                        User.viewUser(listUsers);
                        break;
                    } 
                    case 5:
                    {
                        fla = 0;
                        break;
                    } 
                    
                    default:
                        break;
                }
            
                }catch (Exception e){
        
                    System.out.println("Enter an valid option!");
                    e.printStackTrace();
                    fla = 0;
        
                }finally{
    
                }
            }

            scan.close();
       }
}