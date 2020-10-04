#include <stdio.h>
#include <string.h>

int main() {
    char palavra[40] = "";

    int contadorMaiuscula = 0;
    int contadorMinuscula = 0; 

    fgets(palavra, 40, stdin);

    for (int i = 0; i < strlen(palavra); i++){
        if(palavra[i] != ' ' && (toupper(palavra[i]) >= 'A' &&  toupper(palavra[i]) <= 'Z')) {
            if(palavra[i] == toupper(palavra[i])){
                contadorMaiuscula++;
            }

            if (palavra[i] == tolower(palavra[i])) {
                contadorMinuscula++;
            }
        }
    }

    printf("%d %d", contadorMaiuscula, contadorMinuscula);
    

    return 0;
}