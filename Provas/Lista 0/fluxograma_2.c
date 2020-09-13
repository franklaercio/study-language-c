#include <stdio.h>

int main() {
    int a;
    int b;

    char op;
    char op2;

    printf("Entre com os operandos:\n");
    scanf("%d", &a);
    scanf("%d", &b);

    fflush(stdin);

    printf("Escolha o tipo de operação('a' ou 'l'):\n");
    scanf("\n%c", &op);

    fflush(stdin);
  
    if (op == 'a') {
      printf("Escolha a operação Aritmética(d, m, a):\n");
      scanf("\n%c", &op2);

      if (op2 == 'd') {
        int result = a/b;   
        printf("%i / %i=%i", a, b, result);   
      }else if (op2 == 'm') {
        int result = a*b;   
        printf("%i * %i=%i", a, b, result);
      }else if (op2 == 'a') {
        int result = a+b;  
        printf("%i + %i=%i", a, b, result); 
      }else {
        printf("op Inválida");
      }
    }else if (op == 'l') {
      printf("Escolha a operação Lógica(a, x, o):\n");
      scanf("\n%c", &op2);

      if (op2 == 'a') {
        int result = a&&b; 
        printf("%i and %i=%i", a, b, result);   
      }else if (op2 == 'x') {  
        int result = (!a&&b)||(!b&&a); 
        printf("%i xor %i=%i", a, b, result);
      }else if (op2 == 'o') {
        int result = a||b; 
        printf("%i or %i=%i", a, b, result);   
      }else {
        printf("op inválida");
      }  
    }else {
      printf("Operação Inválida");
    }
}