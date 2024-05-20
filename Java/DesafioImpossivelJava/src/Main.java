// import SaNiDuCollections.collections.ArrayList;
import SaNiDuCollections.collections.Hash;
// import SaNiDuCollections.collections.Iterator;
import SaNiDuCollections.collections.List;
import SaNiDuCollections.exceptions.IteratorException;

public class Main {
    public static void main(String[] args) {
        // LinkedList<Integer> bucked = new LinkedList<>();
        // Hash<Pessoa> hash = new Hash<Pessoa>();
        // hash.add(1, new Pessoa("Sabrina", 19, false));
        // hash.add(2, new Pessoa("Eduardo", 19, false));
        // hash.add(3, new Pessoa("Nicolle", 19, false));

        // System.out.println(hash.get(2).getNome());


        // LinkedList<Pessoa> list = new LinkedList<>();

        // list.add(new Pessoa("Sabrina", 19, false));
        // list.add(new Pessoa("Andrey", 18, false));

        // ArrayList<String> filteredList = null;
        // try {
        //     filteredList = list.stream().map(x -> "Nome: "+ x.getNome() + "  Idade: " + x.getAge()).collect();
        // } catch (IteratorException e) {
        //     e.printStackTrace();
        // }    

        // if (filteredList != null) {
        //     Iterator<String> it = filteredList.iterator();

        //     while (it.hasNext()) {
        //         try {
        //             System.out.println(it.next());
        //         } catch (IteratorException e) {
        //             e.printStackTrace();
        //         }
        //     }
        // }

        Hash<Pessoa> hash = new Hash<>();
    	hash.add(1, new Pessoa("Don", 14, true));
    	hash.add(2, new Pessoa("Trevis", 25, false));
    	hash.add(3, new Pessoa("Queila", 23, true));
    	hash.add(4, new Pessoa("Alisson", 26, false));
    	hash.add(5, new Pessoa("Raissa", 21, true));
        
        try {
            List<String> dados = hash.stream()
                .filter(p -> p.getAge() > 17)
                .filter(p -> p.isExApprentice())
                .map(p -> p.getNome())
                .collect();
            for(int i = 0; i < dados.getSize(); ++i)
            {
                System.out.print("\n" + dados.get(i));
            }
        } catch (IteratorException e) {
            System.out.println(e.getMessage());
            e.printStackTrace();
        }

    }
}
