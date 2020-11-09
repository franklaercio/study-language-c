#include <stdio.h>

enum operacoes {INSERIR = 'i', REMOVER = 'r', EXIST = 'e', SAIR = 'x'};
enum alias {ULTIMA_POSICAO = 39, PENULTIMA_POSICAO = 38, NUMERO_INEXISTENTE = -2147483647};

typedef struct {
    int num;
} Elemento;

typedef struct {
    int tam;
    Elemento vetor[40];
} C_vector;

C_vector insert_at(Elemento elemento, int posicao, C_vector c_vector);

C_vector remove_from(int posicao, C_vector c_vector);

void exist(Elemento elemento, C_vector c_vector);

void imprimirVetor(C_vector c_vector);

int main() {
    char op;
    int numero;
    int posicao;
    C_vector c_vector;

    for(int i = 0; i < 40; i++) {
      Elemento e;
      e.num = NUMERO_INEXISTENTE;
      c_vector.vetor[i] = e;
    }
    
    while(op != SAIR) {  
      scanf("%c", &op);

      switch(op){
        case INSERIR:
          scanf("%i %i", &numero, &posicao);
          Elemento elementoInserido = {.num = numero};
          c_vector = insert_at(elementoInserido, posicao, c_vector);
          break;
        case REMOVER:
          scanf("%i", &posicao);
          c_vector = remove_from(posicao, c_vector);
          break;
        case EXIST:
          scanf("%i", &numero);
          Elemento elementoExiste = {.num = numero};
          exist(elementoExiste, c_vector);
          break;
        case SAIR:
          imprimirVetor(c_vector);
          break;
        default:
          break;
      }
    }
    
    return 0;
}

C_vector insert_at(Elemento elemento, int posicao, C_vector c_vector) {
    if(posicao >= ULTIMA_POSICAO) {
      posicao = ULTIMA_POSICAO;
      c_vector.vetor[PENULTIMA_POSICAO] = c_vector.vetor[ULTIMA_POSICAO];
    }

    if (c_vector.vetor[posicao].num != NUMERO_INEXISTENTE) {
      int index = posicao;
      int valorDeslocado;
      int valorPosterior;

      valorDeslocado = c_vector.vetor[posicao].num;
      c_vector.vetor[posicao] = elemento;

      for(int i = 0; i <= ULTIMA_POSICAO; i++) {
        if (i > posicao) {
          valorPosterior = c_vector.vetor[index + 1].num;
          c_vector.vetor[index + 1].num = valorDeslocado;
          valorDeslocado = valorPosterior;
          index++;
        }
      }
    }else{
      c_vector.vetor[posicao] = elemento;
    }

    c_vector.tam++;

    return c_vector;
}

C_vector remove_from(int posicao, C_vector c_vector) {
    for(int i = 0; i <= ULTIMA_POSICAO; i++) {
        if(i > posicao) {
          c_vector.vetor[i - 1].num = c_vector.vetor[i].num;
        }

        if(i == ULTIMA_POSICAO) {
          c_vector.vetor[ULTIMA_POSICAO].num = NUMERO_INEXISTENTE;
        }
    }

    c_vector.tam--;

    return c_vector;
}

void exist(Elemento elemento, C_vector c_vector) {
    int exiteNumero = 0;
    
    for(int i = 0; i <= ULTIMA_POSICAO; i++) {
      if(c_vector.vetor[i].num == elemento.num) {
        exiteNumero = 1;
        break;
      }
    }

    if(exiteNumero == 1) {
      printf("1\n");
    }else{
      printf("0\n");
    }
}

void imprimirVetor(C_vector c_vector) {
  int vetorVazio = 0;

  for(int i = 0; i <= ULTIMA_POSICAO; i++) {
    if(c_vector.vetor[i].num != NUMERO_INEXISTENTE) {
      vetorVazio = 1;
      printf("%d ", c_vector.vetor[i].num);
    }
  }

  if(vetorVazio == 0) {
    printf("vazio");
  }  
}