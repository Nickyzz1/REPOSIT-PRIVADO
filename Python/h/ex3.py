class Cliente:
    _numero_contas = 0  # Variável de classe para contar o número de contas criadas

    def __init__(self, nome_cliente, numero_agencia, numero_conta, saldo_cliente, tipo_conta):
        self._nome_cliente = nome_cliente
        self._numero_agencia = numero_agencia
        self._numero_conta = numero_conta
        self._saldo_cliente = saldo_cliente
        self._tipo_conta = tipo_conta
        Cliente._numero_contas += 1  # Aumenta o contador de contas ao criar uma nova conta

    # Getters
    def get_nome_cliente(self):
        return self._nome_cliente

    def get_numero_agencia(self):
        return self._numero_agencia

    def get_numero_conta(self):
        return self._numero_conta

    def get_saldo_cliente(self):
        return self._saldo_cliente

    def get_tipo_conta(self):
        return self._tipo_conta

    # Setters
    def set_nome_cliente(self, nome_cliente):
        self._nome_cliente = nome_cliente

    def set_numero_agencia(self, numero_agencia):
        self._numero_agencia = numero_agencia

    def set_numero_conta(self, numero_conta):
        self._numero_conta = numero_conta

    def set_saldo_cliente(self, saldo_cliente):
        self._saldo_cliente = saldo_cliente

    def set_tipo_conta(self, tipo_conta):
        self._tipo_conta = tipo_conta

    # Método privado
    def _metodo_privado(self):
        return f"Método privado acessado para o cliente {self._nome_cliente}."

    # Método estático para mostrar o número de contas
    @staticmethod
    def numero_de_contas():
        return Cliente._numero_contas


# Exemplo de uso:
cliente1 = Cliente("João Silva", "001", "12345-6", 1000.0, "Corrente")
cliente2 = Cliente("Maria Souza", "002", "54321-0", 500.0, "Poupança")

# Exemplo de acesso aos getters
print(f"Nome do cliente: {cliente1.get_nome_cliente()}")
print(f"Saldo do cliente: {cliente1.get_saldo_cliente()}")

# Exemplo de uso do método privado
print(cliente1._metodo_privado())

# Exemplo de uso do método estático para contar contas
print(f"Número total de contas: {Cliente.numero_de_contas()}")

# Exemplo de modificação usando setters
cliente2.set_saldo_cliente(600.0)
print(f"Novo saldo de Maria: {cliente2.get_saldo_cliente()}")
