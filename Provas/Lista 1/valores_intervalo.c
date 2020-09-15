#include <stdio.h>

int main() {
    int number1;
    int number2;
    int bigger;
    int smaller;

    scanf("%i %i", &number1, &number2);

    if (number1 > number2) {
        bigger = number1;
        smaller = number2;
    }else {
        bigger = number2;
        smaller = number1;
    }

    if (bigger != smaller && !((bigger - smaller) == 1)) {
        for (int i = smaller + 1; i < bigger; i++){
            printf("%i ", i);
        }
    }else{
        printf("intervalo vazio");
    }

    return 0;
}