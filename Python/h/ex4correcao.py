agenda = {}

def incluirNovoNome(nome, telefones):
    if nome in agenda:
        print(f"O nome '{nome}' já existe na agenda.")
        return
    
    agenda[nome] = telefones
    print(f"Nome '{nome}' adicionado com sucesso na agenda.")

def incluirTelefone(nome, telefone):
    if nome in agenda:
        # print(agenda[nome]) aceessa os valores da chave nome, os valores são uma lista
        agenda[nome].append(telefone)
        print(f"Telefone '{telefone}' adicionado para '{nome}'.")
    else:
        resposta = input(f"O nome '{nome}' não existe na agenda. Deseja incluí-lo? (s/n): ")
        if resposta.lower() == 's':
            telefones = [telefone]
            incluirNovoNome(nome, telefones)

def excluirTelefone(nome, telefone):
    if nome in agenda:
        if telefone in agenda[nome]:
            agenda[nome].remove(telefone)
            if len(agenda[nome]) == 0:
                del agenda[nome]
                print(f"Nome '{nome}' foi excluído da agenda pois não possui mais telefones.")
            else:
                print(f"Telefone '{telefone}' excluído para '{nome}'.")
        else:
            print(f"Telefone '{telefone}' não encontrado para '{nome}'.")
    else:
        print(f"O nome '{nome}' não existe na agenda.")

def excluirNome(nome):
    if nome in agenda:
        del agenda[nome]
        print(f"Nome '{nome}' excluído da agenda.")
    else:
        print(f"O nome '{nome}' não existe na agenda.")

def consultarTelefone(nome):
    if nome in agenda:
        print(f"Telefones de '{nome}': {', '.join(agenda[nome])}")
    else:
        print(f"O nome '{nome}' não existe na agenda.")

def mostrarMenu():
    print("Selecione uma opção:")
    print("1 - Adicionar um novo nome e número(s) à agenda")
    print("2 - Adicionar um novo número a um nome existente")
    print("3 - Excluir um número específico de um nome")
    print("4 - Excluir um nome e todos os seus números")
    print("5 - Consultar telefones de um nome")
    print("0 - Sair")

# Loop principal do programa
while True:
    mostrarMenu()
    opcao = input("Digite o número da opção desejada: ")

    if opcao == '1':
        nome = input("Digite o nome que deseja incluir na agenda: ")
        telefones = input("Digite os números de telefone separados por vírgula: ").split(',') #o split faz virar uma lista
        print(type(telefones))
        incluirNovoNome(nome, telefones)
    elif opcao == '2':
        nome = input("Digite o nome ao qual deseja adicionar um número: ")
        telefone = input("Digite o número de telefone que deseja adicionar: ")
        incluirTelefone(nome, telefone)
    elif opcao == '3':
        nome = input("Digite o nome do qual deseja excluir um número: ")
        telefone = input("Digite o número de telefone que deseja excluir: ")
        excluirTelefone(nome, telefone)
    elif opcao == '4':
        nome = input("Digite o nome que deseja excluir da agenda: ")
        excluirNome(nome)
    elif opcao == '5':
        nome = input("Digite o nome do qual deseja consultar os telefones: ")
        consultarTelefone(nome)
    elif opcao == '0':
        print("Saindo do programa...")
        break
    else:
        print("Opção inválida. Por favor, escolha uma opção válida.")
