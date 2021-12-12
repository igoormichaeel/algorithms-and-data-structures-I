#include <stdlib.h>
#include <stdio.h>
#include<math.h>
#include "DoublyLinkedList.h"

// Inicio das implementações das funções

struct doublylinkedlist* inicializar(){
    struct doublylinkedlist *lista = (struct doublylinkedlist*)malloc(sizeof(struct doublylinkedlist));
    
    lista->cabeca = NULL;
    lista->cauda = NULL;
    lista->qtdade = 0;

    return lista;
}

struct no* alocarNovoNo(int valor){
    struct no *novoNo = (struct no*)malloc(sizeof(struct doublylinkedlist));

    novoNo->ant = NULL;
    novoNo->val = valor;
    novoNo->prox = NULL;

    return novoNo;
}

void inserirElementoNoInicio(struct doublylinkedlist *lista, int valor){
    struct no *novoNo = alocarNovoNo(valor);

    if (lista->cabeca == NULL){
        lista->cabeca = novoNo;
        lista->cauda = novoNo;
    } else{
        lista->cabeca->ant = novoNo;
        novoNo->prox = lista->cabeca;
        lista->cabeca = novoNo;
    }
    lista->qtdade++;
}

void inserirElementoNoFim(struct doublylinkedlist *lista, int valor){
    struct no *novoNo = alocarNovoNo(valor);

    if(lista->cabeca == NULL){
        inserirElementoNoInicio(lista, valor);
    } else{
        lista->cauda->prox = novoNo;
        novoNo->ant = lista->cauda;
        lista->cauda = novoNo;
        lista->qtdade++;
    }
}

void inserirElementoEmPosicao(struct doublylinkedlist *lista, int valor, int posicao){
    if(posicao == 0) inserirElementoNoInicio(lista, valor);
    else if(posicao == lista->qtdade) inserirElementoNoFim(lista, valor);
    else if(posicao>0 && posicao<lista->qtdade){
        struct no *novoNo = alocarNovoNo(valor);
        struct no *aux = lista->cabeca;
        int cont = 0;

        while(cont < posicao-1){
            aux = aux->prox;
            cont++;
        }

        novoNo->ant = aux;
        novoNo->prox = aux->prox;
        aux->prox = novoNo;
        lista->qtdade++;
    }
}

int obterElementoEmPosicao(struct doublylinkedlist *lista, int posicao){
    if(posicao>=0 && posicao<lista->qtdade){
        if(posicao == 0) return lista->cabeca->val;
        else if(posicao == lista->qtdade-1) return lista->cauda->val;
        else if(posicao>0 && posicao<lista->qtdade-1){
            if(posicao <= (lista->qtdade/2)){
                // comeca a percorrer a lista pela cabeca
                struct no *aux = lista->cabeca;
                int cont = 0;
                while(cont < posicao){
                    aux = aux->prox;
                    cont++;
                }
                return aux->val;
            }
            else{
                // comeca a percorrer pela cauda
                struct no *aux = lista->cauda;
                int cont = lista->qtdade-1;
                while(cont > posicao){
                    aux = aux->ant;
                    cont--;
                }
                return aux->val;
            }
        }
    }
}

void removerElementoEmPosicao(struct doublylinkedlist *lista, int posicao){
    if(posicao>=0 && posicao<lista->qtdade){
        struct no *aux, *aux2;
        if(lista->cabeca->prox == NULL){
            // caso em que há apenas um elemento na lista
            free(lista->cabeca);
            lista->qtdade--;
            lista->cabeca = NULL;
            lista->cauda = NULL;
        } else if(posicao==0){
            aux = lista->cabeca;
            lista->cabeca = aux->prox;
            lista->cabeca->ant = NULL;
            lista->qtdade--;
            free(aux);
        } else if(posicao == lista->qtdade-1){
            aux = lista->cauda;
            lista->cauda = aux->ant;
            lista->cauda->prox = NULL;
            lista->qtdade--;
            free(aux);
        } else if(posicao>0 && posicao<lista->qtdade-1){
            if(posicao <= (lista->qtdade/2)){
                // comeca a percorrer a lista pela cabeca
                aux = lista->cabeca;
                int cont = 0;
                while(cont < posicao-1){
                    aux = aux->prox;
                    cont++;
                }
                aux2 = aux->prox;
                aux->prox = aux2->prox;
                aux2->prox->ant = aux;
                free(aux2);
            }
            else{
                // comeca a percorrer pela cauda
                aux = lista->cauda;
                int cont = lista->qtdade-1;
                while(cont > posicao+1){
                    aux = aux->ant;
                    cont--;
                }
                aux2 = aux->ant;
                aux->ant = aux2->ant;
                aux2->ant->prox = aux;
                free(aux2);
            }
            lista->qtdade--;
        }
    }
}

void imprimirLista(struct doublylinkedlist *lista){
    if (lista->cabeca != NULL && lista->qtdade>0){
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

// Fim das implementações das funções

int main(){
    struct doublylinkedlist *lista = inicializar();

    int numElementos = 5;
	for (int i = 0; i < numElementos; i++) {
		inserirElementoNoFim(lista, i);
	}
    imprimirLista(lista);
    printf("%d \n", lista->qtdade);
    for (int i = 0; i < numElementos; i++) {
		removerElementoEmPosicao(lista, numElementos - i - 1);
        imprimirLista(lista);
        printf("%d \n", lista->qtdade);
	}
    
    // 5 - 0 - 1 = 4
    // 5 - 1- 1 = 3
    // 5 - 2 - 1 = 2
    // 5 - 3 - 1 = 1
    // 5 - 4 - 1 = 0


    // 0 1 2 3 4

    return 0;

}