#include <stdio.h>
#include <string.h>

typedef struct string_t {
 char val[101];
}string;

void preencherResultado(string *result, string *srt, int pos, int tamanho, int str_tam){
    for(int i = pos; i < tamanho; i++){
      (*result).val[i] = (*srt).val[str_tam];
      str_tam++;
    }
}

void insereStrEm(string *result, string *srt1, int pos, string *str2){
    int primeiro_lanco = strlen((*srt1).val);
    int segundo_lanco = strlen((*str2).val);
    int str1_tam = 0;
    int str2_tam = 0;

    if(pos > 0) {
      for(int i = 0; i < primeiro_lanco; i++){
        (*result).val[i] = (*srt1).val[str1_tam];
        str1_tam++;
      }

      for(int i = pos; i < str1_tam + segundo_lanco; i++){
        (*result).val[i] = (*str2).val[str2_tam];
        str2_tam++;
      }
    }else{
      for(int i = pos; i < segundo_lanco; i++){
        (*result).val[i] = (*str2).val[str2_tam];
        str2_tam++;
      }
      
      for(int i = str2_tam; i < str2_tam + primeiro_lanco; i++){
        (*result).val[i] = (*srt1).val[str1_tam];
        str1_tam++;
      }
      
      (*result).val[str2_tam + primeiro_lanco] = '\0';
    } 
}

int main() {
  int posicao;
  string srt1;
  string srt2;
  string result;

  fgets(srt1.val, 256, stdin);
  srt1.val[strcspn(srt1.val, "\n")] = 0;
  fgets(srt2.val, 256, stdin);
  srt2.val[strcspn(srt2.val, "\n")] = 0;
  scanf("%i", &posicao);

  insereStrEm(&(result), &(srt1), posicao, &(srt2));
  
  printf("%s", result.val);

  return 0;
}
