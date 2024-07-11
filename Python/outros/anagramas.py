import time
import random

# variáveis
file = 'anagramas.txt'
matriz = []
anagramas = []
respostas = []
anagrama  = ''
lives = 6
gameOver = False

with open(file, "r") as f:
    for linha in f:
        linha = linha.strip() 
        partes = linha.split('_')
        matriz.append(partes)

# filtro ternario
# para cada caracter de cada item se o caracter for diferente de '', ent adc
matriz = [parte for parte in matriz if parte != ['']]

def filterAnagramas():
    global anagramas
    for i in range(len(matriz)):
        anagramas.append(matriz[i][0])
        respostas.append(matriz[i][1])

filterAnagramas()

def main(gameOver):

    while gameOver == False:

        global anagrama, lives
        randIndex = random.randint(0, len(anagramas) - 1)
        anagrama = anagramas[randIndex]
        resposta = respostas[randIndex]

        print(f"\n---------------------------")
        print(f"o anagrama é : {anagrama}")
        guess = input("Enter a guess:\n---")

        if guess ==  resposta:
            print(f"você ganhou!\nResposta {resposta}")
            gameOver=True
        else:
            print("você errou!")
            if lives > 1:
                lives -= 2
                print(f"Lives: {lives}")
            else:
                print("game over")
                print(f"Lives: {lives}")
                gameOver = True

main(gameOver)              
    
# print(anagramas)



# while gameOver == False:
#     guess = input("Enter a guess:")
#     if guess == matriz[0][1]:
#         print("você ganhou!")
#         gameOver=True
#     else:
#         print("você errou!")
#         if lives > 1:
#             lives -= 2
#         else:
#             print("game over")
#             gameOver = True



# print(f"{matriz[0][0]}")
# print(f"{matriz[0][1]}")
# print(f"{matriz[1][0]}")
# print(f"{matriz[1][1]}")
# print(f"{matriz[2][0]}")
# print(f"{matriz[2][1]}")











# dois outputs:

# with open (file, "r") as f:
#     for i in f:
#         i = i.strip()
#         print(i)
#         # i = i.split('\n')
#         # print(i)
#         i = i.split('_')
#         print(i)

# veto_voto
# ['veto', 'voto']
# ramo_amor
# ['ramo', 'amor']


# with open (file, "r") as f:
#     for i in f:
#         i = i.strip()
#         print(i)
#         i = i.split('\n')
#         print(i)
#         # i = i.split('_')
#         # print(i)

# ['']
# veto_voto
# ['veto_voto']
# ramo_amor
# ['ramo_amor']

# ['']

# def filter(valor):
#     return valor != '' and valor is not None

# with open(file, 'w') as f:
#     f.write('''
# veto_voto
# ramo_amor
# arto_rato
#             ''')
    
#     f.close()
