#include <stdio.h>
#include <string.h>

char ordenaCaracteres(char charOrdernado[40]) {
    int i, k;
    char charAux;

    for (i = strlen(charOrdernado) - 1; i > 0; i--){
        for (k = 0; k < i; k++){
            if(charOrdernado[k] > charOrdernado[k + 1]) {
                charAux = charOrdernado[k];
                charOrdernado[k] = charOrdernado[k+1];
                charOrdernado[k+1] = charAux;                     
            }
        }
    }
    
    return charOrdernado[40];
}

int main() {
    char vogais[] = {'a', 'e', 'i', 'o', 'u'};
    char caracteres[40] = "";
    
    char charAux;
    char vogaisOrdenadas[20] = "";
    char consoantesOrdenadas[20] = "";

    int contadorVogais = 0;
    int contadorConsoantes = 0;

    fgets(caracteres, 40, stdin);

    //fflush(stdin);

    for (int i = 0; i < strlen(caracteres); i++){
        char caracter = caracteres[i];
        
        if (caracter == 'a' || caracter == 'e' || caracter == 'i' || caracter == 'o' || caracter == 'u') {
          vogaisOrdenadas[contadorVogais] = caracter;
          contadorVogais++;
        }else if(caracter != ' ' && caracter != '\0' && caracter != '\n' ){
          consoantesOrdenadas[contadorConsoantes] = caracter;
          contadorConsoantes++;
        } 
    }

    ordenaCaracteres(vogaisOrdenadas);
    ordenaCaracteres(consoantesOrdenadas);

    fputs(strcat(vogaisOrdenadas, consoantesOrdenadas), stdout); 

    return 0;
}
