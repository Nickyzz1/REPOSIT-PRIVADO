phoneList = {}

def includeName(name, phones):
    global phoneList
    phoneList = {name:f"{phones}"}
    print(f"\n{phoneList}")
    print("\ninsertion with sucessfully\n\n")

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
        if nameUp in phoneList:
            update = input("\nName was found! Enter the index of the number:")
            i
            
        else:
            op = input("\nName not found! You want add this name?\n1 - YES\n2 - NO\n")
            if op == '1':
                name = input("enter the name of person: ")
                quant = input("enter the quantity of numbers you want to add at that person: ")
                phones = []
                for i in range(int(quant)):
                    number = input(f"enter the number {i}: ")
                    phones.append(number)
                includeName(name, phones)
            else:
                pass

    elif option == '3':
        pass
    elif option == '4':
        pass
    elif option == '5':
        print(phoneList)
    
