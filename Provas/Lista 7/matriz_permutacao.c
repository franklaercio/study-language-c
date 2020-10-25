#include <stdio.h>
#include <stdbool.h>

void preencherMatriz(int n, int m, int matriz[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

int main(){
    int quadrado, contador = 0;
    bool isMatrizPermutacao = true;

    scanf("%i", &quadrado);
    
    int matriz[quadrado][quadrado];
    
    preencherMatriz(quadrado, quadrado, matriz);
    
    for(int i = 0; i < quadrado; i++){
        for(int j = 0; j < quadrado; j++){         
            if(matriz[i][j] == 1){
                contador++;
            }       
        }
        if(contador > 1){
          isMatrizPermutacao = false;
          break;
        }else{
          contador = 0;
        }
    }    

    isMatrizPermutacao ? printf("1") : printf("0");
    
    return 0;
}