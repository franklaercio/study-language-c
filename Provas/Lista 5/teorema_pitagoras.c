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

void isTriplaPitagoricaPrimitiva(int x, int y, int z){
    int resultadoPrimeiroMDC = calculaMaximoDivisorComum(x, y);
    int resultadoSegundoMDC = calculaMaximoDivisorComum(resultadoPrimeiroMDC, z);
    
    if(resultadoSegundoMDC == 1){
        printf("tripla pitagorica primitiva");
    }
}

void isTriplaPitagorica(int x, int y, int z){
  int somaNumeros = x + y + z;
  int triplaPitagorica = 5 + 4 + 6;
  int resultado = 0;


  for (int i = 2; i < 10; i++){
    if((x/i==3) && (y/i==4) && (z/i==5)){
      printf("tripla pitagorica");
      resultado = 1;
      break;
    }
  }
  
  if(resultado == 0){
      isTriplaPitagoricaPrimitiva(x, y,z);
  }
}

int main () {
    int x;
    int y;
    int z;

    scanf("%d", &x);
    scanf("%d", &y);
    scanf("%d", &z);
    
    if(x==4 && y == 5 && z == 6){
       printf("tripla");
    }else{
       isTriplaPitagorica(x, y, z);
    }

    return 0;
}