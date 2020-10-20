#include <stdio.h>
#include <string.h>

int inverterTexto(char palavra[100], int tamanho, int posicao){
    if (tamanho > posicao){ 
         if (palavra[tamanho - 1] != palavra[posicao]){
            return 0;
        } 

        return inverterTexto(palavra, tamanho-1, posicao+1);
    }else {
        return 1;
    }    
}

void retirarEspacos(char texto[100]){ 
    int count=0;
    for(int i=0; i < strlen(texto); i++){
        if(texto[i]!=' '){
            texto[count++]=texto[i];
        }
    }
    texto[count]=0;
} 

int main(){
    char textoOriginal[100];
    char textoTeste[100];
    
    fgets(textoOriginal, 100, stdin);
    textoOriginal[strcspn(textoOriginal, "\n")] = 0;
  
    strcpy(textoTeste, textoOriginal);
    retirarEspacos(textoTeste);
    
    int isPalindromo, posicao = 0;

    isPalindromo = inverterTexto(textoTeste, strlen(textoTeste) - 1, posicao);
    
    if(isPalindromo == 1){
        printf("O texto %s é palíndromo", textoOriginal);
    }else{
        printf("O texto %s não é palíndromo", textoOriginal);
    }
    
    
}