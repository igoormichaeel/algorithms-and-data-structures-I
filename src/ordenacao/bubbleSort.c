#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

void bubbleSort(int* v, int n) {
    for (int j = 0; j < n-1; j++){
        bool trocou = false;

        for (int i=0; i < n-j-1; i++) {
            if (v[i] > v[i+1]) {
                int temp = v[i];
                v[i] = v[i+1];
                v[i+1] = temp;
                trocou = true;
            }
        }

        if (!trocou) return;
    }
}

void exibirArray(int *v, int tamV) {
    printf("[");

    for (int i = 0; i < tamV; i++) {
        printf("%d", v[i]);

        if (i < tamV - 1) printf(", ");
    }

    printf("]\n");
}

int main(){
    srand(time(0));
    
    int tamanho = 10000;

    int *v = (int*)malloc(tamanho * sizeof(int));

    for (int i = 0; i < tamanho; i++) {
        v[i] = rand() % 10;
    }

    //exibirArray(v, tamanho);

    clock_t begin = clock();

    bubbleSort(v, tamanho);

    clock_t end = clock();

    double tempo = (double)(end - begin)/(CLOCKS_PER_SEC);

    //exibirArray(v, tamanho);

    printf("Tempo total: %lf", tempo);
}