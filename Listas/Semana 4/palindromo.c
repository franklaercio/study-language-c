#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char palavra[40] = "";
    char inversa[40] = "";

    int verificaPalindromo;

    fgets(palavra, 40, stdin);

    for (int i = strlen(palavra); i >= 0; i--){
        inversa[strlen(palavra) - i] = palavra[i];
    }

    verificaPalindromo = strcmp(palavra, inversa);
    
    if (verificaPalindromo == 0) {
        printf("%s é um palíndromo", palavra);
    }else{
        printf("%s não é um palíndromo", palavra);
    }

    return 0;
}