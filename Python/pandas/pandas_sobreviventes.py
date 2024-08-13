import pandas as pd

#somar td
#divir todos os (titanic[survived])==sobreviventes por 100 e os ~sobreviventes po 100 mtbm

titanic = pd.read_csv("titanic.csv", sep =",")

def somar_parentes(linha): #os parentres estão em duias colunas, vamos somar para ver o número de parentes total de passangers
    return linha["SibSp"] + linha["Parch"] #retorna o resultado da soma d e duas linhas

nova_coluna = titanic.apply(somar_parentes, 1) 
titanic["Relatives"] = nova_coluna
# print(titanic)

def sobreviventes():
    contagem= (titanic["Survived"]==1).value_counts()
    total = contagem[True] + contagem[False]

    porcentagem_s = round((contagem[True]/total)*100)
    porcentagem_n= round((contagem[False]/total)*100)
    print(f"A porcentagem de sobreviventes é: {porcentagem_s}%\nA procentagem de não sobreviventes é: {porcentagem_n}%")

sobreviventes()

def parentes():
    filtro = titanic[(titanic["Survived"]==1) & (titanic["Relatives"]==0)]
    contagem = len(filtro)
    porcentagem_p = round((contagem/891)*100)
    print(f"A porcentagem de sobreviventes que não possuiam parentes é: {porcentagem_p}%")

parentes()

def homens_m():
    filtro = titanic[(titanic["Sex"]=="male") & (titanic["Survived"]==0)]
    porcentagem_h = round((len(filtro)/891)*100)
    print(F"A porcentagem de homens que não sobreviveram é: {porcentagem_h}%")

homens_m()

def mulheres_m():
    filtro = titanic[(titanic["Sex"]=="female") & (titanic["Survived"]==0)]
    porcentagem_h = round((len(filtro)/891)*100)
    print(F"A porcentagem de mulheres que não sobreviveram é: {porcentagem_h}%")

mulheres_m()

def classes():
    filtro_1 = titanic[(titanic["Pclass"]==1) & (titanic["Survived"]==1)]
    porcentagem_1 = round((len(filtro_1)/891)*100)
    print(f"A quantidade de sobreviventes da primeira classe é: {porcentagem_1}%")

    filtro_2 = titanic[(titanic["Pclass"]==2) & (titanic["Survived"]==1)]
    porcentagem_2 = round((len(filtro_2)/891)*100)
    print(f"A quantidade de sobreviventes da segunda classe é: {porcentagem_2}%")

    filtro_3 = titanic[(titanic["Pclass"]==3) & (titanic["Survived"]==1)]
    porcentagem_3 = round((len(filtro_3)/891)*100)
    print(f"A quantidade de sobreviventes da terceira classe é: {porcentagem_3}%")

classes()

