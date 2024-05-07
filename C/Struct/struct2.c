#include <stdio.h>

typedef struct{
    char name[10];
    int registration;
    char course[20];

}Student;

int main() 
{
    //vetor array que contera os estudantes
    Student student[5]; 
    //fazendo for para criar 5 alunos
    for(int i = 0; i < 5; i++) {
        printf("\nEnter a name %i: ", i);
        scanf("%s", &student[i].name);
        printf("\nEnter a registration: ");
        scanf("%d", &student[i].registration);
        printf("\nEnter a course: ");
        scanf("%s", &student[i].course);
    }
    //printando
    for(int i = 0; i < 5 ; i++) {

        printf("Student: %s\n", student[i].name);
        printf("Reghistration: %d\n", student[i].registration);
        printf("Course: %s\n", student[i].course);
        printf("%s", "\n\n");
    }
}

//scanf("%99[^\n]%*c", student[i].course);
