#include <stdio.h>

void imprime_indireto (int **A_indireto, int n) {
  for(int i = 0; i < n; i++){
      printf("%i ", *(*A_indireto + i));
  }
}

void imprime_vetor(int A[], int n){
  for(int i = 0; i < n; i++){
      printf("%i ", *(A + i));
  }
}

void bubble_sort(int **vetor, int n) {
    int k, j, aux;

    for (k = n - 1; k > 0; k--) {
        for (j = 0; j < k; j++) {
            if (*(*vetor + j) > *(*vetor + (j + 1))) {
                aux = *(*vetor + j);
                *(*vetor + j) = *(*vetor + (j + 1));
                *(*vetor + (j + 1)) = aux;
            }
        }
    }
}

int main() {
    int tamanho;

    scanf("%i", &tamanho);
    
    int A[tamanho];

    for(int i = 0; i < tamanho; i++){
      scanf("%i", &A[i]);
    }

    int *ponteiro;
    int **A_indireto;
    ponteiro = A;
    A_indireto = &ponteiro;

    bubble_sort(A_indireto, tamanho);

    imprime_indireto(A_indireto, tamanho);
    printf("\n");
    imprime_vetor(A, tamanho);
    
    return 0;
}