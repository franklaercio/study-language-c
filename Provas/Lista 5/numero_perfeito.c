#include <stdio.h>
#include <stdbool.h>

int imprimeNumeroPerfeito(int numero){
  printf("%i = 1", numero);

  for(int i=2; i <= numero; i++){
    if(numero % i == 0 && numero != i){
      printf(" + %i", i);
    }
  }

  return 0;
}

bool isNumeroPerfeito(int numero){
    int resultado = 0;

    for(int i=1; i <= numero; i++){
        if(numero % i == 0 && numero != i){
          resultado += i;
        }
    }

    if (resultado == numero){
      imprimeNumeroPerfeito(numero);
    }else{
      printf("%i nao eh perfeito", numero);
    }

    return 0;
}

int main () {
    int numero;
    scanf("%d", &numero);

    isNumeroPerfeito(numero);

    return 0;
}