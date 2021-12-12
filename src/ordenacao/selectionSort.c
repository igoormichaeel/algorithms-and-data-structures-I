#include <stdlib.h>
#include <stdio.h>
#include <limits>

// selectionSort out-of-place
void selectionSortOP(int **v, int tamanho) {
    int* v_ordenado = (int*)malloc(tamanho*sizeof(int));

    for (int j=0; j<tamanho; j++) {
        int iMenor = 0 ;

        for (int i=0; i<tamanho; i++) {
            if ((*v)[i] < (*v)[iMenor]) iMenor = i;
        }

        v_ordenado[j] = (*v)[iMenor];
        (*v)[iMenor] = INT_MAX;
    }

    (*v) = v_ordenado;
}

// selectionSort in-place
void selectionSortIP(int *v, int tamanho) {
    for (int j=0; j<tamanho-1; j++) {
        int iMenor = j;

        for (int i=j+1; i<tamanho; i++) {
            if(v[i] < v[iMenor]) iMenor = i;
        }

        int temp = v[j];
        v[j] = v[iMenor];
        v[iMenor] = temp;
    }
}