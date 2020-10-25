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

int main() {
    int linhaA, colunaA, linhaB, colunaB, multiplicacao = 0;
    
    scanf("%i %i", &linhaA, &colunaA);
    
    int A[linhaA][colunaA];
    lerMatriz(linhaA, colunaA, A);
    
    scanf("%i %i", &linhaB, &colunaB);
    
    int B[linhaB][colunaB];
    lerMatriz(linhaB, colunaB, B);
    
    int C[linhaA][colunaB];
    
    for(int i = 0; i <= linhaA; i++) {
        for(int j = 0; j <= colunaB; j++) {
			for(int k = 0; k < linhaB; k++) {
				multiplicacao +=  A[i][k] * B[k][j];
			}

			C[i][j] = multiplicacao;
			multiplicacao = 0;
        }
        
    }
    
    imprimirMatriz(linhaA, colunaB, C);
    
    return 0;
}