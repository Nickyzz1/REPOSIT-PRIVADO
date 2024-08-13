import pandas as pd
import pyodbc
import matplotlib.pyplot as plt

# Configurar a conexão com o banco de dados
server = 'CA-C-0064P\SQLEXPRESS'  # Nome do servidor
database = 'sensorTable'  # Nome do banco de dados
cnxn = pyodbc.connect('DRIVER={SQL Server};SERVER='+server+';DATABASE='+database+';Trusted_Connection=yes')  # Conectar ao banco de dados

# Executar consulta e carregar dados em um DataFrame
query = 'SELECT * FROM climateServer'
df = pd.read_sql_query(query, cnxn)

# Fechar a conexão com o banco de dados
cnxn.close()

# Plotar temperatura e umidade
plt.figure(figsize=(15,10))
plt.plot(df['timestamp'], df['temperature'], label='Temperature', color='red')
plt.plot(df['timestamp'], df['humidity'], label='Humidity', color='blue')

# Configurar título e legendas
plt.title("Temperature and Humidity over Time")
plt.xlabel("Timestamp")
plt.ylabel("Values")
plt.legend()

# Mostrar o gráfico
plt.show()



import pandas as pd
import pyodbc
import matplotlib.pyplot as plt

server = 'CA-C-0064P\SQLEXPRESS' #coloco o nome do servidor  num var
database = 'sensorTable' #varcom o nome do database
cnxn = pyodbc.connect('DRIVER={SQL Server};SERVER='+server+';DATABASE='+database+';Trusted_Connection=yes') #varável que guarda a conexão com o servidor; faz aa conexão
cursor = cnxn.cursor() #var do tipo cursor que pode ler e escrever no bd
query = 'SELECT * FROM climateServer' #ele executa a conexão a table que vc coloca  o nome
df = pd.read_sql_query(query, cursor)
cnxn.close()
plt.figure(figsize=(15,10))

plt.plot(df['timstamp'], df['temperature'], label = 'Temperature')
plt.plot(df['timstamp'], df['humidity'], label = 'Humidity')

plt.title("climate")
plt.xlabel('Timestamp')
plt.ylabel('values')
plt.show()

# for i in cursor: #printa td que cursor leu e agora guarda
#     print(i)
cnxn.close() #fecha a conexão
