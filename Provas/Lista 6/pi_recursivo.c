#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double pi(int i){
  if(i == 0){
    return 4 / ((2*i+1) * pow(-1, i));
  }

  return (4 / ((2*i+1) * pow(-1, i)) + pi(i - 1));
}

double calcularPi(int p){
  double valorPi = 0;
  double piAnterior = 1;

  for(int i = 0; i < 10001; i++){
    if(((floor(valorPi*pow(10, p))) - (floor(piAnterior*pow(10, p)))) == 0){
      break;
    }

    piAnterior = valorPi;
    valorPi = pi(i);

    if(i == 10000){
      valorPi = -1;
    }
  }

  return valorPi;
}

int main(){
    int p;
    char format[20];
    double pi = 0;
    
    scanf("%d", &p);
    
    pi = calcularPi(p);  

    sprintf(format, "Valor de pi %%.%dlf\n",p);
    printf(format,pi);

    return 0;
}