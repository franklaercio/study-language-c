#include <stdio.h>
#include <string.h>
#include <stdbool.h>

int main() {
    char primeiroTexto[40] = "";
    char segundoTexto[40] = "";
    char stringConcatenada[80] = "";

    fgets(primeiroTexto, 40, stdin);
    fgets(segundoTexto, 40, stdin);

    int contadorPrimeiroCaracter = 0;
    int contadorSegundoCaracter = 1;

    for (int i = 0; i < strlen(primeiroTexto); i++){
        char caracterTexto1 = primeiroTexto[i];
        char caracterTexto2 = segundoTexto[i];

        if(caracterTexto1 != '\0' && caracterTexto2 != '\0' && caracterTexto1 != '\n'){
            stringConcatenada[contadorPrimeiroCaracter] = primeiroTexto[i];
            stringConcatenada[contadorSegundoCaracter] = segundoTexto[i];
            contadorPrimeiroCaracter += 2;
            contadorSegundoCaracter += 2;
        }else{
            stringConcatenada[contadorSegundoCaracter - 1] = segundoTexto[i];
            printf("%s %c\n", "aqui", caracterTexto2);
        }

        printf("%d\n", contadorSegundoCaracter);
    }

    printf("%s", stringConcatenada);

    return 0;
}
