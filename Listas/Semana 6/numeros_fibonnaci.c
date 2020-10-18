#include <stdio.h>

int fibonnaci(int n){
    if(n <= 1){
        return n;
    }

    return fibonnaci(n-1) + fibonnaci(n-2);
}

int main(){
    int primeiroIntervalo;
    int segundoIntervalo;
    int contador = 0;

    scanf("%i", &primeiroIntervalo);
    scanf("%i", &segundoIntervalo);

    for (int i = 0; i < segundoIntervalo; i++) {
        int numeroFibonnaci = fibonnaci(i);

        if(numeroFibonnaci > primeiroIntervalo && numeroFibonnaci < segundoIntervalo){
            contador++;
        }
    }    

    printf("Existem %i números de fibonacci entre %i e %i", contador, primeiroIntervalo, segundoIntervalo);

    return 0;
}