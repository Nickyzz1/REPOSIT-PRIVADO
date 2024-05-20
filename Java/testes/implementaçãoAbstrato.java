package testes;

public abstract class implementaçãoAbstrato {

    // Classe abstrata com método abstrato
    public abstract void fazerBarulho(); // Método abstrato

}
// Subclasse concreta que estende Animal
class Cachorro extends implementaçãoAbstrato {
    // Implementação do método abstrato fazerBarulho
    //ao usar o override eu estou dizendo explicitamente ao ompilador que agora estou "sobrescrevendo" o método abstrato da classe pai, para não dar erros de lógica e interpretaççao do compilador
    @Override
    public void fazerBarulho() {
        System.out.println("O cachorro faz au au!"); // Funcionalidade específica para cachorro
    }
}
    
