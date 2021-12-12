#ifndef _LINKEDSTACK_H_
#define _LINKEDSTACK_H_
#include <stdbool.h>

struct no{
    int val;
    struct no *prox;
};

struct linkedstack{
    struct no *topo;
    int qtdade;
};

// Declaracao de funcoes

struct linkedstack* inicializar();

struct no* alocarNovoNo(int valor);

void empilhar(struct linkedstack** pilha, int valor);

void desempilhar(struct linkedstack* pilha);

int desempilharRetornando(struct linkedstack* pilha);

int topo(struct linkedstack* pilha);

bool vazia(struct linkedstack* pilha);

void exibirLista(struct linkedstack* pilha);

// Fim de declaracao de funcoes

#endif // _LINKEDSTACK_H_