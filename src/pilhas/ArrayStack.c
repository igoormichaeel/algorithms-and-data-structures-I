#include "ArrayStack.h"
#include <stdio.h>
#include <stdlib.h>
#include <limits.h>

// Implementação das funções

struct arraystack* inicializar(int tamanho) {
    struct arraystack* pilha = (struct arraystack*)malloc(sizeof(struct arraystack));

    pilha->elementos = (int*)calloc(tamanho, sizeof(int));
    pilha->qtdade = 0;
    pilha->tamanho = tamanho;

    return pilha;
}

void duplicarCapacidade(struct arraystack* pilha) {
    pilha->elementos = (int*)realloc(pilha->elementos, 2 * pilha->tamanho * sizeof(int));
    pilha->tamanho *= 2;
}

void empilhar(struct arraystack** pilha, int valor) {
    if (*pilha == NULL) *pilha = inicializar(10);
    else if ((*pilha)->qtdade == (*pilha)->tamanho) duplicarCapacidade(*pilha);

    (*pilha)->elementos[(*pilha)->qtdade] = valor;
    (*pilha)->qtdade++;
}

void desempilhar(struct arraystack* pilha) {
    if (pilha != NULL && pilha->qtdade>0) pilha->qtdade--;
}

int desempilharRetornando(struct arraystack* pilha) {
    if ((pilha != NULL) && (pilha->qtdade > 0)) {
        pilha->qtdade--;
        return pilha->elementos[pilha->qtdade];
    }
    else return INT_MIN;
}

int topo(struct arraystack* pilha) {
    if ((pilha != NULL) && (pilha->qtdade > 0)) return pilha->elementos[pilha->qtdade - 1];
    else return INT_MIN;
}

bool vazio(struct arraystack* pilha) {
    return ((pilha == NULL) || (pilha->qtdade == 0));
}

void imprimir(struct arraystack* pilha) {
    printf("-\n");

    if (vazio(pilha)) printf("Pilha vazia!\n");
    else {
        for (int i = pilha->qtdade - 1; i >= 0; i--) {
            printf("%d\n", pilha->elementos[i]);
        }
    }

    printf("-\n");
}

// Fim da implementação das funções

int main(){
    struct arraystack *pilha;

    pilha = inicializar(10);

    empilhar(&pilha, 123456);
    imprimir(pilha);
    printf("%d \n", pilha->qtdade);
    printf("%d \n", topo(pilha));

    return 0;
}