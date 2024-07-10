import argparse

parser = argparse.ArgumentParser(description='Calcular a área do terreno')
parser.add_argument('largura', type=int, help='Largura do terreno')
parser.add_argument('comprimento', type=int, help='Comprimento do terreno')

args = parser.parse_args()

def calculator(l, c):
    area = l * c
    return area

if __name__ == '__main__':
    print("Área do terreno é: %s m²" % calculator(args.largura, args.comprimento))
# need open with integrate terminal para abrir na pasta correta e o comando é python argparser.py 10 10
