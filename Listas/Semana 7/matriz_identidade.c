#include <stdio.h>

void imprimirMatriz(int n, int m,int matriz[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matriz[i][j]);    
        }
        printf("\n");
   }      
}

int main(){
    int dimensao;
    
    scanf("%d", &dimensao);
    
    int matrizIdentidade[dimensao][dimensao];
    
    for(int i = 0; i < dimensao; i++){
        for(int j = 0; j < dimensao; j++){
            if(i == j){
                matrizIdentidade[i][j] = 1;
            }else{
                matrizIdentidade[i][j] = 0;
            }
        }
    }
    
    imprimirMatriz(dimensao, dimensao, matrizIdentidade);
}