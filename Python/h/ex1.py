import re

# texto = open('texto.txt', 'w')
# texto.write('''
# J~_oa*o! V#i.tor
# M%a$theu's S#il$va
# Car**olin$a Me(i&r*e
# Cecilia Meireles
# Andressa Alves
# Jo$_*se _N+i@va#ldo
# An!a Vi\t#oria$
# joa?o a'bRE*u
# Vinicius car&valho
# s#HERL%OCK !holmes
# NATHAN L*IMA!
# Rafael Joao
# M#aria J@ose
# G#abriela #Maria
# Jessica lim%a**
# emanuelle gar&*cia
# Fab12ian#a G_+ome-s
# Lucas Silveira
# Adri3$ana A'!lmeida
# Q+UENTI)N ?TARAN@TINO
# BA+T M*AN
# CLA$Rk @Kent
# Bruc?e Al()ves
# HELEn+a R_omulo
# Nicholas!@ B#ueno
# No$ah B&arbosa
# Daniel? G_+onçalVES
# ELBA! RAMALHO
# Le*_onard#o +(Gabriel
# Gabri#el Penkal?
#                 ''')

with open('texto.txt', 'r') as arquivo:
    for linha in arquivo:
        linha_limpa = re.sub("[?\#@~^'+*_#!1234567890().$%@&-]", '', linha).capitalize()
        print(linha_limpa)

arquivo.close()