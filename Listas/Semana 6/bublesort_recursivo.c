#include <stdlib.h>
#include <stdio.h>  

void bubbleSort(int numeros[], int tamanho){
    if(tamanho == 1){
        return;
    }

    for (int i=0; i< tamanho-1; i++){
        if (numeros[i] > numeros[i+1]){
            int temp = numeros[i];
            numeros[i] = numeros[i + 1];
            numeros[i + 1] = temp;
        }    
    }
    
    bubbleSort(numeros, tamanho-1);        
}

int main(){
  int tamanho;
  scanf("%i", &tamanho);  

  int numeros[tamanho];  
  srand(1); 

  for(int i=0; i < tamanho; i++){
    int rand_num = rand()%100; //gera um número aleatório entre 0 e 99
    numeros[i] = rand_num;
    printf("%d ", rand_num);
  }
  
  printf("\n");

  bubbleSort(numeros, tamanho);

  for (int i = 0; i < tamanho; i++){
      printf("%d ", numeros[i]);
  }
}