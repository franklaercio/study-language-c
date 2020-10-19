#include <stdlib.h>
#include <stdio.h>
#include <math.h>

double pi(int i){
  if(i == 0){
    return 4 * pow(-1,i) / (2*i+1);
  }

  return (4 * pow(-1,i) / (2*i+1)) + pi(i - 1);
}

int main(){
    int p;
    char format[20];
    int valorPi = 0;
    int valorAnterior = 1;
    int i = 0;
    
    scanf("%d", &p);

    while(((valorPi * pow(10, p)) - (valorAnterior * pow(10, p))) != 0){
        if(i == 10000){
            valorPi = -1;
        }
        
        valorAnterior = pi(i - 1);
        valorPi = pi(i);
        i++;
    }

    sprintf(format, "Valor de pi %%.%dlf\n",p);
    printf(format,valorPi);

    return 0;
}