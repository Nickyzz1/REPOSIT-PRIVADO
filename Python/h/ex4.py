class Empresa:
    def __init__(self, nome, cnpj, nacionalidade, presidente):
        self.nome = nome
        self.cnpj = cnpj
        self.nacionalidade = nacionalidade
        self.presidente = presidente
        self.paises_atuacao = []
        self.produtos = {}

    def retornar_nome_responsavel(self):
        return self.presidente

    def retornar_paises_atuacao(self):
        return self.paises_atuacao

    def pesquisar_pais_atuacao(self, pais):
        return pais in self.paises_atuacao

    def adicionar_produto(self, nome, preco, descricao):
        self.produtos[nome] = {"preco": preco, "descricao": descricao}

    def retornar_relatorio_produtos(self):
        return self.produtos

    def pesquisar_produto_especifico(self, nome_produto):
        return self.produtos.get(nome_produto, None)

    def realizar_vistoria(self):
        print(f"Vistoria na empresa {self.nome}")


# Exemplo de uso da classe Empresa
bosch = Empresa("Bosch", "123456789", "Alemanha", "João Schmidt")
bosch.adicionar_produto("Furadeira", 299.99, "Furadeira elétrica potente")
print(bosch.retornar_relatorio_produtos())

class Area(Empresa):
    def __init__(self, nome, sigla_setor, funcao, diretor, lucro, inicio_auditoria=None, fim_auditoria=None):
        super().__init__(nome, '', '', '')  # Chamada ao construtor da classe pai (Empresa)
        self.sigla_setor = sigla_setor
        self.funcao = funcao
        self.diretor = diretor
        self.lucro = lucro
        self.inicio_auditoria = inicio_auditoria
        self.fim_auditoria = fim_auditoria

    def retornar_nome_responsavel(self):
        return self.diretor

    def retornar_relatorio_financeiro(self):
        return f"Relatório financeiro de {self.nome}: Lucro {self.lucro}"

    def retornar_periodo_auditoria(self):
        if self.inicio_auditoria and self.fim_auditoria:
            return f"Período de auditoria: {self.inicio_auditoria} até {self.fim_auditoria}"
        else:
            return "Não está sendo auditada"

    def realizar_vistoria(self):
        print(f"Vistoria na área {self.nome}")


# Exemplo de uso da classe Area
producao = Area("Produção", "PT", "Fabricação de ferramentas", "Maria Silva", 100000.0, "01/06/2024", "30/06/2024")
print(producao.retornar_relatorio_financeiro())

class Departamento(Area):
    def __init__(self, nome, sigla_setor, funcao, gestor, quantidade_funcionarios):
        super().__init__(nome, sigla_setor, funcao, gestor, 0)  # Chamada ao construtor da classe pai (Area)
        self.quantidade_funcionarios = quantidade_funcionarios

    def contratar_funcionario(self):
        self.quantidade_funcionarios += 1

    def realizar_treinamento(self):
        print(f"Treinamento no departamento {self.nome}")

    def realizar_vistoria(self):
        print(f"Vistoria no departamento {self.nome}")


# Exemplo de uso da classe Departamento
qualidade = Departamento("Qualidade", "QMM", "Controle de Qualidade", "José Santos", 50)
qualidade.contratar_funcionario()
print(f"Quantidade de funcionários em Qualidade: {qualidade.quantidade_funcionarios}")
