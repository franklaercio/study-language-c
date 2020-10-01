#include <stdio.h>
#include <string.h>

int main() {
    char frase[256];

    fgets(frase, 256, stdin);

    for (int i = 1; i < strlen(frase); i++){
        char caractere = frase[i];

        if(caractere == ' ') {
            frase[i + 1] = toupper(frase[i + 1]);
        }else{
            frase[i + 1] = tolower(frase[i + 1]);
        }
    }

    printf("%s", frase);
    
    return 0;
}