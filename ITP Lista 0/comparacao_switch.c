/* 
Usando a construçao switch ... case, escreva um programa que receba dois caracteres, A e B, do usuário e imprima as seguintes coisas:

Caso os dois caracteres forem iguais, o programa deve imprimir "Caracteres <A> e <B> iguais", onde <A> e <B> deve ser o valor de cada caractere.
Caso os dois caracteres sejam diferentes:
Se o primeiro caractere antecede o segundo na tabela ASCII, o programa deve imprimir: "Caractere <A> antecede <B>", onde <A> e <B> deve ser o valor de cada caractere.​
Se o segundo caractere antecede o primeiro na tabela ASCII, o programa deve imprimir: "Caractere <B> antecede <A>", onde <A> e <B> deve ser o valor de cada caractere.
Sugestão: Na linguagem C cases só aceitam constantes, para esse caso use ifs dentro ou antes dos case para limitar as escolhas possíveis.

*/

#include <stdio.h>

int main() {
    char a;
    char b;

    scanf("%c %c", &a, &b);

    switch (1) {
    case 1:
        if (a == b) {
            printf("%s %c %s %c %s","Caracteres", a, "e", b, "iguais");
        }
    default:
        if (a < b) {
            printf("%s %c %s %c","Caractere", a, "antecede", b);
        }

        if (b < a) {
            printf("%s %c %s %c","Caractere", b, "antecede", a);
        }

        break;
    }

    return 0;
}