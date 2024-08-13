import requests
import json

proxies = {'https' : "http://disrct:etsps2024401@10.224.200.26:8080"}

nameUser = input("Enter your name to estimate your age: ")
url = 'https://api.agify.io/?name=' + nameUser
resultName = requests.get(url, proxies=proxies).content #faz requisição para a url do tipo get coloca as var dentro a url o content pega o conteudo html do site, api volta um txt poequeno
results = json.loads(resultName) #transforma em um dict
age = results.get("age")
print(f"your age:{age}")