#include "LinkedStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Implementação das funções

struct linkedstack* inicializar(){
    struct linkedstack *pilha = (struct linkedstack*)malloc(sizeof(struct linkedstack));

    pilha->topo = NULL;
    pilha->qtdade = 0;

    return pilha;
}

struct no* alocarNovoNo(int valor){
    struct no *novoNo = (struct no*)malloc(sizeof(struct no));

    novoNo->val = valor;
    novoNo->prox = NULL;

    return novoNo;
}

void empilhar(struct linkedstack** pilha, int valor){
    struct no *novoNo = alocarNovoNo(valor);

    if(*pilha == NULL){
        (*pilha) = inicializar();
        (*pilha)->topo = novoNo;
    } else if((*pilha)->topo == NULL){
        (*pilha)->topo = novoNo;
    } else{
        struct no *aux = (*pilha)->topo;
        novoNo->prox = aux;
        (*pilha)->topo = novoNo;
    }
    (*pilha)->qtdade++;
}

void desempilhar(struct linkedstack* pilha){
    if(pilha != NULL && pilha->qtdade>0){
        struct no *aux = pilha->topo;

        pilha->topo = aux->prox;
        pilha->qtdade--;

        free(aux);
    }
}

int desempilharRetornando(struct linkedstack* pilha){
    if(pilha != NULL && pilha->qtdade>0){
        struct no *aux = pilha->topo;
        int valor = aux->val;

        pilha->topo = aux->prox;
        pilha->qtdade--;

        free(aux);

        return valor;
    } else return INT_MIN;
}

int topo(struct linkedstack* pilha){
    if(pilha != NULL && pilha->qtdade > 0) return pilha->topo->val;
    else return INT_MIN;
}

bool vazia(struct linkedstack* pilha){
    if(pilha == NULL || pilha->qtdade==0) return true;
    else return false;
}

void exibirLista(struct linkedstack* pilha){
    printf("-\n");
    
    if (vazia(pilha)) printf("Lista vazia!\n");
    else{
        struct no *aux = pilha->topo;

        do{
            printf("%d\n", aux->val);
            aux = aux->prox;
        } while(aux != NULL);
    }
    
    printf("-\n");
}

// Fim da implementação das funções

int main(){
    struct linkedstack *pilha = NULL;
    pilha = inicializar(2);

    exibirLista(pilha);
    
    empilhar(pilha, 5);
    empilhar(pilha, 9);
    empilhar(pilha, 25);

    exibirLista(pilha);

    printf("topo: %d\n", topo(pilha));

    desempilhar(pilha);
    desempilhar(pilha);

    exibirLista(pilha);

    if(vazia(pilha)) printf("Pilha vazia!\n");
    else printf("Pilha não vazia!\n");

    printf("tamanho: %d\n", tamanho(pilha));
    printf("topo: %d\n", topo(pilha));

    desempilhar(pilha);

    exibirLista(pilha);

    return 0;
}