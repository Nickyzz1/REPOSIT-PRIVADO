# somar os algarismos de um númwro
num = input("enter a num separated by comma figuring out the sum of the algarisms: ")
lista = []
num = num.split(',')
sum = 0 
for i in num:
    lista.append(int(i))
for j in lista:
    sum += j
print(sum)
