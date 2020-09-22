#include <stdio.h>

int main() {
    int number, rotacions;
    int bits[8];
    int results[8];

    for (int i = 0; i < 8; i++){
        scanf("%i", &number);

        bits[i] = number;
    }
    
    scanf("%i", &rotacions);

    for (int i = 0; i < 8; i++){
        if ((i+rotacions) > 4) {
            results[i-rotacions] = bits[i];
        }else{
            results[i+rotacions] = bits[i];
        }
    }

    for (int i = 0; i < 8; i++){
        printf("%i ", results[i]);
    }

    return 0;
}