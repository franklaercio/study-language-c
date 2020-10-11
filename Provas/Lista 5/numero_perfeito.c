#include <stdio.h>

int imprimirDivisores(int numero){
    for(int i=0; i <= numero; i++){
        if(numero%i == 0){
            printf("%d", numero);
        }
    }
}

int main () {
    int numero;
    scanf("%d", &numero);

    imprimirDivisores(numero);

    return 0;
}