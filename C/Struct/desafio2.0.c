#include <stdio.h>
#include <stdlib.h>

struct Student{
    char name[50];
    char course[50];
    int registration;
};

int main()
{   
    int numStudents = 0;
    struct Student *arrayStudents = (struct Student *) malloc(sizeof(struct Student)*(numStudents));

    printf("+===========WELCOME===============+\n");

    int fla = 1;
    int option;
    int addStudents;
    int index;

    while (fla == 1)
    {
        printf("\n+=============MENU===============+\n");
        printf("| 1 - Add students ================|\n");
        printf("| 2 - See students ================|\n");
        printf("| 3 - Change data of student ======|\n");
        printf("| 4 - Exit ========================|\n");

        scanf("%i", &option);

        switch (option)
        {
            case 1:

                printf("Enter how many students you want to add: ");
                scanf("%d", &addStudents);

                arrayStudents = realloc (arrayStudents, sizeof(struct Student) * (numStudents + addStudents));
                
                for(int i = 0; i < addStudents; i++)
                {
                    printf("\nEnter a name: ");
                    scanf("%s", arrayStudents[i].name);

                    printf("Enter a course: ");
                    scanf("%s" , arrayStudents[i].course);

                    printf("Enter a registration: ");
                    scanf("%d", &arrayStudents[i].registration);

                    printf("%s", "\n");

                }

                numStudents += addStudents;
                break;//case 1

            case 2:
                for(int i = 0; i < numStudents; i++)
                {
                    printf("Student %d:\n", i);
                    printf("Name: %s " , arrayStudents[i].name);
                    printf("%s", "\n");
                    printf("Course: %s ", arrayStudents[i].course);
                    printf("%s", "\n");
                    printf("Registration: %d", arrayStudents[i].registration);
                    printf("%s", "\n\n");
                }
                break; //case 2

            case 3:

                printf("Enter a index for changing datas: ");
                scanf("%d", &index);

                int opChange;
                printf("\nWhat you want to change:\n1 - name\n2 - course\n3 - registration\n");
                scanf("%i", &opChange);

                if(opChange == 1)
                {
                    printf("Enter a new name: ");
                    scanf("%s", arrayStudents[index].name);
                    
                }else if(opChange == 2)
                {
                    printf("Enter a new course: ");
                    scanf("%s", arrayStudents[index].course);
                }
                else if(opChange == 3){
                    printf("Enter a new registration: ");
                    scanf("%d", &arrayStudents[index].registration);
                }else{
                    printf("Invalid option!\n");
                }
                break; //case 3

            case 4:
                printf("Exiting...\n");
                fla = 0;
                break; //case 4

            default:
                break; 

        }//switch

    }//while

    free(arrayStudents);

}//main

//Crie uma struct Student com campos nome (char[50]), curso (char[50]) e matricula (int).
// O número inicial de estudantes será fornecido pelo usuário.
// Alocar memória dinamicamente para armazenar os estudantes.
// Permitir ao usuário adicionar novos estudantes (realocando a memória conforme necessário).
// Permitir ao usuário visualizar os dados dos estudantes cadastrados.
// Liberar a memória alocada ao final do programa.
