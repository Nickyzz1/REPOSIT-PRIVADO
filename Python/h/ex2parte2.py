def soma_digitos(numero):
    # Converter o número para uma string para iterar sobre cada dígito
    numero_str = str(numero)
    
    # Inicializar a variável para armazenar a soma dos dígitos
    soma = 0
    
    # Iterar sobre cada dígito na string
    for digito in numero_str:
        # Converter o dígito de volta para um número inteiro e somar à variável soma
        soma += int(digito)
    
    # Retornar a soma dos dígitos
    return soma

# Exemplo de uso
numero = int(input("Digite um número inteiro: "))
resultado = soma_digitos(numero)
print(f"A soma dos dígitos de {numero} é {resultado}.")
