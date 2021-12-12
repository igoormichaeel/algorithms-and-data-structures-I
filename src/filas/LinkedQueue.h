#ifndef _LINKEDQUEUE_H_
#define _LINKEDQUEUE_H_

struct no{
    int val;
    struct no* prox;
};

struct linkedqueue{
    struct no* frente;
    struct no* tras;
    int qtdade;
};

// Declaração das funções

struct no* alocarNovoNo(int valor);

struct linkedqueue* inicializar();

bool vazia(struct linkedqueue* fila);

void enfileirar(struct linkedqueue** fila, int valor);

int desenfileirar(struct linkedqueue* fila);

int frente(struct linkedqueue* fila);

// Fim da declaração das funções

#endif // _LINKEDQUEUE_H_