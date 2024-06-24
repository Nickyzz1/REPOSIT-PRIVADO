import pyodbc
import time
import requests as rq
import json

proxies = {'https': "http://disrct:etsps2024401@10.224.200.26:8080"}

def InserirBD(sinal):
    server = 'CA-C-0064P\SQLEXPRESS'
    database = 'genius'
    cnxn = pyodbc.connect('DRIVER={SQL Server};SERVER=' + server + ';DATABASE=' + database + ';Trusted_Connection=yes')
    cursor = cnxn.cursor()
    cursor.execute(f"INSERT tableGenius (score) VALUES ({sinal[0]})")
    cursor.commit()
    print("Inserido com sucesso!")

def apresentar(sinal):
    print(f"score: {sinal[0]}")

while True:
    url = 'https://iiot-7276b-default-rtdb.firebaseio.com//Nicolle.json'
    cont = rq.get(url, proxies=proxies).content
    results = json.loads(cont)
    Score = results.get("Score")
    if Score is not None:  # Verifica se Score não é None
        print(f"score: {Score}")
        valores = (Score,)  # Note a vírgula para fazer uma tupla de um único valor
        apresentar(valores)
        InserirBD(valores)
        break
    else:
        print("Score is None, skipping insertion.")
    time.sleep(2)
