import re

# with open('newText.txt', 'w') as arquivo:
#     arquivo.write('''
#                     J~_oa*o! V#i.tor
#                     M%a$theu's S#il$va
#                     Car**olin$a Me(i&r*e
#                     Cecilia Meireles
#                     Andressa Alves
#                     Jo$_*se _N+i@va#ldo
#                     An!a Vi	#oria$
#                     joa?o a'bRE*u
#                     Vinicius car&valho
#                     s#HERL%OCK !holmes
#                     NATHAN L*IMA!
#                     Rafael Joao
#                     M#aria J@ose
#                     G#abriela #Maria
#                     Jessica lim%a**
#                     emanuelle gar&*cia
#                     Fab12ian#a G_+ome-s
#                     Lucas Silveira
#                     Adri3$ana A'!lmeida
#                     Q+UENTI)N ?TARAN@TINO
#                     BA+T M*AN
#                     CLA$Rk @Kent
#                     Bruc?e Al()ves
#                     HELEn+a R_omulo
#                     Nicholas!@ B#ueno
#                     No$ah B&arbosa
#                     Daniel? G_+onçalVES
#                     ELBA! RAMALHO
#                     Le*_onard#o +(Gabriel
#                     Gabri#el Penkal?
#                   ''')

arquivoTxt = 'newText.txt'
output = 'output.txt'

def cleanName(name):
    cleanName = re.sub(r'[^a-zA-Z\s]', '', name)
    #  codigo nega td que é diferente de a-z minusculo e maiúsculo e espaço
    formatName = ' '.join(word.capitalize() for word in cleanName.split(' '))
    print(formatName)

def main():

    with open(arquivoTxt, 'r') as arquivo:

        content = arquivo.read()
        cleanName(content.strip())
        
        # for name in content:
        #     if name.strip():
        #         with open(output, 'w') as formatArquivo:
        #             for name in cleanNames:
        #                 formatArquivo.write(name + '\n')
        #             for  i in formatArquivo:
        #                 print(i)
                        
main()
