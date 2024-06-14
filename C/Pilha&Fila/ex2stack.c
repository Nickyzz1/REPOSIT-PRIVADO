#include <stdio.h>
//adc um elemento após o ultimo elemento da stack
void push(int * arr, int *n, int value)
{
    int newArr[*n + 1]; //0,1,2,3,4,5
    printf("\npush with sucessfully\n");
    for(int i = 0; i < *n ; i++)
    {
        newArr[i] = arr[i];
        printf("[%i]", newArr[i]);
    }

    newArr[*n + 1] = value; // add depois do ultimo elemento adc atack que é o 5 nesse caso
    printf("[%i]", newArr[*n + 1]);
    *n += 1;
}
//tira o ultimo elemento adc a stack
void pop(int * arr, int *n)
{
    printf("\npop was sucessfully\n");
    int newArr[*n-1];
    *n -=1;
    for(int i = 0; i < *n; i++)
    {
        newArr[i] = arr[i];
        printf("[%i]", newArr[i]);
    }
    arr = newArr;
}

//retorna o primeiro elemento da pilha
void top(int *arr, int n)
{
    printf("top is: %d", arr[n - 1]);
}

int main()
{
    int arr[] = {1,2,3,4,5}; //primeiro sai e ultimo entra
    int n = 5;
    int option;
    
    while(1)
    {
        printf("\n======================\n");
        printf("\n0 - exit ======================\n");
        printf("\n1 - push ======================\n");
        printf("\n2 - pop ======================\n");
        printf("\n3 - top ======================\n");
        scanf("%i", &option);

        if(option == 0)
        {
            printf("goodbye!");
            break;
        }
        else if(option == 1)
        {
            int value;
            printf("\nEnter a value for push: ");
            scanf("%d", &value);
            push(arr, &n, value);
            break;
        }
        else if(option == 2)
        {
            pop(arr, &n);
            break;
        }
        else if(option == 3)
        {
            top(arr, n);
            break;
        }
        else
        {
            printf("Enter a valid option");
        }
    }
}