
count = 0

class Livro(): 
    def __init__(self, titulo, autor, qtd_paginas, guardado=True): 
        self.titulo = titulo 
        self.autor = autor 
        self.qtd_paginas = qtd_paginas 
        self.guardado = guardado
    def getBook(book):
        if book.guardado == True:
            book.guardado = False
            print(f"livro emprestado! status guardado {book.guardado}")
        else:
            print("não é possível emprestar esse livro")
    def returnBook(book):
        if book.guardado == False:
            print(f"devolvido com sucesso! status guardado {book.guardado}")
        else:
            print("não é possível devolver esse livro")
            
    def virarPag(book):
        global count
        if count < book.qtd_paginas:
            count += 1 
            print(f"a pagina do livro é : {count} ")
            
# • virar_uma_pagina: avança uma página do livro caso o atributo guardado seja “False” 
# e mostra em qual página do livro está (sempre começando em 1), e não podendo 
# ultrapassar o limite de quantidade de páginas. Tem como output o número da página 
# do livro; 
l1 = Livro('aaa', 'bbbb', 4, False)
l2 = Livro('ccc', 'dddd', 600)

option = 0

while True:
    option = input("1-pegar livro\n2-devolver livro\n3-virar pag\n0-sair\n")
    print(option)
    if option == '3':
        l1.virarPag()
        
     
# l2.getBook()
# l1.returnBook()

# print(l1.autor)

        
# pegar_livro: muda o atributo guardado para “False”, mas só pode funcionar caso o 
# livro esteja com o guardado (guardado == True); 
# • devolver_livro: muda o campo do guardado para “True”, mas só pode funcionar caso 
# o livro esteja com o guardado (guardado == False); 
# • virar_uma_pagina: avança uma página do livro caso o atributo guardado seja “False” 
# e mostra em qual página do livro está (sempre começando em 1), e não podendo 
# ultrapassar o limite de quantidade de páginas. Tem como output o número da página 
# do livro; 
# • virar_n_paginas: avança uma quantidade n de páginas do livro caso o atributo 
# guardado seja igual a “False” e mostra em qual página do livro está (sempre 
# começando em 1), e não podendo ultrapassar o limite de quantidade de páginas. Tem 
# como output o número da página do livro; 
# • voltar_uma_pagina: volta uma página do livro caso ele esteja com o guardado em 
# False e mostra em qual página do livro está (sempre começando em 1), e não podendo 
# ultrapassar o limite de quantidade de páginas. Tem como output o número da página 
# do livro; 
# • voltar_n_paginas: volta uma quantidade n de páginas do livro caso ele esteja com o 
# guardado em False e mostra em qual página do livro está (sempre começando em 1), 
# e não podendo ultrapassar o limite de quantidade de páginas. Tem como output o 
# número da página do livro; 
# • ler_livro: mostra um output do nome e do autor do livro. 
