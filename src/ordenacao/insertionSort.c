#include <stdlib.h>
#include <stdio.h>

// insertionSort in-place

void insertionSortIP(int* v, int tamanho) {
    for (int i=1; i < tamanho; i++) {
        int valor = v[i];
        int j;

        for (j=i; j > 0 && v[j-1 ] > valor; j--) {
            v[j] = v[j-1];
        }
        
        v[j] = valor;
    }
}

void exibirLista(int* vetor, int tamanho) {
    printf("[");

    for (int i = 0; i < tamanho; i++) {
        printf("%d", vetor[i]);

        if (i < tamanho - 1) printf(", ");
    }

    printf("]\n");
}

int main() {
    int tamanho = 6;
    int* v = (int*)malloc(tamanho*sizeof(int));

    v[0] = 2;
    v[1] = 7;
    v[2] = 4;
    v[3] = 1;
    v[4] = 5;
    v[5] = 3;

    exibirLista(v, tamanho);

    insertionSortIP(v, tamanho);

    exibirLista(v, tamanho);

    return 0;
}