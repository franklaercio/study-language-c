/** 
 * Escreva um programa que receba um número inteiro de 1 à 100000 e separe os dígitos do número, imprimindo na saída os dígitos em linhas diferentes. 
**/
#include <stdio.h>

int count(int i) {
 int ret = 1;

 while (i/=10) {
    ret++;
 }

 return ret;
}

int main() { 
    int number, countDigits;

    int i = 0; 
    int j, digit; 

    do {
        scanf("%i", &number);

        if (number < 1 || number > 100000) {
            printf("O número deve está dentro do intervalo 1 a 100000");
        }

        countDigits = count(number);
    } while (number < 1 || number > 100000);

    int numbers[countDigits];

    while (number != 0) { 
        digit = number % 10; 
        numbers[i] = digit; 
        i++; 
        number = number / 10; 
    } 
  
    for (j = i - 1; j > -1; j--) { 
        printf("%d \n", numbers[j]); 
    }

    return 0; 
}  