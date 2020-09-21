/*
Um fluxograma é uma forma simples de representar condicionais. Nos fluxogramas, um retângulo representa um conjunto de instruções e um losango representa uma decisão em relação a uma pergunta. Para que fique melhor de implementar, usemos as seguintes convençoes:

Além de expressões matemáticas e lógicas, instruções podem ser: 
Leia <tipo> <variavel>, Ex: Leia int A, significa que o programa deve executar uma leitura de uma variável int com o nome A.
Imprima "<texto>", Ex: Imprima "Hello World", significa que o programa deve imprimir o texto "Hello World", sem as aspas.
Imprima "<variavel>", Ex Imprima "Valor de A=<A>", significa que o programa deve imprimir o texto "Valor de A=10", se a variável A tiver valor 10.
Os fluxogramas são muito flexíveis, como não existe uma estrutura definida para usá-los, tentaremos explicar individualmente cada vez que uma nova construção for feita. Por enquanto, usando os esclarecimentos acima, implemente o seguinte fluxograma:

Obs: Neste programa, como estamos usando floats, você vai ter que truncar a quantidade de casas decimais quando for imprimir os valores, use "%.Xf"(exemplo printf("%.5f", a) ) onde X é o numero de casas decimais que você quer imprimir.
*/

#include <stdio.h>

int main () {
    float a;
    float b;

    printf("Entre com os operandos: \n");
    scanf("%f", &a);
    scanf("%f", &b);

    switch (1){
    case 1:
        if (a > 0 && b < 0) {
            printf("Valor de V=%.1f",a*b);
        }
    case 2:
         if(a < 0) {
            printf("Valor de V=%.1f",a+b);
        } 
    default:
        if(a > 0 && b>0) {
          printf("Valor de V=%.1f",a/b);
        }
        break;
    }
    
    return 0;
}