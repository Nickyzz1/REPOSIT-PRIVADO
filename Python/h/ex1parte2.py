import re

with open('texto.txt', 'r') as arquivo:
    for linha in arquivo:
        linha_limpa = re.sub(r"[?\#@~^'+*_#!1234567890().$%@&-]", '', linha)  # Remove caracteres especiais
        linha_formatada = linha_limpa.strip().capitalize()  # Remove espaços em branco e capitaliza a primeira letra
        print(linha_formatada)

