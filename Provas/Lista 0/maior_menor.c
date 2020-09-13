/**
 * Escreva um programa que:

Leia do usuário 3 números inteiros
Caso os 3 números sejam iguais, imprima “ Os três números são iguais “
Caso os números não sejam iguais, o programa deve computar o maior e o menor entre os 3 números e imprimir: “O menor número é <menor> e o maior número é <maior>”, onde <menor> e <maior> são os valores do menor e maior números lidos.
 *  
**/
#include <stdio.h>

int main(){
    int number1;
    int number2;
    int number3;

    scanf("%i %i %i", &number1, &number2, &number3);

    if(number1 == number2 && number1 == number3 && number2 == number1 && number2 == number3){
        printf("Os três números são iguais");
    }else{
        int bigger;
        int smaller;
        
        int numbers[] = {number1, number2, number3};
        int size = 3;
        
        for (int i = 0; i <= size; i++){
            if (numbers[i] >= number1 && numbers[i] >= number2 && numbers[i] >= number3) {
                bigger = numbers[i];
            }

            if (numbers[i] <= number1 && numbers[i] <= number2 && numbers[i] <= number3) {
                smaller = numbers[i];
            }
        }

        printf("O menor número é %i e o maior número é %i", smaller, bigger);
    }

    return 0;
}
