#include <stdio.h>
#include <math.h>

int main() {
    int number1, number2, smaller, bigger;
    int total = 0;

    scanf("%i %i", &number1, &number2);

    if (number1 > number2) {
        bigger = number1;
        smaller = number2;
    }else {
        bigger = number2;
        smaller = number1;
    }

    for (int i = smaller; i <= bigger; i++){
        total += i;
    }

    printf("%i", total);

    return 0;
}