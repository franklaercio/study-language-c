#include <stdio.h>
#include <stdbool.h>

void lerCampoBatalha(int n, int m, int matriz[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

void verificaTiro(int n, int m, int matriz[n][m], int tiroLinha, int tiroColuna){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(matriz[i][j] != 0){
                bool isCampoDireta = i + 1 < 4;
                bool isCampoEsquerda = i - 1 < 4;
                bool isCampoCima = m + j < 2*j;
                bool isCampoBaixo = m + j < 2*j;

                if(matriz[i][j]){
                    printf("3\n");
                }else{
                    printf("2\n");
                }
            }else{
                printf("1\n");
            }
        }
    }
}

int main(){
    int linha, coluna;
    scanf("%d %d", &linha, &coluna);

    int campo[linha][coluna];
    lerCampoBatalha(linha, coluna, campo);

    int tiroLinha = 1, tiroColuna = 1;

    while(tiroLinha != linha || tiroColuna != coluna){
        scanf("%d %d", &tiroLinha, &tiroColuna);
        verificaTiro(linha, coluna, campo, tiroLinha, tiroColuna);
    }      
    
    return 0;
}