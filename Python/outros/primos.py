num = int(input("enter a num:\n---"))
lista = []
isPrimo = False

for i in range(num):
    print(i)
    if num % (num - i) == 0:
        lista.append(num - i)
        
if len(lista) > 2:
    print("nn é primo")
else:
    print("é primo")

    
