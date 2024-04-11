#include <stdio.h>
int main(){
    char matriz[][100] = {{}, {"fer"}};
    printf("Enter a name: ");
    scanf("%s", &matriz[0]);
    printf("%s\n", matriz[0]);
}
