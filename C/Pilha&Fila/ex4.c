#include <stdio.h>
#include <stdlib.h>

struct Car{
    char placa[10];
    char color[10];
    char brand[20];
    char model[20];
    char year[4];
};
//adc items a array cars
struct Car * add(struct Car * arr, int n)
{
    for(int i = 0 ; i < n; i++)
    {
        printf("\nEnter a number identification %i: ", i);
        scanf("%s", arr[i].placa);
        printf("\nEnter a color %i: ", i);
        scanf("%s", arr[i].color);
        printf("\nEnter a brand %i: ", i);
        scanf("%s", arr[i].brand);
        printf("\nEnter a model %i: ", i);
        scanf("%s", arr[i].model);
        printf("\nEnter a year %i: ", i);
        scanf("%s", arr[i].year);
        printf("%s", "\n");
    }
    return arr;
}

int main()
{
    int n;
    printf("Enter how many vehicles you wanna add: ");
    scanf("%i", &n);
    struct Car * cars = (struct Car*)malloc(sizeof(struct Car)*n);
    add(cars, n);

    printf("\n==================== FICHA ======================+\n");
    
    for(int i = 0; i < n; i++)
    {
        printf("\nThe color is %i: %s",i, cars[i].color);
        printf("\nThe brand is %i: %s",i, cars[i].brand);
        printf("\nThe model is %i: %s",i, cars[i].model);
        printf("\nThe identify is %i: %s",i, cars[i].placa);
        printf("\nThe year is %i: %s",i, cars[i].year);
        printf("%s", "\n");
    }
    free(cars);
}
// Crie um programa que permita a leitura de diferentes veículos(Placa, Cor, Marca, Modelo, Ano). 
// O usuário poderá escolher a quantidade de veículos que serão lidos. após isso, imprima os dados