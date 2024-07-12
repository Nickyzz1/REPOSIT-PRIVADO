# Polimorfismo é um conceito em programação orientada a objetos (POO) que permite que diferentes classes utilizem métodos com o mesmo nome

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
