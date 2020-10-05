#include <stdio.h>

float calculaMedia(char tipoMedia, float nota1, float nota2, float nota3){
    float resultado;

    if(tipoMedia == 'A'){
        resultado = ((nota1*4) + (nota2*5) + (nota3*6))/15;
    }else if(tipoMedia == 'N'){
        resultado = ((nota1) + (nota2) + (nota3))/3;
    }

    return resultado;
}

int main(){
    char tipoMedia;
    float nota1;
    float nota2;
    float nota3;

    scanf("%c", &tipoMedia);
    scanf("%f", &nota1);
    scanf("%f", &nota2);
    scanf("%f", &nota3);

    printf("%.2f", calculaMedia(tipoMedia, nota1, nota2, nota3));

    return 0;
}