# -*- coding: utf-8 -*-
"""
Created on Wed Jun 19 08:41:22 2024

@author: liq1ct
"""

import pyodbc
import time
import requests as rq
import json

proxies = {'https' : "http://disrct:etsps2024401@10.224.200.26:8080"} #sempre que for acessar um site precisa de autirzação do proxy

#função para inserir no bd
def InserirBD(sinal): #parametro sinal
    server = 'CA-C-0064P\SQLEXPRESS' 
    database = 'sensorTable'
    cnxn = pyodbc.connect('DRIVER={SQL Server};SERVER='+server+';DATABASE='+database+';Trusted_Connection=yes') #fa z aa conexão
    cursor = cnxn.cursor() #cria um objeto do tipo cursor
    cursor.execute(f"INSERT climateServer (temperature, hum) VALUES ({sinal[0]},{sinal[1]})") #ativa o objeto do tipo cursor
    cursor.commit()
    print("Inserido com sucesso!")

def apresentar(sinal):
    print(f"Temperatura: {sinal[0]}")
    print(f"Umidade: {sinal[1]}")

    
while True:
    url = 'https://iiot-7276b-default-rtdb.firebaseio.com//Nicolle.json'
    cont = rq.get(url, proxies=proxies).content 
    results = json.loads(cont)
    temp =  results.get("temperatura")
    hum = results.get("humidae")
    print(f"temp :{temp} hum :{hum}")
    valores = (temp, hum)
    apresentar(valores)
    InserirBD(valores)
    time.sleep(2)