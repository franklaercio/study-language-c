#include <stdio.h>

void lerMatriz(int linha, int coluna, int matriz[linha][coluna]) {
    for(int i = 0; i < linha; i++) {
        for(int j = 0; j < coluna; j++) {
            scanf("%d", &matriz[i][j]);
        }
        
    }
}

int main(){
    int matriz[15][15];
    int direcao[4][2]={{1,0}, {0,1}, {1,1}, {1,-1}};
    int peca = 0, resultado = 0, pecasSeguidas = 0, linha = 0, coluna = 0;
    
    lerMatriz(15, 15, matriz);
    
    for(int dir = 0; dir < 4; dir++){
        for(int i = 0; i < 15; i++){
            for(int j = 0; j < 15; j++){
                peca = 0;
                pecasSeguidas = 0;
                
                if(matriz[i][j] != 0){
                    peca = matriz[i][j];
                    linha = i, coluna = j;
                    
                	while(peca == matriz[linha][coluna]){
                	    linha += direcao[dir][0];
    	                coluna += direcao[dir][1];
                	    pecasSeguidas++;
                    }
                    
                    if(pecasSeguidas == 5){
            	        resultado = peca;
            	    }
                }
            }
            
        }
    }
    
    printf("%d", resultado);
    
    return 0;
}