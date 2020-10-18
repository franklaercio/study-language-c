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
    int numeroFibonnaci = 0;
    int contador = 0;
    int sequencia = 0;

    scanf("%i", &primeiroIntervalo);
    scanf("%i", &segundoIntervalo);

    do{
      numeroFibonnaci = fibonnaci(sequencia);
      
      if(numeroFibonnaci > primeiroIntervalo && numeroFibonnaci < segundoIntervalo){
            contador++;
      }

      sequencia++;
    }while(sequencia != 20);  

    printf("Existem %i números de fibonacci entre %i e %i", contador, primeiroIntervalo, segundoIntervalo);

    return 0;
}