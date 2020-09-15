#include <stdio.h>

int main() {
    int stop = 1;


    do{
        int rgb1 = 0;
        int rgb2 = 0;
        int rgb3 = 0;

        scanf("%i %i %i", &rgb1, &rgb2, &rgb3);

        if (rgb1 < 0 || rgb2 < 0 || rgb3 <0)  {
            stop = 0;
        }else{
            printf("%02X%02X%02X\n", rgb1, rgb2, rgb3);
        }
    }while(stop == 1);

    return 0;
}