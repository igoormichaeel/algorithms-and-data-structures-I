#ifndef _LINKEDLIST_H_
#define _LIKEDLIST_H_

struct no{
    int val;
    struct no *prox;
};

struct linkedlist{
    struct no *cabeca;
    int qtdade;
};

// Declaracao de funcoes

struct linkedlist* inicializar();

struct no* alocarNovoNo(int valor);

void inserirElementoNoFim(struct linkedlist *lista, int valor);

void inserirElementoNoInicio(struct linkedlist *lista, int valor);

void inserirElementoEmPosicao(struct linkedlist *lista, int valor, int posicao);

int obterElementoEmPosicao(struct linkedlist *lista, int posicao);

void removerElementoEmPosicao(struct linkedlist *lista, int posicao);

void imprimirLista(struct linkedlist *lista);

// Fim de declaracao de funcoes

#endif // _LINKEDLIST_H_