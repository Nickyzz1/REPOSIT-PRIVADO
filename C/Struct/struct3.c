#include <stdio.h>

typedef struct {
    char name[10];
    int registration;
    int nota1;
    int nota2;
    int nota3;
} Student;

int main() {
    // cria as variáveis usadas
    Student student[5];
    int meanBig = 0;
    int meanLow = 10; // Inicializar com o maior valor possível
    int meanStudent = 0;
    char arrayAprovados[5][10];
    char arrayReprovados[5][10];
    int countAprovados = 0;
    int countReprovados = 0;

    // cria os 2 alunos
    for (int i = 0; i < 2; i++) {
        
        printf("Enter a student %i: ", i);
        scanf("%s", student[i].name);
        printf("Enter the registration %i: ", i);
        scanf("%d", &student[i].registration);
        printf("Enter the grade for the first test %i: ", i);
        scanf("%d", &student[i].nota1);
        printf("Enter the grade for the second test %i: ", i);
        scanf("%d", &student[i].nota2);
        printf("Enter the grade for the third test %i: ", i);
        scanf("%d", &student[i].nota3);

        // Calcula a média do estudante
        meanStudent = (student[i].nota1 + student[i].nota2 + student[i].nota3) / 3;

        // Calcula a média mais alta
        if (meanStudent > meanBig) {
            meanBig = meanStudent;
        }

        // Calcula a média mais baixa
        if (meanStudent < meanLow) {
            meanLow = meanStudent;
        }

        // Verifica se o aluno foi aprovado ou reprovado
        if (meanStudent >= 6) {
            // Adiciona à lista de aprovados
            for (int j = 0; student[i].name[j] != '\0'; j++) {
                arrayAprovados[countAprovados][j] = student[i].name[j];
            }
            countAprovados++;
        } else {
            // Adiciona à lista de reprovados
            for (int j = 0; student[i].name[j] != '\0'; j++) {
                arrayReprovados[countReprovados][j] = student[i].name[j];
            }
            countReprovados++;
        }
    }

    // mostra os resultados
    printf("\n\nThe biggest mean: %d", meanBig);
    printf("\n\nThe Lowest mean: %d", meanLow);

    printf("\n\nAproved:\n");
    for (int i = 0; i < countAprovados; i++) {
        printf("%s\n", arrayAprovados[i]);
    }

    printf("\n\nReproved:\n");
    for (int i = 0; i < countReprovados; i++) {
        printf("%s\n", arrayReprovados[i]);
    }

    return 0;
}
