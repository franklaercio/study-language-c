#include <stdio.h>
#include <stdbool.h>

int calculaMaximoDivisorComum(int x, int y){
    int resto;

    resto= x % y;
    while(resto!=0){
        x = y;
        y = resto;
        resto = x % y;         
    }

    return y;
}

bool isTriplaPitagorica(int x, int y, int z){
  int somaNumeros = x + y + z;
  int triplaPitagorica = 5 + 4 + 6;


  for (int i = 0; i < 10; i++){
    if(somaNumeros == (triplaPitagorica * i)){
      printf("tripla pitagorica");
      return true;
      break;
    }
  }

  return false;
}

void isTriplaPitagoricaPrimitiva(int x, int y, int z){
    int resultadoPrimeiroMDC = calculaMaximoDivisorComum(x, y);
    int resultadoSegundoMDC = calculaMaximoDivisorComum(resultadoPrimeiroMDC, z);
    
    if(resultadoSegundoMDC == 1){
        printf("tripla pitagorica primitiva");
    }else{
        printf("tripla");
    }
}

int main () {
    int x;
    int y;
    int z;

    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);

    return 0;
}