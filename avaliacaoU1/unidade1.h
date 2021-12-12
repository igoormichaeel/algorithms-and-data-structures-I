#ifndef _UNIDADE1_H_
#define _UNIDADE1_H_

// Início - Arraylist

struct arraylist {
    int* vetor;
    int qtdade;
    int capacidade;
};

struct arraylist* inicializarAL(int capacidade);

void duplicarCapacidade(struct arraylist* lista);

void inserirElementoNoFim(struct arraylist* lista, int valor);

void inserirElementoEmPosicao(struct arraylist* lista, int valor, int posicao);

int obterElementoEmPosicao(struct arraylist* lista, int posicao);

void inverterArrayList(struct arraylist* lista);

void insereOrdenado(struct arraylist* lista, int val);

// Fim - Arraylist

// Início - DoublyLinkedList

struct no {
    struct no* ant;
    int val;
    struct no* prox;
};

struct doublylinkedlist {
    struct no* cabeca;
    struct no* cauda;
    int qtdade;
};

struct doublylinkedlist* inicializarDLL();

struct no* alocarNovoNo(int valor);

void inserirElementoNoFimDLL(struct doublylinkedlist* lista, int valor);

int obterElementoEmPosicaoDLL(struct doublylinkedlist* lista, int posicao);

void inverterDoublyLinkedList(struct doublylinkedlist* lista);

// Fim DoublyLinkedList

#endif // _UNIDADE1_H_