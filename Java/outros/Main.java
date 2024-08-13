// import java.util.LinkedList;
import SaNiDuCollections.*;
import SaNiDuCollections.collections.*;;

public class Main
{
    public static void main(String[] args) {
        // LinkedList<Integer> bucked = new LinkedList<>();
        Hash<Pessoa> hash = new Hash<Pessoa>();
        hash.add(1, new Pessoa("Sabrina", 19, false));
        hash.add(2, new Pessoa("Eduardo", 19, false));
        hash.add(3, new Pessoa("Nicolle", 19, false));

        System.out.println(hash.get(2).getNome());
    }
    
}