#ifndef _DOUBLYLINKEDLIST_H_
#define _DOUBLYLINKEDLIST_H_

struct no{
    struct no *ant;
    int val;
    struct no *prox;
};

struct doublylinkedlist{
    struct no *cabeca;
    struct no *cauda;
    int qtdade;
};

// Início das declarações das funções

struct doublylinkedlist* inicializar();

struct no* alocarNovoNo(int valor);

void inserirElementoNoInicio(struct doublylinkedlist *lista, int valor);

void inserirElementoNoFim(struct doublylinkedlist *lista, int valor);

void inserirElementoEmPosicao(struct doublylinkedlist *lista, int valor, int posicao);

int obterElementoEmPosicao(struct doublylinkedlist *lista, int posicao);

void removerElementoEmPosicao(struct doublylinkedlist *lista, int posicao);

void imprimirLista(struct doublylinkedlist *lista);

// Fim das declarações das funções

#endif // _DOUBLYLINKEDLIST_H_