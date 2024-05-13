public class Elemento{

    private String value;

    Elemento(String value){
        this.value = value;
        Elemento item = new Elemento(value);
    }

    //get
    String getValue(){
        return value;
    }
    
}