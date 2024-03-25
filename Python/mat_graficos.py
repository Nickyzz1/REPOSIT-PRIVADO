# import pandas as pd
# import matplotlib.pyplot as plit #faz gráficos 

# resp = pd.read_csv("respiradores.csv", sep = ",")

# x = resp["MES"]
# y = resp["TOTAL"]

# plit.bar(x,y,1,align = "center",edgecolor = "black", color = "gray", zorder = 2)#zorder do gráfico maior para ele ficar nma frente
# plit.title("Compra de respiradores por mês")
# plit.xticks(rotation=45)
# plit.xlabel("Mês")
# plit.ylabel("Quantidade")
# # plit.grid(zorder =1) #linha soa gráfico
# plit.grid(axis='y', linestyle = "dashed", zorder =1) #dashed = pontilhado
# plit.show()

# print(help(plit.bar))



import pandas as pd
import matplotlib.pyplot as plit #faz gráficos 

resp = pd.read_csv("respiradores.csv", sep = ",")


plit.plot(resp["MES"], resp["PARANA"], marker='o', label = 'Paraná')
plit.plot(resp["MES"], resp["PARANA"], marker='o', label = 'São Paulo')
plit.plot(resp["MES"], resp["PARANA"], marker='o', label = 'Santa Catarina')
plit.legend()
plit.title("Compra de respiradores por mês no Paraná")
plit.xticks(rotation=45)
plit.grid(linestyle = "dashed")
plit.show()

print(help(plit.bar))
