#ifndef _ARRAYQUEUE_H_
#define _ARRAYQUEUE_H_

// Declaração das funções

struct arrayqueue {
    int frente;
    int tras;
    int *elementos;
    int tamanho;
    int qtdade;
};

struct arrayqueue* inicializar(int tamanho);

void enfileirar(struct arrayqueue** fila, int valor);

int desenfileirar(struct arrayqueue* fila);

int frente(struct arrayqueue* fila);

// Fim da declaração das funções

#endif