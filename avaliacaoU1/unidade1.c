#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include "unidade1.h"

// Início - Arraylist

struct arraylist* inicializarAL(int capacidade) {
    struct arraylist* lista = (struct arraylist*)malloc(sizeof(struct arraylist));

    lista->vetor = (int*)calloc(capacidade, sizeof(int));
    lista->qtdade = 0;
    lista->capacidade = capacidade;

    return lista;
}

void duplicarCapacidade(struct arraylist* lista) {
    lista->vetor = (int*)realloc(lista->vetor, 2 * lista->capacidade * sizeof(int));
    lista->capacidade = 2 * lista->capacidade;
}

void inserirElementoNoFim(struct arraylist* lista, int valor) {
    if (lista->qtdade == lista->capacidade) duplicarCapacidade(lista);
    lista->vetor[lista->qtdade] = valor;
    lista->qtdade++;
}

void inserirElementoEmPosicao(struct arraylist* lista, int valor, int posicao) {
    if (posicao >= 0 && posicao <= lista->qtdade) {
        if (lista->qtdade == lista->capacidade) duplicarCapacidade(lista);

        for (int i = lista->qtdade; i > posicao; i--) {
            // adianta todos os elementos de uma posicao a direita
            lista->vetor[i] = lista->vetor[i - 1];
        }
        lista->vetor[posicao] = valor;
        lista->qtdade++;
    }
}

int obterElementoEmPosicao(struct arraylist* lista, int posicao) {
    if (posicao >= 0 && posicao < lista->qtdade) return lista->vetor[posicao];
}

void inverterArrayList(struct arraylist* lista) {
    int aux;

    for (int i = 0; i < lista->qtdade/2; i++) {
        aux = lista->vetor[i];
        lista->vetor[i] = lista->vetor[lista->qtdade - i - 1];
        lista->vetor[lista->qtdade - i - 1] = aux;
    }
}

void insereOrdenado(struct arraylist* lista, int val) {
    int inicio = 0, fim = lista->qtdade - 1, delta = lista->qtdade, meio, posicao;
    
    while (delta >= 1){
        delta = fim - inicio +  1;
        meio = delta/2 + inicio;

        if (delta == 1 || delta == 2) {
            if (val <= lista->vetor[fim]) posicao = fim;
            else posicao = fim + 1;
            break;
        }
        
        if(val == lista->vetor[meio]) {
            posicao = meio;
            break;
        } else if (val < lista->vetor[meio]) fim = meio - 1;
        else inicio = meio + 1;
    }

    inserirElementoEmPosicao(lista, val, posicao);
}

void imprimirAL(struct arraylist* lista) {
    printf("[");

    for (int i = 0; i < lista->qtdade; i++) {
        printf("%d", lista->vetor[i]);

        if (i < lista->qtdade - 1) printf(", ");
    }

    printf("]\n");
}

// Fim - Arraylist

// Início - DoublyLinkedList

struct doublylinkedlist* inicializarDLL() {
    struct doublylinkedlist* lista = (struct doublylinkedlist*)malloc(sizeof(struct doublylinkedlist));

    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->qtdade = 0;

    return lista;
}

struct no* alocarNovoNo(int valor) {
    struct no* novoNo = (struct no*)malloc(sizeof(struct no));

    novoNo->val = valor;
    novoNo->ant = NULL;
    novoNo->prox = NULL;

    return novoNo;
}

void inserirElementoNoFimDLL(struct doublylinkedlist* lista, int valor) {
    struct no* novoNo = alocarNovoNo(valor);

    if (lista->cabeca == NULL) lista->cabeca = novoNo;
    else {
        novoNo->ant = lista->cauda;
        lista->cauda->prox = novoNo;
    }
    lista->cauda = novoNo;
    lista->qtdade++;
}

int obterElementoEmPosicaoDLL(struct doublylinkedlist* lista, int posicao) {
    struct no* aux = lista->cabeca;

    for (int i = 0; i < posicao && aux->prox != NULL; i++) {
        aux = aux->prox;
    }
    
    return aux->val;
}

void inverterDoublyLinkedList(struct doublylinkedlist* lista) {
    if (lista != NULL && lista->qtdade>0){
        struct no* aux = lista->cauda, *aux2;
        lista->cabeca = aux;
        while (aux->ant != NULL){
            aux2 = aux->ant;
            aux->ant = aux->prox;
            aux->prox = aux2;
            aux = aux->prox;
        }
        aux2 = aux->ant;
        aux->ant = aux->prox;
        aux->prox = aux2;
        lista->cauda = aux;
    }
}

void imprimirDLL(struct doublylinkedlist *lista){
    if (lista != NULL && lista->qtdade>0){
        struct no *aux = lista->cabeca;
        printf("[");
        while(aux != NULL){
            printf("%d", aux->val);
            if(aux->prox != NULL) printf(", ");
            aux = aux->prox;
        }
        printf("]\n");
    } else printf("Lista vazia!\n");
}

// Fim DoublyLinkedList

int main() {
    struct doublylinkedlist *lista = inicializarDLL();

    inserirElementoNoFimDLL(lista, 2);
    inserirElementoNoFimDLL(lista, 4);
    inserirElementoNoFimDLL(lista, 6);
    
    imprimirDLL(lista);

	inverterDoublyLinkedList(lista);
	
    imprimirDLL(lista);

    return 0;
}