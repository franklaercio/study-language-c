#include <stdio.h>
#include <string.h>

int imprimirVetor(int numeros[5]){
    for (int i = 0; i < 5; i++){
        printf("%d ", numeros[i]);
    }
    printf("\n");
    return 0;
}

int imprimirOrdemCrescenteDecrescente(int numeros[5]){
    int i, k;
    char numeroAux;

    for (i = 5; i > 0; i--){
        for (k = 0; k < i; k++){
            if(numeros[k] > numeros[k + 1]) {
                numeroAux = numeros[k];
                numeros[k] = numeros[k+1];
                numeros[k+1] = numeroAux;                     
            }
        }
    }

    imprimirVetor(numeros);

    for (i = 4; i >= 0; i--){
        printf("%d ", numeros[i]);
    }

    printf("\n");
    
    return numeros[40];
}

int main () {
    int numeros[5];
    int ordemDigitacao[5];

    for (int i = 0; i < 5; i++){
        int numero = 0;
        scanf("%d", &numero);
        numeros[i] = numero;
        ordemDigitacao[i] = numero;
    }
    
    imprimirOrdemCrescenteDecrescente(numeros);
    
    imprimirVetor(ordemDigitacao);

    return 0;
}