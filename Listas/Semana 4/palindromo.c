#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main() {
    char palavra[40] = "";

    fgets(palavra, 40, stdin);

    int verificaPalindromo = 0;
    int countContrario = strlen(palavra) - 2;

    for (int i = 0; i < strlen(palavra); i++){
        //printf("%c\n 1", palavra[countContrario]);
        printf("%c\n 2", palavra[i]);
        // if (palavra[i] != palavra[countContrario]) {
        //     verificaPalindromo = 1;
        //     break;
        // }else{
        //     countContrario--;
        // }
        //countContrario--;
    }
    
    // if (verificaPalindromo == 0) {
    //     printf("%s é um palíndromo", palavra);
    // }else{
    //     printf("%s não é um palíndromo", palavra);
    // }

    return 0;
}