#include <stdio.h>
#include <math.h>

int main() {
    int i;
    float notas[10];
    float somaNotas, media, desvioPadrao, somatorio;

    for (i = 0; i < 10; i++) {
        float nota;
        scanf("%f", &nota);
        notas[i] = nota;
        somaNotas += nota;
    }

    media = somaNotas / 10;
    for(i = 0; i < 10; i++){
        somatorio = somatorio + pow(notas[i] - media,2);
    }

    desvioPadrao = sqrt(somatorio/(10-1));
    printf("%.2f %.2f", media, desvioPadrao);

    return 0;
}