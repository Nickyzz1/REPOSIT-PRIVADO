#include <stdio.h>
#include <string.h>

int main(){
    char numerosAlunos[5][18] ={{"41999999999"},{"41988888888"},{"41977777777"}};
    char materias[5][18] = {{"Matematica"},{"Geografia"},{"Portugues"},{"Ingles"}};
    char nomesAlunos[][8] = {{}, {"Amilton"}, {"Jose"}};
    float notas[3][10] = {{10.0, 6.0, 6.0},{10.0, 5.0, 6.4}};

    char nome[50] = "";
    int qtdAlunos = 0, i = 0, j = 0;
    int len = sizeof(nome)/sizeof(nome[0]);
    int lenNomes = sizeof(nomesAlunos[0])/sizeof(nomesAlunos[0][0]);

    printf("Quantos alunos voce quer adicionar?\n");
    scanf("%d", &qtdAlunos);
    while(i < qtdAlunos){
        printf("Digite o nome do aluno:\n");
        scanf("%s", nome);
        for(int i = 0; i < len; i++){
            nomesAlunos[j][i] = nome[i];
        }
        i ++;
        j ++;
    }
    for(int i = 0; i < lenNomes; i++){
        printf("%s\n", nomesAlunos[i]);
    }
}
