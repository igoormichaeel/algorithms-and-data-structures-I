#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <limits.h>
#include "ArrayQueue.h"

// Implementação das funções

struct arrayqueue* inicializar(int tamanho) {
    struct arrayqueue* fila = (struct arrayqueue*)malloc(sizeof(struct arrayqueue));

    fila->elementos = (int*)calloc(tamanho, sizeof(int));
    fila->frente = -1;
    fila->tras = -1;
    fila->qtdade = 0;
    fila->tamanho = tamanho;

    return fila;
}

void enfileirar(struct arrayqueue** fila, int valor) {
    if ((*fila) == NULL) (*fila) = inicializar(10);
    if (((*fila)->tras + 1) % (*fila)->tamanho == (*fila)->frente) return; // fila cheia, não enfileira
    if ((*fila)->frente == -1 && (*fila)->tras == -1) {
        // se a fila estiver vazia, 'frente' também incrementa uma posição
        (*fila)->frente = ((*fila)->frente + 1) % (*fila)->tamanho;
    }
    (*fila)->tras = ((*fila)->tras + 1) % (*fila)->tamanho;
    (*fila)->elementos[(*fila)->tras] = valor;
    (*fila)->qtdade++;
}

int desenfileirar(struct arrayqueue* fila) {
    if (fila != NULL && fila->qtdade > 0) {
        int aux = fila->frente;

        if (fila->frente == fila->tras) fila->frente = fila->tras = -1;
        else fila->frente = (fila->frente + 1) % fila->tamanho;

        fila->qtdade--;

        return fila->elementos[aux];
    }
    else return INT_MIN;
}

int frente(struct arrayqueue* fila) {
    if (fila != NULL && fila->qtdade > 0) return fila->elementos[fila->frente];
    else return INT_MIN;
}

// Fim de implementação das funções