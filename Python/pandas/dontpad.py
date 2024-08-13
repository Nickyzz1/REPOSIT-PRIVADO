
import pandas as pd

df = pd.read_csv('titanic.csv', sep=',')

# print(df.head(10)) # Os 5 primeiros
# print(df.tail()) # Os 5 últimos

# print(df['Name'])
# print(df.Name)

# colunas = ['Name', 'Age']
# print(df[colunas])


# print(df.columns) # Retornar todas as colunas



# print(df.iloc[:,:])
# print(df.loc[:, ["Age"]])

# print(df.describe())
# print(df.Age.mean())
# print(df.info())
# print(df["Embarked"].unique())
# df["Age"].value_counts() Contagem de quantas vezes eles aparecem, normalize


# ------- Tratando Not a Number -----------
# x = df.dropna() #excluir todas as linhas com not a number
# print(x.isna()) # Verificando valores nulos

# y=df["Age"].fillna(df["Age"].mean()) #Preencheer onde é encontrado not a number 
# print(y.head(15))
# z=df.fillna(200)

# -----------------------------------------

# .sort_values()




#  --------------------- Carros ----------------------------------

import pandas as pd
colunas = ["Manufacturer", "Make", "Price", "MPG.city", "Type", "Passengers"]
ap = pd.read_csv("Cars93_miss.csv", sep=",").loc[:, colunas]

ap = ap[ap["Passengers"]==5]

ap = ap.sort_values(by="MPG.city", ascending=False).head(10)

ap = ap.sort_values(by="Price")

print(ap.head())






# ------------------------------------ EX1 ------------------------------------


# E se quisermos um filtro que retorne os registros com os passageiros da primeira classe 
# que sobreviveram e os passageiros da terceira classe que não sobreviveram?



# Resolução: 

titanic = pd.read_csv('titanic.csv', sep=',')

filtro = (  
    (titanic["Pclass"] == 1) & (titanic["Survived"] == 1) |
    (titanic["Pclass"] == 3) & (titanic["Survived"] == 0)
)
titanic[filtro].head()



# ------------------------------------ EX2 ------------------------------------



# Robin está procurando por uma mulher que conheceu durante um evento no Titanic, poucas horas antes da tragédia.
# Ele gostaria de saber se ela sobreviveu e nós podemos ajudar ele através do nosso banco de dados.
# As informações que ele sabe sobre ela são:

# - Ela embarcou em Southampton (Inglaterra)
# - Ela era da segunda classe
# - Ela tinha 29 anos
# - E no nome completo dela tinha Anne, mas ele não sabe se era nome ou sobrenome.
# - Lembre sempre de retirar os valores NaN das colunas (aplique outro valor no lugar deles).



# Resultado:
# A mulher que ele está procurando é Faunthorpe, Mrs. Lizzie (Elizabeth Anne Wilkinson), ela sobreviveu



# ------------------------------------ Code ------------------------------------


import pandas as pd

titanic = pd.read_csv('titanic.csv', sep=',')


# ---------- Valores NaN ----------
media=titanic["Age"].mean()
titanic["Age"] = titanic["Age"].fillna(media)
titanic["Age"] = round(titanic["Age"])

titanic["Cabin"] = titanic["Cabin"].fillna("Desconhecido")


# ---------- FILTRO ----------
filtro_embarque = (titanic["Embarked"]=="S")& (titanic["Pclass"] == 2) & (titanic["Sex"] == "female") & (titanic["Age"] == 29)
titanic=titanic[filtro_embarque]



for i in titanic.index:
    if "Anne" in titanic.loc[i,"Name"]:
        print(titanic.loc[i,:])


#CRIAR NOVA COLUNA
import pandas as pd

titanic = pd.read_csv("titanic.csv", sep=',')

def soma(linha): #recebe o 1 parâmetro nomeado de linha
    return linha["SibSp"] + linha["Parch"] #retorna o resultado da soma d e duas linhas

nova_coluna = titanic.apply(soma, 1) #o apply lê cada linha, a fução soma é um parâmetro do apply e o 1 significa axis = 1,  que lê linha por linha. Com o retormo da soma de cada linha cria-se uma coluna com esses valores (se fosse por coluna seria 0)
titanic["Relatives"] = nova_coluna #@dei um nome "Relatives" para minha nova coluna; Com o retorno da soma de cada linha cria-se uma coluna com esses valores
# print(titanic.columns) # verificar se nova coluna foi ralemnte adc
print(titanic)
