#include <stdio.h>

void lerMatriz(int n, int m, int matriz[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

void imprimirMatriz(int n, int m,int matriz[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            printf("%d ", matriz[i][j]);    
        }
        printf("\n");
   }      
}

int main(){
    int linha, coluna, numero;
    
    scanf("%d %d", &linha, &coluna);
    
    int A[linha][coluna];
    int B[linha][coluna];
    int C[linha][coluna];
    
    lerMatriz(linha, coluna, A);
    lerMatriz(linha, coluna, B);
    
    for(int i = 0; i < linha; i++){
        for(int j = 0; j < coluna; j++){
            C[i][j] = A[i][j] + B[i][j];
        }
    }
    
    imprimirMatriz(linha, coluna, C);
    
    
    return 0;
}