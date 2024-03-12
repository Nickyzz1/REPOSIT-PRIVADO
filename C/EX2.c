#include <stdio.h>

int main(){
    float n;
    printf("Choose one number for convert to fahrenheit: ");
    scanf("%f", &n);
    float f = n*1.8 +32;
    printf("O valor em Farenheits: %f\n",f);
    float k = (n+459.67)*5/9;
    printf("O valor em Kelvin :%f\n ", k); 

    
}
