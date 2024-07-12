class Animal:
    def __init__(self, nome, idade, peso):
        self.nome = nome
        self.idade = idade
        self.peso = peso

    def fazer_som(self):
        raise NotImplementedError("Este método deve ser sobrescrito pelas subclasses")

class Cachorro(Animal):
    def __init__(self, nome, idade, peso, raca):
        super().__init__(nome, idade, peso)
        self.raca = raca

    def fazer_som(self):
        return "Au au"

class Gato(Animal):
    def __init__(self, nome, idade, peso, cor_pelo):
        super().__init__(nome, idade, peso)
        self.cor_pelo = cor_pelo

    def fazer_som(self):
        return "Miau"

class Vaca(Animal):
    def __init__(self, nome, idade, peso, producao_leite):
        super().__init__(nome, idade, peso)
        self.producao_leite = producao_leite

    def fazer_som(self):
        return "Muu"

# Exemplos de uso
meu_cachorro = Cachorro("Rex", 5, 30, "Labrador")
meu_gato = Gato("Mimi", 3, 4, "Preto")
minha_vaca = Vaca("Bela", 7, 600, "Alta")

print(f"Meu cachorro {meu_cachorro.nome}, idade {meu_cachorro.idade}, pesa {meu_cachorro.peso}kg, raça {meu_cachorro.raca}, faz {meu_cachorro.fazer_som()}.")
print(f"Meu gato {meu_gato.nome}, idade {meu_gato.idade}, pesa {meu_gato.peso}kg, cor do pelo {meu_gato.cor_pelo}, faz {meu_gato.fazer_som()}.")
print(f"Minha vaca {minha_vaca.nome}, idade {minha_vaca.idade}, pesa {minha_vaca.peso}kg, produção de leite {minha_vaca.producao_leite}, faz {minha_vaca.fazer_som()}.")

# da erro se eu mencionar o super do pai e não colocar todos os argumentos que precisa
----------------------------
class Animal:
    def __init__(self, nome):
        self.nome = nome

    def fazer_som(self):
        raise NotImplementedError("Este método deve ser sobrescrito pelas subclasses")

class Cachorro(Animal):
    def __init__(self, nome, raca):
        super().__init__(nome)
        self.raca = raca

    def fazer_som(self):
        return "Au au"

# Exemplo de uso
meu_cachorro = Cachorro("Rex", "Labrador")
print(f"Meu cachorro {meu_cachorro.nome}, da raça {meu_cachorro.raca}, faz {meu_cachorro.fazer_som()}.")

# 
Polimorfismo em POO Python
Polimorfismo é um conceito em programação orientada a objetos (POO) que permite que diferentes classes utilizem métodos com o mesmo nome, mas que se comportam de maneira diferente com base no objeto que os invoca. Em Python, o polimorfismo é frequentemente implementado por meio de herança e substituição de métodos.

Exemplo de Polimorfismo
Vamos criar uma hierarquia de classes para ilustrar o polimorfismo:

python
Copiar código
class Animal:
    def fazer_som(self):
        raise NotImplementedError("Este método deve ser sobrescrito pelas subclasses")

class Cachorro(Animal):
    def fazer_som(self):
        return "Au au"

class Gato(Animal):
    def fazer_som(self):
        return "Miau"

class Vaca(Animal):
    def fazer_som(self):
        return "Muu"

# Lista de diferentes animais
animais = [Cachorro(), Gato(), Vaca()]

# Exemplo de polimorfismo
for animal in animais:
    print(animal.fazer_som())
Saída:
Copiar código
Au au
Miau
Muu
# No exemplo acima, temos a classe Animal com o método fazer_som, que é sobrescrito pelas subclasses Cachorro, Gato e Vaca. Cada subclasse implementa o método fazer_som de maneira diferente, permitindo que diferentes objetos sejam tratados de forma polimórfica através da interface comum Animal.

# super() em POO Python
# O super() é uma função em Python que é usada para dar acesso aos métodos e atributos de uma classe pai ou superclasse.
