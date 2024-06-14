#include <stdio.h>

//coloca um elemento ao final da fila
void enqueue(int * arr, int *n, int value)
{
    int newArr[*n + 1]; //0,1,2,3,4,5
    for(int i = 0; i < *n ; i++)
    {
        newArr[i] = arr[i];
        printf("[%i]", newArr[i]);
    }

    newArr[*n + 1] = value; // add depois do ultimo elemento da fila que é o 5 nesse caso
    printf("[%i]", newArr[*n + 1]);
    *n += 1;
    // arr = newArr;
    // return arr;
}
//retira o primeiro elemento da fila
void dequeue(int * arr, int *n)
{
    int newArr[*n-1];
    *n -=1;
    for(int i = 0; i < *n; i++)
    {
        newArr[i] = arr[i + 1];
        printf("[%i]", newArr[i]);
    }
    arr = newArr;
    //return arr;
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
        printf("\n1 - enqueue ======================\n");
        printf("\n2 - dequeue ======================\n");
        scanf("%i", &option);

        if(option == 0)
        {
            break;
        }
        else if(option == 1)
        {
            int value;
            printf("\nEnter a value for enqueue: ");
            scanf("%d", &value);
            enqueue(arr, &n, value);
            break;
        }
        else if(option == 2)
        {
            dequeue(arr, &n);
            break;
        }
        else
        {
            printf("Enter a valid option");
        }
    }
}