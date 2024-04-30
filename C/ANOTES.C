// //ponteiro aponta o arquivo FILE *arquivo
// //SEMPRE que vc der fopen, sempre de fclose

// //ex: código paraa abrir um txt em #C
// //condicionais--> condição, num labirinto vc vai para onde tem luz; isso é condicional
// //cada hexa = 4bits

// //um inteiro = 4 bytes = 32 bits

// // recursiva
// // ponteiro
// // função com parâmeto de ponteiro

// // while
// // do while 
// // ponteiros --> fazer código
// // função recursiva
// // ponteiro
// // parâmetro de função sendo ponteiro
// // for sobre for
// // estudar loops
// // pode usar printf dentro da função
// // io: input, output
// // txt
// // heather
// // 10 questões
// //16 bits --> odis bytes--> 4hexas





// //#include <stdio.h>
// //int main(){
//     //FILE * arquivo;
//     //char nome[50];
//     //prinf("Digite o nome do arquivo TXT: ");
//     //scanf("%s", &nome);

//     //arquivo = fopen(nome, "w");
//     //fprint(arquivo,"%s", "ola");
//     //fclose(arquivo);

//     //return 0;


// //operador ternário

// //int a =10
// //int b = 20
// //int c;
// //c = (a < b)? a:b
// //orintf("%d", c)

// //sempre que fizer um sweet coloque um break ou ele não irá parar, irá ler mais do que precisa  e dará erro


// #include <stdio.h>
// #include <windows.h>

// // int main(){
// //     system("color 5");
// //     printf("OIII");
// //     system("pause");
// //     system("color 7");
// // }


// // int main(){
// //     for(int i = 0;i <10;i++){ //i++ é = i+1, for(int i = ponto_de_partida;i=limite_loop;i++)
// //         printf("oi\n");

// // }}



// //for infinito

// // for(;;){  
// //     printf("olá")
// // }




// //for com variável
// // int main(){
// // //   int i = 0;
// //     for(int i=0;i<10;i++){
// //         printf("mais\n");

// // }

// // }



// // int main(){
// //     int alunos = 0;

// //     while(alunos <30){
// //         alunos ++;
// //         printf("Quantidade de alunos: %i\n", alunos);
// //     }
// // }


// // int main(){
// //     int alunos =0;
// //     do {
// //         alunos ++;
// //         printf(alunos);
// //     }while(alunos<1);

// // }

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     FILE * File = fopen("Texto.txt", "r+");
//     int Size = 1;
//     rewind(File);
//     while(fgetc(File) != EOF){++Size;}
//     char * Text = malloc(Size);
//     rewind(File);
//     fread(Text, 1, Size, File);
//     printf("%s", Text);
//     fclose(File);
// }

// #include <stdio.h>
// #include <stdlib.h>
// int main()
// {
//     FILE * File = fopen("Texto.txt", "r+");
//     int Size = 1;
//     rewind(File);
//     while(fgetc(File) != EOF){++Size;}
//     char * Text = malloc(Size);
//     rewind(File);
//     fread(Text, 1, Size, File);
//     printf("%s", Text);
//     fclose(File);
// }

// Troca de Valores: Crie uma função que receba dois ponteiros como parâmetros e troque os valores das variáveis para as quais apontam.
// Soma de Elementos: Escreva uma função que receba um array e seu tamanho como parâmetros e retorne a soma de todos os elementos do array usando ponteiros.
// Maior e Menor Elemento: Crie uma função que receba um array e seu tamanho como parâmetros e use ponteiros para encontrar o maior e o menor elemento do array.
// Ordenação de Array: Implemente uma função que ordene um array de inteiros em ordem crescente usando ponteiros.
// Verificação de Palíndromo: Escreva uma função que receba uma string como parâmetro e use ponteiros para verificar se a string é um palíndromo (ou seja, se ela é igual quando lida de trás para frente).

