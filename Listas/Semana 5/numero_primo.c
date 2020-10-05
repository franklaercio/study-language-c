#include <stdio.h>
#include <stdbool.h>

void verificarPrimo(int numero){
    int resultado = 0;

    for (int i = 2; i <= numero / 2; i++) {
        if (numero % i == 0) {
        resultado++;
        break;
        }
    }

    if(resultado == 0){
        printf("%d eh primo\n", numero);
    }else{
        printf("%d nao eh primo\n", numero);
    }
}

int main(){
    int quantidade;
    scanf("%d", &quantidade);

    for (int i = 0; i < quantidade; i++){
        int primo;
        scanf("%d", &primo);

        verificarPrimo(primo);
    }

    return 0;
}