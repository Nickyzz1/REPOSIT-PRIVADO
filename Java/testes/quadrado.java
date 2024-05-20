package testes;

public abstract class exAbstract {

    abstract void area();
    abstract void perimetro();

}

public class quadrado extends exAbstract{

    @Override
    public void area()
    {

    }
}

public class circulo{

}

public class triangulo{

}


//Crie uma hierarquia de classes para representar figuras geométricas. Crie uma classe abstrata chamada Figura com métodos abstratos para calcular a área e o perímetro. Em seguida, crie subclasses concretas para representar diferentes tipos de figuras, como Quadrado, Círculo, Triângulo, etc. Implemente os métodos abstratos em cada uma das subclasses para calcular a área e o perímetro corretamente.abstratos