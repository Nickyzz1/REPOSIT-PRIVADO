
import pandas as pd
colunas = ["Manufacturer", "Make", "Price", "MPG.city", "Type", "Passengers"]
ap = pd.read_csv("Cars93_miss.csv", sep=",").loc[:, colunas]

ap = ap[ap["Passengers"]==5] #deixa apenaas as linhas que tem passageiros =5

ap = ap.sort_values(by="MPG.city", ascending=False).head(10)

ap = ap.sort_values(by="Price")

print(ap.head())
