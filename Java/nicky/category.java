import java.util.Random;

public class Category{
    
    Random random = new Random();
    String randomCategory[];

    Category(){

        randomCategory = new String[2];
        randomCategory[0] = "Cheater";
        randomCategory[1] = "Cooperative";
    }

    String random() {

        int index = random.nextInt(randomCategory.length);
        String category = randomCategory[index];
    
        return category;
    }

}
