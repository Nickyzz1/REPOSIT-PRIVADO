numAcounts = 0
login = False

class client():
    def __init__(client, name, agency, acount, balance, typeAcount):
        client.__name = name
        client.__agency = agency
        client.__acount = acount
        client.__balance = balance
        client.__typeAcount = typeAcount

    #getters

    def getName(client):
        # print(client.__name)
        return client.__name  
    
    def getAgency(client):
        # print(client.__agency)
        return client.__agency

    def getAcount(client):
        # print(client.__name)
        return client.__acount  

    def getBalance(client):
        # print(client.__name)
        return client.__balance 
     
    def getTypeAcount(client):
        # print(client.__name)
        return client.__typeAcount  

    # setters

    def setName(client, newName): 
        client.__name = newName
    
    def setAgency(client, newAgency):
        client.__agency = newAgency

    def setAcount(client, newAcount):
        client.__acount = newAcount  

    def setBalance(client, newBalance):
        client.__balance = newBalance
     
    def setTypeAcount(client, newTypeAcount):
        client.__typeAcount = newTypeAcount

    @staticmethod
    def nAcounts(client, numAcounts):
        print(f"o número de contas é {numAcounts}")

# matriz = []

while True:

    option = int(input("Enter the option\n1 - create a new acount \n2 - ver nome\n3 - ver numero da agencia\n4 - ver numero da conta\n5 - ver saldo\n6 - ver tipo de conta\n7 sair\n---"))

    if option == 1:

        userName = input("enter your name:\n---")
        userAcount = input("enter number of your acount:\n---")
        useragency = input("enter number od yuor agency:\n---")
        userBalance= input("enter your balance:\n--- ")
        userType = input("enter your type acount[poupança, corrente:\n---")
        c1 = client(userName, userAcount, useragency, userBalance, type)
        numAcounts += 1
        login = True

    elif option == 2:

        if login == False:
            print('First create acount!')
        else:
            print("ok")







# Criar um software para criar um sistema bancário onde o objeto cliente deve ter os seguintes campos (Getter / Setter / Método Privado / Método Estático):
# • Nome_cliente
# • Numero_agencia
# • Numero Conta
# • Saldo_cliente
# • Tipo_Conta (Corrente, Poupança)
# Deve se criar todos os atributos e métodos como sendo privados, sendo somente acessados por getters e setters, além de ter um método estático para mostrar o número de contas que esse banco tem, aumentando conforme contas são criadas.
