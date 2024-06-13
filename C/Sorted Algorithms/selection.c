#include <stdio.h>

int * selection(int * arr, int len)
{
    for(int i = 0; i <len; i++)
    {
        int low = i;
        for(int j = i; j < len; j++ )
        {
            if(arr[low] > arr[j])
            {
                low = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[low];
        arr[low] = temp;
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
    //int arr[] = {1,1,0,90,0};
    int arr[] = {11,3,2,2, 0, 0, 90, 10, 500};
    int len = sizeof(arr)/sizeof(arr[0]);
    printf("\nThe unorder array: ");
    display(arr, len);
    selection(arr, len);
    printf("\nThe order array: ");
    display(arr, len);

}
