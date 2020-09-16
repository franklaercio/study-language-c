#include <stdio.h>

int main() {
    int quantidadeOperacoes;

    scanf("%i", &quantidadeOperacoes);

    float operacoes[quantidadeOperacoes];
    int resultadoOperacao[quantidadeOperacoes];

    float op1 = 0;
    float op2 = 0;

    for (int i = 0; i < quantidadeOperacoes; i++){
        float op;
        scanf("%f", &op);
        operacoes[i] = op;
    }
    
    for (int j = 0; j <= quantidadeOperacoes; j++) {
        op1 = operacoes[j];
        
        if (op1 > op2) {
            resultadoOperacao[j] = 1;
        }else if(op1 < op2) {
            resultadoOperacao[j] = -1;
        }else{
            resultadoOperacao[j] = 0;
        }

        op2 = operacoes[j];
    }

    int linha1 = 0;
    int linha2 = 0;
    
    int resultado = 0;

    for (int k = 1; k < quantidadeOperacoes; k++) {
      linha1 = resultadoOperacao[k];
      
      if (linha1 != linha2 && k > 1) {
        resultado = 0;
        break;
      } else {
        resultado = linha1;
      }  
      
      linha2 = resultadoOperacao[k];
    }  

    printf("%d", resultado);

    return 0;
}