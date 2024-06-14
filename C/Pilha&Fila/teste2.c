#include <stdio.h>

int *enqueue(int *arr, int *n, int value)
{
    int newArr[*n + 1];
    for(int i = 0; i < *n; i++)
    {
        newArr[i] = arr[i];
    }
    newArr[*n] = value; // add depois do ultimo elemento da fila que é o 5 nesse caso
    *n += 1;
    arr = newArr;
    return arr;
}

int *dequeue(int *arr, int *n)
{
    int newArr[*n-1];
    for(int i = 0; i < *n; i++)
    {
        newArr[i] = arr[i + 1];
    }
    *n -=1;
    arr = newArr;

    // for(int i = 0; i < *n; i++)
    // {
    //     printf("[%d]", arr[i]);
    // }
    return arr;
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
        printf("\n3 - display======================\n");
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
        }
        else if(option == 2)
        {
            dequeue(&arr, &n);
        }
        else if(option == 3)
        {
            for(int i = 0; i < n; i++)
            {
                printf("[%d]", arr[i]);
            }
        }
        else
        {
            printf("Enter a valid option");
        }
    }
}