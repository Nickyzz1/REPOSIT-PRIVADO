//cada elemento tem o seu valor e o endereço do proximo elemento apenas
public class Elemento{
  
  private String valor; //o elemnto será  uma string
  private Elemento proximo; //o próximo é do tipo elemento

  //get
  public Elemento getValor(Elemento valor){
    return valor;
  }

  public Elemento getProximo(Elemento proximo){
    return proximo;
  }
  //set
  public void setValor(String valor){
    this.valor = valor;
  }

  public void setProximo(Elemento proximo){
    this.proximo = proximo;
  }  
  
}
