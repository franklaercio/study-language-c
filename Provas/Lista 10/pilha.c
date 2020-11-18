#include <stdio.h>
#include <stdbool.h>
#include <string.h>

typedef struct node  {
  int data;      
} Node; 

typedef struct stack  {
  int size;  
  Node vetor[3];
} Stack; 

bool equals(char * a, char *b) {
  int index = 0;
 
  while(a[index] == b[index]){
    if(a[index] == '\0' || b[index] == '\0' ){
      break;
    }

    ++index;
  }

  if(a[index] == '\0' && b[index] == '\0' ){
    return true;
  }else{
    return false;
  }
}

bool isFullStack(Stack *stack) {
    if((*stack).size == 2) {
        return true;
    }else{
        return false;
    }
}

void imprimir(Stack *stack) {
    printf("pilha: ");
    
    for(int i = 2; i >= 0; i--) {
        if((*stack).vetor[i].data > -1) {
            printf("%i ", (*stack).vetor[i].data);
        }
    }
    printf("\n");
}

Stack push(Node node, Stack *stack) {
    if(!isFullStack(stack)) {
      if((*stack).size == -1) {
        (*stack).size++;
        (*stack).vetor[(*stack).size] = node;
      }else{
        (*stack).size++;
        (*stack).vetor[(*stack).size] = node;
        
        Node nodes[3];
        int contador = 0;

        for(int i = 2; i >= 0; i--) {
            nodes[contador] = (*stack).vetor[i];
            contador++;
        }
        
        int j = 2;
        
        for(int i = 0; i < 3; i++) {
          (*stack).vetor[j] = nodes[i];
          j--;
        }
      }
      
      imprimir(stack);
    
      return (*stack);
    }else{
      printf("pilha cheia. nao eh possivel adicionar mais elementos\n");
    }
}

void pop(Stack *stack) {
    if((*stack).size > -1) {
      (*stack).vetor[2].data = -1;

      imprimir(stack);
    }else{
      printf("pilha vazia, nao eh possivel realizar pop\n");
    }
}

int main() {
    char comando[256];
    int numero;
    
    Stack stack;

    for(int i = 0; i < 3; i++) {
      stack.vetor[i].data = -1;
    }
    
    stack.size = -1;
    
    while(1) {
        fgets(comando, 256, stdin);
        comando[strcspn(comando, "\n")] = 0;
        
        if(comando[0] == 's' && comando[1] == 'a') {
            break;
        }
        
        if(equals(comando, "push")) {
            scanf("%i", &numero);
            Node node = {.data = numero};

            stack = push(node, &stack);
        }
        
        if(equals(comando, "pop")) {
            pop(&stack);
        }
    }
    
    return 0;
}