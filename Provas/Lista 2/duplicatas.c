#include <stdio.h>

int main() {
    int quantidadeNumeros, numero, naoMesmoNumero;
    int qtd = 0;
    
    scanf("%i", &quantidadeNumeros);
    
    int numeros[quantidadeNumeros];
    int resultado[quantidadeNumeros];
    
    //Ler os numeros
    for (int i =0; i < quantidadeNumeros; i++) {
        scanf("%i", &numero);
        numeros[i] = numero;
    }
    
    //Calcula a quantidade de repetidos
    for (int i = 0; i < quantidadeNumeros; i++)  {
        int valor = numeros[i];
        naoMesmoNumero = 0;
        
        //Pega o número e compara com os existentes
        for (int j = 0; j < quantidadeNumeros; j++)  {
            //Caso o número seja igual a um das sequencias é somado
            if (valor == numeros[j]) {
              naoMesmoNumero++;
            }
            
            //Caso esse número se repita mais de uma vez
            if (naoMesmoNumero > 1) {
                //Caso não tenha sido adicionado nenhum número ele é contabilizado e adicionado no array que agrupo os números contabilizados
                if (valor == numeros[j] && qtd < 1) {
                  qtd++;
                  resultado[qtd] = valor;
                  break;
                }else{
                    for (int k = 0; k < qtd; k++) {
                        //Caso o número não tenha sido contabilizado ainda ele é adicionado na sequência numérica
                        if (valor == numeros[j] && valor != resultado[qtd]) {
                            qtd++;
                            resultado[qtd] = valor;
                            break;
                        }
                    }
                }
            }
        }  
    }
    
    printf("%i", qtd);
    

    return 0;
}