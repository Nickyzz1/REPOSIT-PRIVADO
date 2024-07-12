agenda = {}

def incluirNovoNome(nome, telefones):
    if nome not in agenda:
        agenda[nome] = telefones
    else:
        print("Nome já existe na agenda.")

def incluirTelefone(nome, telefone):
    if nome in agenda:
        agenda[nome].append(telefone)
    else:
        incluir = input(f"O nome {nome} não está na agenda. Deseja incluí-lo? (s/n): ")
        if incluir.lower() == 's':
            telefones = [telefone]
            incluirNovoNome(nome, telefones)

def excluirTelefone(nome, telefone):
    if nome in agenda:
        if telefone in agenda[nome]:
            agenda[nome].remove(telefone)
            if not agenda[nome]:
                del agenda[nome]
        else:
            print(f"O telefone {telefone} não está associado ao nome {nome}.")
    else:
        print(f"O nome {nome} não está na agenda.")

def excluirNome(nome):
    if nome in agenda:
        del agenda[nome]
    else:
        print(f"O nome {nome} não está na agenda.")

def consultarTelefone(nome):
    if nome in agenda:
        return agenda[nome]
    else:
        print(f"O nome {nome} não está na agenda.")
        return []

def menu():
    while True:
        print("\nAgenda Telefônica")
        print("1 - Incluir novo nome")
        print("2 - Consultar telefones")
        print("3 - Excluir telefone")
        print("4 - Incluir telefone")
        print("5 - Excluir nome")
        print("0 - Sair")
        opcao = int(input("Escolha uma opção: "))

        if opcao == 1:
            nome = input("Digite o nome: ")
            telefones = input("Digite os telefones separados por espaço: ").split()
            incluirNovoNome(nome, telefones)
        elif opcao == 2:
            nome = input("Digite o nome a ser consultado: ")
            telefones = consultarTelefone(nome)
            if telefones:
                print(f"Telefones de {nome}: {', '.join(telefones)}")
        elif opcao == 3:
            nome = input("Digite o nome: ")
            telefone = input("Digite o telefone a ser excluído: ")
            excluirTelefone(nome, telefone)
        elif opcao == 4:
            nome = input("Digite o nome: ")
            telefone = input("Digite o telefone a ser incluído: ")
            incluirTelefone(nome, telefone)
        elif opcao == 5:
            nome = input("Digite o nome a ser excluído: ")
            excluirNome(nome)
        elif opcao == 0:
            break
        else:
            print("Opção inválida. Tente novamente.")

# Exemplo de uso
menu()
