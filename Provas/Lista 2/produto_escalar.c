#include <stdio.h>
#include <math.h>

int main() {
    int tamanhoVetor, i, j,k;
    int escalar;

    float comprimento1, comprimento2;
    
    scanf("%i", &tamanhoVetor);
    
    int v1[tamanhoVetor];
    int v2[tamanhoVetor];
    
    for(i = 0; i < tamanhoVetor; i++) {
        int numero;
        scanf("%i", &numero);
        v1[i] = numero;
        comprimento1 += numero*numero;
    }
    
    for(j = 0; j < tamanhoVetor; j++) {
        int numero;
        scanf("%i", &numero);
        v2[j] = numero;
        comprimento2 += numero*numero;
    }

    for (k = 0; k < tamanhoVetor; k++) {
        escalar += v1[k]*v2[k];
    }

    printf("%i %.2f %.2f" , escalar, sqrt(comprimento1), sqrt(comprimento2));
    
    
    return 0;
}