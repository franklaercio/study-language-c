/* 

Escreva um programa em que o usuário entre com dois números, A e B, ambos maiores ou iguais a 0. Após isso o programa deverá imprimir:

A soma dos dois números se ambos forem pares
A mensagem "Não posso somar, pois <A> não é par", onde <A> deve ser substituido pelo valor de A
A mensagem "Não posso somar, pois <B> não é par", onde <B> deve ser substituido pelo valor de B
Caso ambos os números não sejam pares, o programa deve imprimir as duas mensagens.


*/

#include <stdio.h>

int main() {
    int a;
    int b;

    scanf("%d", &a);
    scanf("%d", &b);

    if (a % 2 == 0 && b % 2 == 0) {
        int soma = a+b;
        printf("%d", soma);
    }

    if(a % 2 != 0) {
        printf("%s %d %s","Não posso somar, pois", a ,"não é par \n");
    }
    
    if(b % 2 != 0) {
        printf("%s %d %s","Não posso somar, pois", b, "não é par \n");
    }

    return 0;
}