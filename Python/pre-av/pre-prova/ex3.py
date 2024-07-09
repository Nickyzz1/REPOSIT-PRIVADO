import re

times = ['1_palmeiras', '2_coritiba', '1_corintians', '3_juventude', '2_fluminense', '3_bahia', '1_cuiaba', '2_cascavel', '3_ponte preta', '2_parana clube', '3_volta redonda']
primeira = []
segunda = []
terceira = []

for i in times:
    if '1' in i:
        item = re.sub('[123_]', '', i)
        primeira.append(item)
    if '2' in i:
        item = re.sub('[123_]', '', i)    
        segunda.append(item)
    if '3' in i:
        item = re.sub('[123_]', '', i)
        terceira.append(item)


print(f"Primeira div:{primeira}")
print(f"segunda div: {segunda}")
print(f"terceira div : {terceira}")