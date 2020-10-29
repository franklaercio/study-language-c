#include <stdio.h>

void lerMatriz(int tamanho, int (*matriz)[tamanho]){
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

void valorMaximoMinimoMatriz(int tamanho, int (*matriz)[tamanho], int *maximo, int *i_maximo, int *j_maximo,
 int *minimo, int *i_minimo, int *j_minimo){
     *maximo = matriz[0][0];
     *minimo = matriz[0][0];
     *j_maximo = 0;
     *i_maximo = 0;
     *j_minimo = 0;
     *i_minimo = 0;
     
    for(int i = 0; i < tamanho; i++){
        for(int j = 0; j < tamanho; j++){
            if(matriz[i][j] > maximo){
                *maximo = matriz[i][j];
                *i_maximo = i;
                *j_maximo = j;
            }else if(matriz[i][j] < minimo){
                *minimo = matriz[i][j];
                *i_minimo = i;
                *j_minimo = j;
            }
        }
    }            
}

int main() {
    int tamanho, maximo, minimo, i_maximo, j_maximo, i_minimo, j_minimo;

    scanf("%i", &tamanho);

    int matriz[tamanho][tamanho];

    lerMatriz(tamanho, tamanho, matriz);

    valorMaximoMinimoMatriz(tamanho, matriz, maximo, i_maximo, j_maximo, minimo, i_minimo, j_minimo);

    return 0;
}