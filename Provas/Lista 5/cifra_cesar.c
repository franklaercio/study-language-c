#include <stdio.h>
#include <string.h>

void imprimeCifra(char palavra[50]){
  for(int i = 0; i < strlen(palavra); i++){
    if(palavra[i] != '\n' && palavra[i] != ' '){
      printf("%c", palavra[i]);
    }
  }

  printf("\n");
}


void verificaPosicaoAlfabeto(char palavra[50], char alfabeto[26], int cifra){
  for(int i = 0; i < strlen(palavra); i++){
    for(int j = 0; j < 26; j++){
        if(palavra[i] == alfabeto[j]){
          if(j - cifra < 0){
            palavra[i] = alfabeto[26 - cifra + j];
            break;
          }else{
            palavra[i] = alfabeto[j - cifra];
            break;
          }  
      }
    }
  }
  
  imprimeCifra(palavra);
}

void decodificaCifra(int quantidadeTestes){
  char alfabeto[26] = { 'A', 'B', 'C', 'D', 'E', 'F', 'G', 'H', 'I', 'J', 'K', 'L', 'M', 'N', 'O', 'P', 'Q', 'R', 'S', 'T', 'U', 'V', 'W', 'X', 'Y', 'Z' };

  for(int i = 0; i < quantidadeTestes; i++){
    char palavra[50];
    fgetc(stdin);
    fgets(palavra, 50, stdin);
    palavra[strcspn(palavra, "\n")] = 0;

    int cifra;
    scanf("%d", &cifra);

    verificaPosicaoAlfabeto(palavra, alfabeto, cifra);
  }
}


int main(){
    int quantidadeTestes;
    scanf("%d", &quantidadeTestes);

    decodificaCifra(quantidadeTestes);
    
    return 0;
}