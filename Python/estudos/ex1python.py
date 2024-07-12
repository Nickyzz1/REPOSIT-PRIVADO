import re

def limpar_nome(nome):
    # Remove caracteres especiais e números, deixa só letras e espaços
    nome_limpo = re.sub(r'[^a-zA-Z\s]', '', nome)
    # Formata para que a primeira letra de cada palavra seja maiúscula
    nome_formatado = ' '.join([palavra.capitalize() for palavra in nome_limpo.split()])
    return nome_formatado

def processar_arquivo(input_file, output_file):
    with open(input_file, 'r', encoding='utf-8') as arquivo:
        conteudo = arquivo.readlines()
    
    nomes_limpos = [limpar_nome(nome) for nome in conteudo if nome.strip()]
    quantidade_recuperada = len(nomes_limpos)
    
    with open(output_file, 'w', encoding='utf-8') as arquivo:
        for nome in nomes_limpos:
            arquivo.write(nome + '\n')
    
    print(f"Quantidade de itens recuperados: {quantidade_recuperada}")

# Exemplo de uso
processar_arquivo('clientes.txt', 'clientes_limpos.txt')
