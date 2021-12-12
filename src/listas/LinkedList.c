#include <stdlib.h>
#include <stdio.h>
#include "LinkedList.h"

// Implementacao de funcoes

struct linkedlist* inicializar(){
    struct linkedlist *lista = (struct linkedlist*)malloc(sizeof(struct linkedlist));

    lista->cabeca = NULL;
    lista->qtdade = 0;

    return lista;
}

struct no* alocarNovoNo(int valor){
    struct no *novoNo = (struct no*)malloc(sizeof(struct no));

    novoNo->val = valor;
    novoNo->prox = NULL;

    return novoNo;
}

void inserirElementoNoFim(struct linkedlist *lista, int valor){
    //primeiro aloca-se um novo no
    struct no *novoNo = alocarNovoNo(valor);

    // em seguida verifica-se se a lista esta vazia
    if(lista->cabeca == NULL){
        // se estiver vazia, cabeca deve apontar para o novoNo
        lista->cabeca = novoNo;
    } else{
        // caso nao esteja vazia, deve-se percorrer toda a lista ate encontrar o ultimo no
        // para isso, cria-se uma variavel auxiliar que aponta para cabeca (endereco de memoria do primeiro no)
        struct no *aux = lista->cabeca;
        // permanece-se no while enquanto o proximo no for diferente de NULL
        // quando o proximo for NULL, significa que aux esta apontando para o ultimo no
        while(aux->prox != NULL){
            // aux agora aponta para o proximo no
            aux = aux->prox;
        }
        // quando chegar no ultimo no, o proximo deve ser novoNo
        aux->prox = novoNo;
    }
    lista->qtdade++;
}

void inserirElementoNoInicio(struct linkedlist *lista, int valor){
    // primeiro aloca-se um novo no
    struct no *novoNo = alocarNovoNo(valor);
    
    // em seguida verifica-se se a lista esta vazia
    if(lista->cabeca == NULL){
        // se estiver vazia, entao a lista deve apontar para o novoNo
        lista->cabeca = novoNo;
    } else{
        // se nao estiver vazia, então o proximo no do novoNo deve apontar para cabeca (antigo primiro no)
        novoNo->prox = lista->cabeca;

        // e agora cabeca aponta para novoNo
        lista->cabeca = novoNo;
    }
    lista->qtdade++;
}

void inserirElementoEmPosicao(struct linkedlist *lista, int valor, int posicao){
    if(posicao==0) inserirElementoNoInicio(lista, valor);
    else if(posicao == lista->qtdade) inserirElementoNoFim(lista, valor);
    else if((posicao>0 && posicao<lista->qtdade)){
        // primeiro aloca-se um novo no e uma variavel auxiliar que aponta para a cabeca da lista
        struct no *novoNo = alocarNovoNo(valor), *aux = lista->cabeca;
        // percorre-se a lista até a posicao antecessora da desejada
        int cont=0;
        while(cont<posicao-1){
            // aux aponta para o proximo no da fila
            aux = aux->prox;
            cont++;
        }
        // quando estiver no noh antecessor de posicao, deve-se encaixar o novo no, para isso, prox de novoNo deve apontar prox do seu antecessor (aux)
        novoNo->prox = aux->prox;
        // e o proximo do antecessor agora e novoNo
        aux->prox = novoNo;
        lista->qtdade++;
    }
}

int obterElementoEmPosicao(struct linkedlist *lista, int posicao){
    // primeiro verifica-se se eh uma posicao valida
    if(posicao>=0 && posicao<lista->qtdade){
        struct no *aux = lista->cabeca;
        int cont=0;

        while(cont!=posicao){
            aux = aux->prox;
            cont++;
        }
        return aux->val;
    }
}

void removerElementoEmPosicao(struct linkedlist *lista, int posicao){
    // primeiro verifica-se se eh uma posicao valida
    if(posicao>=0 && posicao<lista->qtdade){
        struct no *aux = lista->cabeca, *aux2;

        if(posicao==0){
            // caso deseje-se remover o primeiro no (cabeca), o novo cabeca deve ser o segundo no
            lista->cabeca = aux->prox;
            // libera a memoria do antigo cabeca;
            free(aux);
        } else{
            // caso deseje-se remover outro no, deve-se percorrer a lista ate a posicao antecessora da desejada
            // percorre-se a lista até a posicao antecessora da desejada
            int cont=0;
            while(cont<posicao-1){
                // aux aponta para o proximo no da fila
                aux = aux->prox;
                cont++;
            }
            // quando estiver na posicao antecessora da que deseja eliminar, cria-se um novo ponteiro auxiliar que aponta para o proximo no (no este que deseja-se remover)
            struct no *aux2 = aux->prox;
            // prox de aux deve apontar para o prox de aux2 (ou seja, pulou um elemento na posicao desejada)
            aux->prox = aux2->prox;
            // e, por fim, libera-se o no auxiliar
            free(aux2);
        }
        lista->qtdade--;
    }
}

void imprimirLista(struct linkedlist *lista){
    if(lista->cabeca != NULL){
        struct no *aux = lista->cabeca;
        printf("[");
        do{
            printf("%d", aux->val);
            aux = aux->prox;
            if(aux != NULL) printf(", ");
        } while(aux != NULL);
        printf("] \n");
    } else{
        printf("imprimirLista: A lista está vazia!\n");
    }
}

// Fim de implementacao de funcoes

int main(){
    struct linkedlist *lista = NULL;

    lista = inicializar();

    int numElementos = 100;

    inserirElementoEmPosicao(lista, 0, 0);
    inserirElementoEmPosicao(lista, 1, 1);

    imprimirLista(lista);
	
    /*
    for (int i = 0; i < numElementos; i++) {
		inserirElementoEmPosicao(lista, i, i);
	}

    printf("lista->qtdade: %d \nnumelementos: %d \n", lista->qtdade, numElementos);
	
	for (int i = 0; i < numElementos; i++) {
        printf("obterElementoEmPosicao(lista, %d):%d \n", i, obterElementoEmPosicao(lista, i));
	}

    /*
    inserirElementoNoFim(lista, 0);
    inserirElementoNoFim(lista, 1);
    inserirElementoNoFim(lista, 2);
    inserirElementoNoFim(lista, 3);
    inserirElementoNoFim(lista, 4);

    imprimirLista(lista);
    
    inserirElementoEmPosicao(lista, 10, );

    imprimirLista(lista);
    */
    
    return 0;
}

