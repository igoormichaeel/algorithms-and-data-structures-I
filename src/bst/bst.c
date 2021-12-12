#include "bst.h"

#include <stdio.h>
#include <stdlib.h>

struct noBst* alocarNovoNo(int val) {
  struct noBst* novoNo = (struct noBst*)malloc(sizeof(struct noBst));

  novoNo->val = val;
  novoNo->esq = NULL;
  novoNo->dir = NULL;

  return novoNo;
}

void inserir(struct noBst** raiz, int val, int* tamanho) {
  if (!(*raiz)) {
    (*raiz) = alocarNovoNo(val);
    (*tamanho)++;
  } else if (val <= (*raiz)->val) {
    inserir(&((*raiz)->esq), val, tamanho);
  } else {
    inserir(&((*raiz)->dir), val, tamanho);
  }
}

bool buscar(struct noBst* raiz, int val) {
  if (!raiz)
    return false;
  else if (val == raiz->val)
    return true;
  else if (val < raiz->val)
    buscar(raiz->esq, val);
  else
    buscar(raiz->dir, val);
}

int max(struct noBst* raiz) {
  if (!raiz) return 0;

  if (raiz->dir)
    max(raiz->dir);
  else
    return raiz->val;
}

int min(struct noBst* raiz) {
  if (!raiz) return 0;

  if (raiz->esq)
    min(raiz->esq);
  else
    return raiz->val;
}

int altura(struct noBst* raiz) {
  if (!raiz)
    return 0;
  else {
    int esq = altura(raiz->esq), dir = altura(raiz->dir);
    if (!raiz->esq && !raiz->dir) return 0;
    if (esq > dir)
      return esq + 1;
    else
      return dir + 1;
  }
}

void emOrdem(struct noBst* raiz) {
  if (raiz->esq) emOrdem(raiz->esq);
  printf("%d ", raiz->val);
  if (raiz->dir) emOrdem(raiz->dir);
}

void preOrdem(struct noBst* raiz) {
  printf("%d ", raiz->val);
  if (raiz->esq) preOrdem(raiz->esq);
  if (raiz->dir) preOrdem(raiz->dir);
}

void posOrdem(struct noBst* raiz) {
  if (raiz->esq) posOrdem(raiz->esq);
  if (raiz->dir) posOrdem(raiz->dir);
  printf("%d ", raiz->val);
}

struct noBst* endPaiMenor(struct noBst* raiz) {
  if (!raiz) return NULL;

  if (raiz->esq && raiz->esq->esq)
    raiz = endPaiMenor(raiz->esq);
  else
    return raiz;
}

void removerNoComDoisFilhos(struct noBst* raiz) {
  struct noBst* paiMenor = endPaiMenor(raiz->dir);

  if (paiMenor->esq) {
    int menor = paiMenor->esq->val;
    raiz->val = menor;
    free(paiMenor->esq);
    paiMenor->esq = NULL;
  } else {
    raiz->val = paiMenor->val;
    free(paiMenor);
    raiz->dir = NULL;
  }
}

struct noBst* remover(struct noBst* raiz, int val, int* tamanho) {
  if (!raiz)
    return NULL;
  else {
    if (raiz->val == val) {
      if (!raiz->esq && !raiz->dir)
        return NULL;
      else if ((raiz->esq && !raiz->dir) || (!raiz->esq && raiz->dir)) {
        struct noBst* aux;
        if (raiz->esq)
          aux = raiz->esq;
        else
          aux = raiz->dir;
        free(raiz);
        return aux;
      } else {
        removerNoComDoisFilhos(raiz);
      }
    } else {
      if (val < raiz->val)
        raiz->esq = remover(raiz->esq, val, tamanho);
      else
        raiz->dir = remover(raiz->dir, val, tamanho);
      return raiz;
    }
  }
}

struct noBst* rotacaoDireita(struct noBst* raiz) {
  struct noBst* esq = raiz->esq;
  raiz->esq = raiz->esq->dir;
  esq->dir = raiz;
  return esq;
}

struct noBst* rotacaoEsquerda(struct noBst* raiz) {
  struct noBst* dir = raiz->dir;
  raiz->dir = raiz->dir->esq;
  dir->esq = raiz;
  return dir;
}