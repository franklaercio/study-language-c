#include <stdio.h>

void lerVetor(int elementos, float vetor[elementos]){
    for(int i = 0; i < elementos; i++){
        float numero;
        scanf("%f", &numero);
        vetor[i] = numero;
    }
}

int main(){
    int elementos;
    
    scanf("%d", &elementos);
    
    if(elementos <= 10){
        float a[elementos];
        float b[elementos];
        
        lerVetor(elementos, a);
        lerVetor(elementos, b);
        
        for(int i = 0; i < elementos; i++){
            float soma = a[i] + b[i];
            printf("%.2f ", soma);
        }
    }else{
        printf("Muitos elementos!");
    }
    
    return 0;
}