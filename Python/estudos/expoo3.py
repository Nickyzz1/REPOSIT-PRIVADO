class client():

    def __init__(c, name, agency, acount, balance, typeAcount):
        c.__name = name
        c.__agency = agency
        c.__acount = acount
        c.__balance = balance
        c.__typeAcount = typeAcount
    
    def __validacao(c, newBalance):
        if newBalance.isdigit():
            c.__balance += int(newBalance)
        else:
            print("digite um valor válido")
            c.__balance += 0 
              
    # getters
    
    def getName(c):
        print(f"client {c.__name}")
        return c.__name
    
    def getAgency(c):
        print(f"client {c.__agency}")
        return c.__agency
    
    def getAcount(c):
        print(f"client {c.__acount}")
        return c.__acount
    
    def getTypeAcount(c):
        print(f"client {c.__typeAcount}")
        return c.__typeAcount
    
    def getBalance(c):
        print(f"client {c.__balance}")
        return c.__balance
    
    # setters
    
    def setName(c, new):
        c.__name = new
    
    def setAgency(c, new):
        c.__agency = new

    def setAcount(c, new):
        c.__acount= new
        
    def setBalance(c, new):
        c.__validacao(new)

    def setTypeAcount(c, new):
        c.__typeAcount = new
    
        
    @staticmethod
    def calculatorInvestimentos(c):
        if c.__balance < 2000:
            print("você pode contratar crédito até 1000")
        else:
            print("você pode contratar crédito até 3000")
            
    @staticmethod
    def count(count):
        print(f"o banco tem {count} contas")
 
count = 0
created = False

while True:
    
    option = int(input("0 - sair\n1 - create acount\n2 - ver saldo\n3 - mudar saldo(depositar)\n4 - mudar tipo de conta\n5 - investir\n6 - ver informações\n--"))
    
    try:
        if option == 0:
            break
        elif option == 1:
            name = input("\nenter your name:\n--")
            agency = input("\nenter your agency:\n--")
            acount = input("enter your acount:\n--")
            balance = int(input("Enter your balance:\n--"))
            typeA = input("enter your type acount:\n--")
            
            c1 = client(name, agency, acount, balance, typeA)
            created = True
            count += 1
            client.count(count)
            
        elif option == 2:
            if created == True:
                c1.getBalance()
            else:
                print("\nvocê deve criar uma conta primeiro!")
        elif option == 3:
            if created == True:
                new = input("enter how many you want to deposit:\n--")
                c1.setBalance(new)
            else:
                print("\nvocê deve criar uma conta primeiro!")
        elif option == 4:
            if created == True:
                new = input("enter new type acount:\n--")
                c1.setTypeAcount(new)
            else:
                print("\nvocê deve criar uma conta primeiro!")
        elif option == 5:
            if created == True:
                client.calculatorInvestimentos(c1)
            else:
                print("\nvocê deve criar uma conta primeiro!")
        elif option == 6:
            if created == True:
                print(f"name {c1.getName()} agency: {c1.getAgency()} acount: {c1.getAcount()} balance: {c1.getBalance()} type acount: {c1.getTypeAcount()}")
            else:
                print("\nvocê deve criar uma conta primeiro!")
            
            
    except Exception as e:
        print(e)


# Criar um software para criar um sistema bancário onde o objeto cliente deve ter os seguintes
# campos (Getter / Setter / Método Privado / Método Estático):
# • Nome_cliente
# • Numero_agencia
# • Numero Conta
# • Saldo_cliente
# • Tipo_Conta (Corrente, Poupança)
# Deve se criar todos os atributos e métodos como sendo privados, sendo somente acessados por
# getters e setters, além de ter um método estático para mostrar o número de contas que esse
# banco tem, aumentando conforme contas são criadas.
