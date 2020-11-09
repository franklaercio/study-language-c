#include <stdio.h>

typedef struct {
    int parteInteira;
    int base;
} PontoFixo;

PontoFixo convert(PontoFixo pontoFixo, int baseOperacao) {
    int baseAtual = pontoFixo.base;
    while(1) {
        if(baseAtual > baseOperacao) {
            pontoFixo.parteInteira /= 10;
            baseAtual -= 1;
        }
        
        if(baseAtual < baseOperacao) {
            pontoFixo.parteInteira *= 10;
            baseAtual += 1;
        }
        
        if(baseAtual == baseOperacao) {
            break;
        }
    }
    
    pontoFixo.base = baseOperacao;
    
    return pontoFixo;
}

PontoFixo add(PontoFixo a, PontoFixo b, PontoFixo c) {
    c.parteInteira = a.parteInteira + b.parteInteira;
    c.base = a.base;
    
    return c;
}

int main() {
    PontoFixo a;
    PontoFixo b;
    PontoFixo c;
    int baseOperacao;
    
    scanf("%i %i", &a.parteInteira, &a.base);
    scanf("%i %i", &b.parteInteira, &b.base);
    scanf("%i", &baseOperacao);
    
    PontoFixo a_print = a;
    PontoFixo b_print = b;
    
    if (baseOperacao != a.base) {
        a = convert(a, baseOperacao);
    }
    
    if (baseOperacao != b.base) {
        b = convert(b, baseOperacao);
    }
    
    c = add(a, b, c);

    printf("fixo(%i,%i) + fixo(%i,%i) = fixo(%i,%i)", a_print.parteInteira, a_print.base, b_print.parteInteira, b_print.base, c.parteInteira, c.base);
    
    return 0;
}