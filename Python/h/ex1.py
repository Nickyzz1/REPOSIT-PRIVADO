# O código apresenta alguns problemas e não segue as melhores práticas, especialmente em relação ao uso de estruturas de dados e escrita em arquivo. Vamos analisar os problemas e depois refatorar o código utilizando Programação Orientada a Objetos (POO).

# Problemas no Código Original:
# Entrada de Idade como String: A idade do aluno é lida como uma string (input() retorna uma string), o que pode não ser adequado se precisarmos realizar operações numéricas com essa informação posteriormente.

# Chave "Planta " no Dicionário: Há um espaço extra na chave "Planta " no dicionário aluno, o que pode causar inconsistências na manipulação de dados.

# Escrita Direta no Arquivo: A escrita direta de um dicionário convertido em string para o arquivo não é a maneira mais robusta de armazenar dados estruturados.

# Refatoração Utilizando Programação Orientada a Objetos (POO):
# Vamos refatorar o código utilizando uma abordagem orientada a objetos, criando uma classe Aluno para representar os dados do aluno e encapsular seu comportamento.

class Aluno:
    def __init__(self, nome, idade, turma, planta):
        self.nome = nome
        self.idade = idade
        self.turma = turma
        self.planta = planta

    def to_dict(self):
        return {
            "Nome": self.nome,
            "Idade": self.idade,
            "Turma": self.turma,
            "Planta": self.planta
        }

    def __str__(self):
        return f"Nome: {self.nome}, Idade: {self.idade}, Turma: {self.turma}, Planta: {self.planta}"


# Entrada de dados do aluno
nome_aluno = input("Digite o nome do aluno: ")
idade_aluno = int(input("Digite a idade do aluno: "))  # Convertendo para int
turma_aluno = input("Digite a turma do aluno: ")
planta_aluno = input("Digite a planta do aluno: ")

# Criando objeto aluno
aluno = Aluno(nome_aluno, idade_aluno, turma_aluno, planta_aluno)

# Salvando dados em um arquivo
with open("alunos.txt", "w", encoding="utf-8") as arquivo:
    arquivo.write(str(aluno))

# Exemplo de uso dos métodos da classe Aluno
print(aluno.to_dict())  # Converte para dicionário

# Explicações da Refatoração:
# Classe Aluno: Define uma classe Aluno que encapsula os dados do aluno e fornece métodos para acessar e manipular esses dados.

# Construtor (__init__): Inicializa os atributos do aluno (nome, idade, turma, planta) com os valores fornecidos.

# Método to_dict(): Retorna os atributos do aluno como um dicionário, útil para serialização ou outras operações.

# Método __str__(): Retorna uma representação em string formatada dos dados do aluno, adequada para impressão ou escrita em arquivo.

# Entrada de Dados: Utiliza input() para obter os dados do aluno, convertendo a idade para inteiro (int) para garantir consistência numérica.

# Escrita em Arquivo: Utiliza with open(...) para abrir o arquivo alunos.txt em modo de escrita e escreve a representação em string do objeto aluno diretamente.

# Exemplo de Uso: Demonstração simples de como o objeto Aluno pode ser utilizado, convertendo-o para um dicionário usando to_dict().