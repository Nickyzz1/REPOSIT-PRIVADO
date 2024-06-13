#include <stdio.h>

int * insertion(int * arr, int len)
{
    int i,j, key; //key is a value and j and i are index
    for(i = 1; i < len; i++)
    { //{5,0,0,1}
        key = arr[i]; //thats a value
        j = i - 1; // so, if i beging in 1 the first value of j is 0, thats for compare index
        while(j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j]; // abro espaço, a posição j agpora está "vazia" e arr[i] = key
            j--;
        }
        arr[j + 1] = key;
    }
    return arr;
}
void display(int * arr, int len)
{
    for(int i = 0; i < len; i++)
    {
        printf("[%d]", arr[i]);
    }
}


int main()
{
    int arr[] = {1,1,0,90,0};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("\nThe unorder array: ");
    display(arr, len);
    insertion(arr, len);
    printf("\nThe order array: ");
    display(arr, len);

}
