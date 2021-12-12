#include <stdio.h>
#include <stdlib.h>

void merge(int *v, int tamV, int *e, int tamE, int *d, int tamD){
    int indexV = 0, indexE = 0, indexD = 0;
    while(indexE < tamE && indexD < tamD){
        if(e[indexE] <= d[indexD]) {
            v[indexV] = e[indexE];
            indexE++;
        } else {
            v[indexV] = d[indexD];
            indexD++;
        }
        indexV++;
    }
    while(indexE < tamE){
        v[indexV] = e[indexE];
        indexE++;
        indexV++;
    }
    while(indexD < tamD){
        v[indexV] = d[indexD];
        indexD++;
        indexV++;
    }
}

void mergeSort(int *v, int tamV){
    if(tamV > 1) {
        int meio = tamV/2, tamE = meio, tamD = tamV - meio;
        int *e = (int*)malloc(tamE*sizeof(int));
        int *d = (int*)malloc(tamD*sizeof(int));
        
        for(int i = 0; i < meio; i++){
            e[i] = v[i];
        }
        for(int i = meio; i < tamV; i++) {
            d[i-meio] = v[i];
        }
        
        mergeSort(e, tamE);
        mergeSort(d, tamD);
        merge(v, tamV, e, tamE, d, tamD);
        free(e);
        free(d);
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
    int tamV = 6;
    int *v = (int*)malloc(tamV*sizeof(int));

    v[0] = 4;
    v[1] = 2;
    v[2] = 1;
    v[3] = 5;
    v[4] = 3;
    v[5] = 6;

    exibirArray(v, tamV);

    mergeSort(v, tamV);

    exibirArray(v, tamV);
}