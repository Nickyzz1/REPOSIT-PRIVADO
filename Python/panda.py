import pandas 

dados =  pandas.read_csv('titanic.csv', sep=",", encoding = 'utf8')  #onde guardar dados csv

# print(dados.head(10)) #mostra os 10 primeiros
# print(dados.tail(10)) #mostra os 10 últimos
# print(type(dados)) #mostra o tipo de variável que é a dados
# print(dados[['Name', "Sex", "Age"]].head(10)) #os 10 primerios nomes, seus sexos correspondentes e suas diades correspondentes
# print(dados.columns) #retorna as colunas

#                 #LINHA #COLUNA
# print(dados.iloc[1:10,1:4]) #:linha E :COLUNA se deixar apenas :.: quer dizer do iníco até o final, do contrário vc pode específicar, de qual cLINHA, ex: 1:10 até as COLUNAS 1:3 
# print(dados.loc[:,["Age"]])
# print(dados.iloc[:,-1]) #retornas todas as linhas menos a últimA
# print(dados.describe()) #retorna dados como média, soba, c=quantos, desvio padrão acerca dos dados
# print(dados.Age.mean()) #retorna apenas o dado que vc quer da coluna que vc quer, nesse exemplo o mean= média
# print(dados["Age"].mean()) #outra forma de reornar um age
# print(dados.info()) #da informações se algum valor é nulo ou não, ex: tratar outliers
# print(dados["Embarked"].unique()) #retorna todos as possibilidades de resposta dos embarked sem repetir
print(dados["Age"].value_counts()) #contagem de quatas vezes certos valores apareceram 
x = dados.dropna() #está removendo todas as linhas do DataFrame dados que contenham valores nulos (NaN). O resultado é armazenado na variável x.
print(x.isna()) #verifica valores nulos em x, que é um grupo de valores nulos
y = dados.Age.fillna(dados.Age.mean) #Essa linha imprime as 15 primeiras linhas do DataFrame y, que é o DataFrame dados após preencher os valores nulos na coluna "Age" com a média das idades.
print(y.head(15)) #Essa linha imprime as 15 primeiras linhas do DataFrame y, que é o DataFrame dados após preencher os valores nulos na coluna "Age" com a média das idades.

z =dados.fillna(20000000) #preenche todos os valores nulos no DataFrame dados com o valor 20,000,000 (20 milhões). O resultado é armazenado na variável z. Isso é um preenchimento genérico de valores nulos com um número específico.
# print(round(dados.groupby("Embarked").mean()["Age"].sort_values()["s"],5))

