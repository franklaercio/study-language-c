#include <stdio.h>
#include <string.h>

int ordenarVetorCrescente(int numeros[5]){
    int i, k;
    char numeroAux;

    for (i = strlen(numeros) - 1; i > 0; i--){
        for (k = 0; k < i; k++){
            if(numeros[k] > numeros[k + 1]) {
                numeroAux = numeros[k];
                numeros[k] = numeros[k+1];
                numeros[k+1] = numeroAux;                     
            }
        }
    }
    
    return numeros[40];
}

int ordenarVetorDecrescente(int numeros[5]){
    int i, k;
    char numeroAux;

    for (i = strlen(numeros) - 1; i > 0; i--){
        for (k = 0; k < i; k++){
            if(numeros[k] < numeros[k + 1]) {
                numeroAux = numeros[k];
                numeros[k] = numeros[k+1];
                numeros[k+1] = numeroAux;                     
            }
        }
    }
    
    return numeros[40];
}

void imprimirVetor(int numeros[5]){
    for (int i = 0; i < 5; i++){
        printf("%d", numeros[i]);
    }
}

int main () {
    char numeros[5];

    for (int i = 0; i < 5; i++){
        char numero;
        scanf("%d", numero);
    }

    char crescente = strcpy(numeros);
    int decrescente = strcpy(numeros);
    
    ordenarVetorCrescente(crescente);
    ordenarVetorCrescente(decrescente);







    return 0;
}