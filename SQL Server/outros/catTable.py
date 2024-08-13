import pyodbc
import time
import requests as rq
import json

server = 'CA-C-0064P\SQLEXPRESS' #coloco o nome do servidor  num var
database = 'sensorTable' #varcom o nome do database
cnxn = pyodbc.connect('DRIVER={SQL Server};SERVER='+server+';DATABASE='+database+';Trusted_Connection=yes') #varável que guarda a conexão com o servidor; faz aa conexão
cursor = cnxn.cursor() #var do tipo cursor que pode ler e escrever no bd
cursor.execute('SELECT * FROM climateServer') #ele executa a conexão a table que vc coloca  o nome
for i in cursor: #printa td que cursor leu e agora guarda
    print(i)
cnxn.close() #fecha a conexão