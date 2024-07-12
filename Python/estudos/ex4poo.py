class company:
    def __init__(self, name, cnpj, nacionalidade, responsavel, paises=[], prod=[]):
        self.name = name
        self.cnpj = cnpj
        self.nacionalidade = nacionalidade
        self.__responsavel = responsavel
        self.__paises = paises
        self.prod = prod

    def getResponsavel(self):
        # print(self.__responsavel)
        return self.__responsavel

    def getPaises(self):
        return self.__paises

    def search(self, pais):
        if pais in self.__paises:
            print('existe')
        else:
            print('não existe')

    def addProd(self, prod):
        self.prod.append(prod)

    def relatorio(self):
        print("retornando relatório")

    def searchProd(self, prod):
        if prod in self.prod:
            print('existe')
        else:
            print('não existe')

class area(company):
    def __init__(self, name, cnpj, nacionalidade, responsavel, paises, prod, function, sigla, lucro, inicio, fim):
        super().__init__(name, cnpj, nacionalidade, responsavel, paises, prod)
        self.function = function
        self.sigla = sigla
        self.lucro = lucro
        self.inicio = inicio
        self.fim = fim

# Exemplo de uso
a1 = area('ana', '123456789', 'Brasil', 'João', ['Brasil', 'Argentina'], ['Produto1'], 'Gerenciamento', 'G', '10000', '2023-01-01', '2023-12-31')
print(f"Nome: {a1.name}, Responsável: {a1.getResponsavel()}, Função: {a1.function}, Sigla: {a1.sigla}, Lucro: {a1.lucro}, Início: {a1.inicio}, Fim: {a1.fim}")

        
#/ Empresa (Bosch):
# Atributos:
# • Nome
# • CNPJ
# • Nacionalidade
# • Nome do Responsável (Presidente)
# • Países de Atuação (lista)
# • Produtos (chaves: nome do produto, preço do produto, descrição)
# Métodos:
# • Retornar Nome do Responsável
# • Retornar os Países de Atuação
# • Pesquisar por um País de Atuação
# • Adicionar produto
# • Retornar Relatório de Produtos
# • Pesquisar por um Produto Específico
# Área (PS, PT, GS, AA, PM, ED etc.):
# Atributos:
# • Nome
# • Sigla do Setor
# • Função (PT faz ferramentas, AA venda de peças...)
# • Nome do Responsável (Diretor)
# • Lucro
# • Data de Início de Auditoria
# • Data de Fim de Auditoria
# Métodos:
# • Retornar Nome do Responsável
# • Retornar Relatório Financeiro
# • Retornar Período de Auditoria (saber Data de Início e Fim de Auditoria E se está sendo
# auditada, ALÉM do responsável pela área)
# Departamento (ETS, QMM, BISB, FCM, PUR, IDI1, MSE, CVO, OSD, MFI):
# Atributos:
# • Nome
# • Sigla do Setor
# • Função (QMM cuida da qualidade...)
# • Nome do Responsável (Gestor)
# • Quantidade de Funcionários
# Métodos:
# • Retornar Nome do Responsável
# • Contratar Funcionário
# • Realizar Treinamento
# Nesse software Departamento deve herdar de Área, e Área deve herdar de Empresa!
# Todos os objetos devem possuir um método de vistoria onde deve mostrar na tela a
# empresa/Setor/Subsetor que está tendo a vistoria 
