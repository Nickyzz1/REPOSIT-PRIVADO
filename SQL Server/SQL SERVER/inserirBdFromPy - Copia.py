# -*- coding: utf-8 -*-
"""
Created on Wed Jun 19 08:41:22 2024

@author: liq1ct
"""

import pyodbc
import time
import matplotlib.pyplot as plt
import numpy as np
import seaborn as sns
import pandas as pd
import requests as rq
import json

proxies = {'https' : "http://disrct:etsps2024401@10.224.200.26:8080"}
url = 'https://iiot-7276b-default-rtdb.firebaseio.com//Nicolle.json'

def InserirBD(sinal):

    server = 'CA-C-0064P\SQLEXPRESS'
    database = 'sensorTable'
    cnxn = pyodbc.connect('DRIVER={SQL Server};SERVER='+server+';DATABASE='+database+';Trusted_Connection=yes')
    cursor = cnxn.cursor()
    cursor.execute(f"INSERT climates (temperature, hum) VALUES ({sinal[0]},{sinal[1]})")
    cursor.commit()
    print("Inserido com sucesso!")

def apresentar(sinal):
    print(f"Temperatura: {sinal[0]}")
    print(f"Umidade: {sinal[1]}")
    
while True:
    valores = (4,2)
    apresentar(valores)
    InserirBD(valores)
    time.sleep(120)