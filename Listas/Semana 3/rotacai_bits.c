#include <stdio.h>

int main() {
    int number, rotacions;
    int bits[8];

    for (int i = 0; i < 8; i++){
        scanf("%i", &number);

        bits[i] = number;
    }
    
    scanf("%i", &rotacions);

    for (int i = 0; i < 8; i++){
        printf("%i ", bits[i]);
    }

    return 0;
}