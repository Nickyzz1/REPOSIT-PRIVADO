def soma_algarismos(numero):
    return sum(int(digito) for digito in str(numero))

def main():
    try:
        numero = int(input("Digite um número inteiro maior que zero: "))
        if numero <= 0:
            print("Número Inválido. Tente novamente.")
        else:
            resultado = soma_algarismos(numero)
            print(f"A soma dos algarismos é: {resultado}")
    except ValueError:
        print("Entrada inválida. Por favor, digite um número inteiro.")

# Exemplo de uso
main()
