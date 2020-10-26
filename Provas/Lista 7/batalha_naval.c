#include <stdio.h>
#include <stdbool.h>

void lerCampoBatalha(int n, int m, int matriz[n][m]){
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            scanf("%d", &matriz[i][j]);
        }
    }
}

int isPossivelVerificar(int testeLinha, int testeColuna, int linha, int coluna){
    if(testeLinha > 3 || testeLinha < 0 || testeColuna > 3 || testeColuna < 0) {
      return 0;
    }else{
      return 1;
    }
}

void verificaTiro(int n, int m, int matriz[n][m], int tiroLinha, int tiroColuna){
    if(matriz[tiroLinha][tiroColuna] > 0){ 
        int tiro = 0;
        if(isPossivelVerificar(tiroLinha, tiroColuna + 1, n, m) == 1){
            tiro += matriz[tiroLinha][tiroColuna + 1];
        }

        if(isPossivelVerificar(tiroLinha, tiroColuna - 1, n, m) == 1){
            tiro += matriz[tiroLinha][tiroColuna - 1];
        }

        if(isPossivelVerificar(tiroLinha - 1, tiroColuna, n, m) == 1){
            tiro += matriz[tiroLinha - 1][tiroColuna]; 
        }
        
        if(isPossivelVerificar(tiroLinha + 1, tiroColuna, n, m) == 1){
            tiro += matriz[tiroLinha + 1][tiroColuna];
        }
        
        if(tiro == 0){
            printf("3\n");
        }else{
            printf("2\n");
        }

        matriz[tiroLinha][tiroColuna] = 0;  
    }else{
        printf("1\n");
    } 
}

int main(){
    int tirosLinha[40];
    int tirosColuna[40];
    int salvaTiroLinha = 0, salvaTiroColuna = 0;
    int linha, coluna;
    scanf("%d %d", &linha, &coluna);

    int campo[linha][coluna];
    lerCampoBatalha(linha, coluna, campo);

    int tiroLinha = 1, tiroColuna = 1, mesmoTiro = 0, tiros = 0;

    while(true){
        mesmoTiro = 0;
        tiros = 0;
        
        scanf("%d %d", &tiroLinha, &tiroColuna);
        
        if(((tiroLinha > 4) || (tiroLinha < 0)) || ((tiroColuna > 4) || (tiroColuna < 0))){
          break;
        }
        
        while(tiros < 40){
            if(tirosLinha[tiros] == tiroLinha && tirosColuna[tiros] == tiroColuna){
                mesmoTiro = 1;
            }
            tiros++;
        }
        
        tirosLinha[salvaTiroLinha] = tiroLinha;
        tirosColuna[salvaTiroColuna] = tiroLinha;
        
        salvaTiroLinha++;
        salvaTiroColuna++;
        
        if(mesmoTiro == 0){
            verificaTiro(linha, coluna, campo, tiroLinha - 1, tiroColuna - 1);
        }else{
            printf("4\n");
        }
    }      
    
    return 0;
}