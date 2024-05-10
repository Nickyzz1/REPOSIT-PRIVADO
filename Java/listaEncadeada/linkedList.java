public class linkedList{
  
  //precisa me permitir buscar por algum elemento
  //precisa me permitir remover um elemento
  //precisa me permitir adc um elemento
  
  private Elemento primeiro;
  private Elemento ultimo;
  private int tamanho;

  //construtor
  //o método construtor é chamado quando se constrói um objeto
  //nesse caso, quando criar a lista o tamanho é zero
  public linkedList(){
    this.tamanho = 0;
  }

  //como são privadas get:
  public Elemento getPrimeiro(Elemento primeiro){
    return primeiro;
  }

  public Elemento getUltimo(Elemento ultimo){
    return ultimo;
  }
  public int getTamanho(){
    return tamanho;
  }
  //set
  public void setPrimeiro(Elemento primeiro){
    this.primeiro = primeiro;
  }

  public void setUltimo(Elemento ultimo){
    this.ultimo = ultimo;
  }

  public void setTamanho(int tamanho){
    this.tamanho = tamanho;
  }

  //functions

  //add
  public void add(String valor){
    
  }
  //remover
  public void remove(String valor){
    
  }
  //retornar um elemento
  public Elemento getElemento(int position){
    return null; 
  }
  
}
