#include <stdio.h>
#include <stdbool.h>

typedef struct {
    int num;
} Elemento;

typedef struct {
    int tam;
    Elemento vetor[40];
} C_vector;

C_vector insert_at(Elemento elemento, int posicao, C_vector c_vector) {
    if(posicao >= 39) {
      posicao = 39;
      c_vector.vetor[38] = c_vector.vetor[39];
    }

    if (c_vector.vetor[posicao].num >= 0) {
      int deslocamento = posicao;
      int numeroDeslocado, numeroPosterior;
      numeroDeslocado = c_vector.vetor[posicao].num;
      c_vector.vetor[posicao] = elemento;

      for(int i = 0; i < 40; i++) {
        if (i > posicao) {
          numeroPosterior = c_vector.vetor[deslocamento + 1].num;
          c_vector.vetor[deslocamento + 1].num = numeroDeslocado;
          numeroDeslocado = numeroPosterior;
          deslocamento++;
        }
      }
    }else{
      c_vector.vetor[posicao] = elemento;
    }

    c_vector.tam++;

    return c_vector;
}

C_vector remove_from(int posicao, C_vector c_vector) {
    for(int i = 0; i < 40; i++) {
        if(i > posicao) {
          c_vector.vetor[i - 1].num = c_vector.vetor[i].num;
        }

        if(i == 39) {
          c_vector.vetor[39].num = -66;
        }
    }

    c_vector.tam--;

    return c_vector;
}

void exist(Elemento elemento, C_vector c_vector) {
    bool isInsertedNumber = false;
    
    for(int i = 0; i < 40; i++) {
      if(c_vector.vetor[i].num == elemento.num) {
        isInsertedNumber = true;
      }
    }

    printf(isInsertedNumber ? "1\n": "0\n");
}


int main() {
    char operacao;
    int numero;
    int posicao;
    bool isVectorVazio = true;
    C_vector c_vector;

    for(int i = 0; i < 40; i++) {
      Elemento e;
      e.num = -66;
      c_vector.vetor[i] = e;
    }
    
    while(1) {
        scanf("%c", &operacao);
       
        if(operacao == 'i') {
            scanf("%i %i", &numero, &posicao);

            Elemento elemento = {.num = numero};
            c_vector = insert_at(elemento, posicao, c_vector);
        }else if (operacao == 'r') {
            scanf("%i", &posicao);
            c_vector = remove_from(posicao, c_vector);
        }else if (operacao == 'e') {
            scanf("%i", &numero);

            Elemento elemento = {.num = numero};
            exist(elemento, c_vector);
        }else if (operacao == 'x'){
            for(int i = 0; i < 40; i++) {
              if(c_vector.vetor[i].num >= 0) {
                isVectorVazio = false;
                printf("%d ", c_vector.vetor[i].num);
              }
            }

            if(isVectorVazio) {
              printf("vazio");
            }

            break;
        }
    }
    
    return 0;
}