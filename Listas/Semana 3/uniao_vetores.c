#include <stdio.h>

void lerVetor(int tamanho, int vetor[tamanho]){
    for(int i = 0; i < tamanho; i++){
        int numero;
        scanf("%d", &numero);
        vetor[i] = numero;
    }
}

void bubble_sort(int vetor[], int n) {
    int k, j, aux;
    
    for (k = n - 1; k > 0; k--) {
        for (j = 0; j < k; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux          = vetor[j];
                vetor[j]     = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

int main(){
    int tam_a;
    int tam_b;
    
    scanf("%d", &tam_a);
    scanf("%d", &tam_b);
    
    int a[tam_a];
    int b[tam_b];
    int c[tam_a + tam_b];
        
    lerVetor(tam_a, a);
    lerVetor(tam_b, b);
    
    int posicaoA = 0;
    int posicaoB = 0;
    
    for(int i = 0; i < tam_a + tam_b; i++){
        if(i < tam_a){
            c[i] = a[posicaoA];
            posicaoA++;
        }else{
            c[i] = b[posicaoB];
            posicaoB++;
        }
    }
    
    bubble_sort(c, tam_a + tam_b);
    
    for(int i = 0; i < tam_a + tam_b; i++){
        printf("%d ", c[i]);       
    }    
    
    return 0;
}