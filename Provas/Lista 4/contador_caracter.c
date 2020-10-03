#include <stdio.h>
#include <string.h>

int main() {
    char caracter[40] = "";
    char texto[40] = "";

    int quantidadeRepeticoes = 0;
    int quantidadeAcertos = 0;
    int posicaoTexto = 0;

    fgets(caracter, 40,stdin);
    fgets(texto, 40,stdin);

    for (int i = 0; i < strlen(texto); i++) {
        quantidadeAcertos = 0;
        if(toupper(texto[i]) == toupper(caracter[0])) {
            quantidadeAcertos++;
            posicaoTexto = i + 1;
            
            for (int j = 1; j < (strlen(caracter) - 1); j++){
                if (toupper(caracter[j]) == toupper(texto[posicaoTexto])){
                    quantidadeAcertos++;
                    posicaoTexto++;
                }
            }   
            
            if (quantidadeAcertos == (strlen(caracter) - 1)){
                quantidadeRepeticoes++;
            }
        }
    }

    printf("%d", quantidadeRepeticoes);

    return 0;
}