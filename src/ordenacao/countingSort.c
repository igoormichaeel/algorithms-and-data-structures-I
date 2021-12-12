#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void exibirArray(int *v, int tamV) {
    printf("[");

    for (int i = 0; i < tamV; i++) {
        printf("%d", v[i]);

        if (i < tamV - 1) printf(", ");
    }

    printf("]\n");
}

void countingSort(int *v, int tamanho){
    int iMenor = 0, iMaior = 0;

    for(int i = 0; i < tamanho; i++){
        if(v[i] < v[iMenor]) iMenor = i;
        if(v[i] > v[iMaior]) iMaior = i;
    }

    int vMenor = v[iMenor], vMaior = v[iMaior];
    int tamanho_c = vMaior - vMenor + 1;
    int* c = (int*)calloc(tamanho_c, sizeof(int));

    for(int i = 0; i < tamanho; i++){
        c[v[i] - vMenor]++;
    }

    int index_v = 0;

    for(int i=0; i < tamanho_c; i++){
        int j = c[i];
        while(j > 0){
            v[index_v] = i + vMenor;
            index_v++;
            j--;
        }
    }
}

int main (){
    int tamanho = 11;
    int* v = (int*)malloc(tamanho*sizeof(int));

    srand(time(0));

    for(int i =0; i < tamanho; i++) v[i] = rand()%10;

    exibirArray(v, tamanho);
    countingSort(v, tamanho);
    exibirArray(v, tamanho);

    return 0;
}