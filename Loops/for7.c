#include <stdio.h>

int main() {
    int num;
    int count = 0;
    int fla = 1;

    printf("Enter a number to discover it: ");
    scanf("%i", &num);

    for (int i = 1; i <= 255; i++) {
        while (fla == 1) {
            while (num != 0) {
                //num = num / 10;Esta linha divide o valor atual de num por 10 e atribui o resultado de volta a num. Isso basicamente remove o último dígito do número. Por exemplo, se num for 123, após esta operação, num será 12
                count += 1;
            }
            fla = 0;
        }
    }

    printf("Number of digits: %d\n", count);

    return 0;
}
