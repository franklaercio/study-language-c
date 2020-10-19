#include <stdio.h>

int fibonnaci(int n){
    if(n <= 1){
        return n;
    }

    return fibonnaci(n-1) + fibonnaci(n-2);
}

int main(){
    int inicio;
    int fim;
    int sequenciaFibbonaci[20];

    scanf("%i", &inicio);
    scanf("%i", &fim);

    for (int i = 0; i < 20; i++){
        int numeroFibonnaci = fibonnaci(i);
        sequenciaFibbonaci[i] = numeroFibonnaci;
    }

    for (int i = inicio; i < fim; i++){
        for (int k = 0; k < 20; k++){
            if((sequenciaFibbonaci > inicio && sequenciaFibbonaci < fim)){
                printf(i);
            }
        }
    }
    
    return 0;
}