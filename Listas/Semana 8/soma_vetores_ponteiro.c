#include <stdio.h>

void lerVetor(int elementos, float *vetor){
    for(int i = 0; i < elementos; i++){
        float numero;
        scanf("%f", &numero);
        vetor[i] = numero;
    }
}

void somaVetores(float *a, float *b, float *c, int elementos){
    for(int i = 0; i < elementos; i++){
        c[i] = a[i] + b[i];
    }
}

int main(){
    int elementos;
    
    scanf("%d", &elementos);
    
    if(elementos <= 10){
        float a[elementos];
        float b[elementos];
        float c[elementos];
        
        lerVetor(elementos, a);
        lerVetor(elementos, b);
        somaVetores(a, b, c, elementos);
        
        for(int i = 0; i < elementos; i++){
            printf("%.2f ", c[i]);
        }
    }else{
        printf("Muitos elementos!");
    }
    
    return 0;
}