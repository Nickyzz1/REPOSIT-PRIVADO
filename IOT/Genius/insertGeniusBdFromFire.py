import pyodbc
import time
import requests as rq
import json

proxies = {'https': "http://disrct:etsps2024401@10.224.200.26:8080"}

def InserirBD(sinal):
    server = 'CA-C-0064P\\SQLEXPRESS'
    database = 'genius'
    cnxn = pyodbc.connect('DRIVER={SQL Server};SERVER=' + server + ';DATABASE=' + database + ';Trusted_Connection=yes')
    cursor = cnxn.cursor()
    # Usando parâmetros para evitar SQL injection
    cursor.execute("INSERT INTO tableGenius (player, score) VALUES (?, ?)", sinal[0], sinal[1])
    cnxn.commit()
    print("Inserido com sucesso!")

def apresentar(sinal):
    print(f"Player: {sinal[0]}, Score: {sinal[1]}")

while True:
    url = 'https://iiot-7276b-default-rtdb.firebaseio.com//Nicolle.json'
    cont = rq.get(url, proxies=proxies).content
    results = json.loads(cont)
    Player = results.get("Player")
    Score = results.get("Score")
    if Score is not None:  # Verifica se Score não é None
        print(f"Player: {Player} Score: {Score}")
        valores = (Player, Score) #se a tupla for um valor é (valor,)
        apresentar(valores)
        InserirBD(valores)
        break
    else:
        print("Score is None, skipping insertion.")
    time.sleep(2)
