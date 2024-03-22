#include <stdio.h>
int main(){
    int num;
    int count=0;

    printf("Enter a number for discover it: ");
    scanf("%i", &num);
    for(int i =1;i<=2;i++)
    {
        num = num/10;
        while(num!=0){
            count +=num;
        }
        
    }
    printf("%i",count);

}
//     do{
//         num = num / 10;
//         count ++;

//     }while (num != 0);

//     // for(;num > 0;num/10){
//     //     count ++;
//     // };
//     printf(" %i ",count);

// }
