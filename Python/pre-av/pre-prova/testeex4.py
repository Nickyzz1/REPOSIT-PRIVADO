matriz = [
    [],[],
    [],[],
    [],[],
]

# matriz = {matriz}
x = 0
y = 0

def includeName(name, phones):
    global x, y
    if matriz == None:
        matriz[x][y] = name
        matriz[x][y + 1] = phones
        for i in matriz:
            print(i)
        print("insertion with sucessfully\n\n")
    else:
        # phoneList = {name:f"{phones}"}
        print(matriz)
        print("insertion with sucessfully\n\n")

while True:

    option = input("enter the option\n1 - add new name\n2 - update name\n3 - delete phone number from name\n4 - delete a name\n5- show list\n\n")

    if option ==  '1':

        name = input("enter the name of person: ")
        quant = input("enter the quantity of numbers you want to add at that person: ")
        phones = []
        for i in range(int(quant)):
            number = input(f"enter the number {i}: ")
            phones.append(number)
        includeName(name, phones)
        
    elif option == '2':

        nameUp = input("enter a name in the list to add a number: ").lower()
        if nameUp in matriz:
            print("está")
        else:
            print("nn encontrado")

    elif option == '3':
        pass
    elif option == '4':
        pass
    elif option == '5':
        print(matriz)
    
