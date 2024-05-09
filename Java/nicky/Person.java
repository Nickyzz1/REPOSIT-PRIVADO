public class Person {

    String name;
    String category;
    int coin;

    Person(String name, String category, int coin)
    {
        this.name = name;
        this.category = category;
        this.coin = coin;
    }

    @Override
    public String toString() {
        return name + " - " + category + " - " + coin;
    }

}
