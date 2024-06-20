import pandas as pd
import pyodbc
import matplotlib.pyplot as plt

server = 'CA-C-0064P\SQLEXPRESS' #coloco o nome do servidor  num var
database = 'sensorTable' #varcom o nome do database
cnxn = pyodbc.connect('DRIVER={SQL Server};SERVER='+server+';DATABASE='+database+';Trusted_Connection=yes') #varável que guarda a conexão com o servidor; faz aa conexão
cursor = cnxn.cursor() #var do tipo cursor que pode ler e escrever no bd
cursor.execute('SELECT * FROM climateServer') #ele executa a conexão a table que vc coloca  o nome
df = pd.read_sql(cursor)
plt.figure(figsize=(15,10))
for i in df['temperature'].unique()
    temperature = df[df['temperature'] == i]
    plt.plot(temperature['temperature'], label = i)
for j in df['humidity'].unique():
    humidity = df[df['humidity'] == j]
    plt.plot(humidity['humidity'], label = j)

plt.title("climate")
plt.show()

# for i in cursor: #printa td que cursor leu e agora guarda
#     print(i)
cnxn.close() #fecha a conexão
