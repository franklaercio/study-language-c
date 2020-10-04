#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char caracteres[256] = "";
    char parada = '@';

    for (int i = 0; i < 256; i++){
        char caracter;
        scanf("%c", &caracter);

        if(caracter == parada){
           caracteres[i] = '\0';
           break;
        }else{
          if(toupper(caracter) == caracter){
            caracteres[i] = tolower(caracter);
          }else{
            caracteres[i] = toupper(caracter);
          }
        }
    }

    for (int i = 0; i < strlen(caracteres); i++){
        if(caracteres[i] != '\n' && tolower(caracteres[i]) >= 'a' && tolower(caracteres[i]) <= 'z') {
          printf("%c ", caracteres[i]);
        }
    }

    return 0;
}