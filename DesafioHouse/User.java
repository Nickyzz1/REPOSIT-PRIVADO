public class User {

    String name, lastName, phone;
    int loans;

    User(String name, String lastName, String phone, int loans)
    {
        this.name = name;
        this.lastName = lastName;
        this.phone = phone;
        this.loans = loans;
    }
    //quando eu crio a função estática eu n~çao preciso criar objeto, nem ter objeto para usá-la, posso chamara apenas a classe seguida de um ponmto e o nome do método
    static void viewUser(User list[])
    {
        for(int i = 0; i <list.length; i++)
        {
            if(list[i] == null)
            {
                continue;
            }
            System.out.printf("\nName: %s", list[i].name);
            System.out.printf("\nLast name: %s", list[i].lastName);
            System.out.printf("\nTelephone: %s", list[i].phone);
            System.out.printf("\nLoans: %s", list[i].loans);
            System.out.println();
        }
    }
}
