#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

void swap(int *v, int i, int j) {
    int temp = v[i];
    
    v[i] = v[j];
    v[j] = temp;
}

int particiona(int *v, int ini, int fim, bool randomizacao){
    int pivoIndex = ini;

    if (randomizacao){
        srand(time(0));

        int i_pivo = rand() % (fim - ini + 1) + ini;
        
        swap(v, i_pivo, fim);
    }

    int pivo = v[fim];  

    for(int i = ini; i < fim; i++){
        if(v[i] <= pivo){
            swap(v, pivoIndex, i);
            pivoIndex++;
        }
    }

    swap(v, pivoIndex, fim);

    return pivoIndex;
}

void quickSort(int *v, int ini, int fim, bool randomizacao) {
    int tam = fim - ini + 1;
    if (tam>1) {
        int pivoIndex = particiona(v, ini, fim, randomizacao);
        quickSort(v, ini, pivoIndex - 1, randomizacao);
        quickSort(v, pivoIndex + 1, fim, randomizacao);
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

int main() {
    int tamV = 7;
    bool randomizacao = false;
    int *v = (int*)malloc(tamV*sizeof(int));

    v[0] = 4;
    v[1] = 2;
    v[2] = 1;
    v[3] = 5;
    v[4] = 3;
    v[5] = 6;
    v[6] = 7;

    exibirArray(v, tamV);

    quickSort(v, 0, tamV-1, randomizacao);

    exibirArray(v, tamV);

    return 0;
}