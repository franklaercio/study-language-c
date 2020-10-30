#include <stdio.h>

void imprime_indireto(int **A_indireto, int n) {
    for (int i=0; i<n; i++)
        printf ("%d ", **(A_indireto+i));
}

int main() {
    int tamanho;
    scanf("%i", tamanho);

    int A[tamanho];

    imprime_indireto(&A, tamanho);

    return 0;
}