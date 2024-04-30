#um filtro que retorne registros com os passageiros da primeira classe que sobreviverame  da terceira que sobreviveram
import pandas as pd

titanic = pd.read_csv('titanic.csv', sep=",", encoding = 'utf8')

filtro = (
    (titanic["Pclass"]==1) & (titanic["Survived"]==1) |
    (titanic["Pclass"]==3) & (titanic["Survived"]==1)    #isso é um filtro
)

print(titanic[filtro].head()) #apenas .head() mostra os 5 primeiros
