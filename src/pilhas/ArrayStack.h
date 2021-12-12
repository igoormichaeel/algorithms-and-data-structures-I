#ifndef _ARRAYSTACK_H_
#define _ARRAYSTACK_H_
#include <stdbool.h>

struct arraystack{
    int *elementos;
    int qtdade;
    int tamanho;
};

// Declaracao de funcoes

struct arraystack* inicializar(int tamanho);

void duplicarCapacidade(struct arraystack *pilha);

void empilhar(struct arraystack **pilha, int valor);

void desempilhar(struct arraystack *pilha);

int desempilharRetornando(struct arraystack *pilha);

int topo(struct arraystack *pilha);

bool vazio(struct arraystack *pilha);

void imprimir(struct arraystack *pilha);

// Fim de declaracao de funcoes

#endif // _ARRAYSTACK_H_