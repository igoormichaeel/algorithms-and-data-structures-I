#include "avl.h"

#include <stdlib.h>

struct noBst* alocarNovoNo(int val) {
  struct noBst* novoNo = (struct noBst*)malloc(sizeof(struct noBst));

  novoNo->val = val;
  novoNo->altura = 0;
  novoNo->balanco = 0;
  novoNo->esq = NULL;
  novoNo->dir = NULL;

  return novoNo;
}

struct noBst* rotacaoDireita(struct noBst* arvore) {
  struct noBst* esq = arvore->esq;
  arvore->esq = esq->dir;
  esq->dir = arvore;
  atualizar(arvore);
  atualizar(esq);
  return esq;
}

struct noBst* rotacaoEsquerda(struct noBst* arvore) {
  struct noBst* dir = arvore->dir;
  arvore->dir = dir->esq;
  dir->esq = arvore;
  atualizar(arvore);
  atualizar(dir);
  return dir;
}

void inserir(struct noBst** raiz, int val, int* tamanho) {
  if (!(*raiz)) {
    (*raiz) = alocarNovoNo(val);
    (*tamanho)++;
  } else if (val <= (*raiz)->val) {
    inserir(&((*raiz)->esq), val, tamanho);
    atualizar(*raiz);
    (*raiz) = balancear(*raiz);
  } else {
    inserir(&((*raiz)->dir), val, tamanho);
    atualizar(*raiz);
    (*raiz) = balancear(*raiz);
  }
}

void atualizar(struct noBst* no) {
  if (no->esq && no->dir) {
    if (no->esq->altura >= no->dir->altura)
      no->altura = no->esq->altura + 1;
    else
      no->altura = no->dir->altura + 1;
    no->balanco = no->dir->altura - no->esq->altura;
  } else if (no->esq && !no->dir) {
    no->altura = no->esq->altura + 1;
    no->balanco = -no->esq->balanco;
  } else {
    no->altura = no->dir->altura + 1;
    no->balanco = no->dir->balanco;
  }
}

struct noBst* balancear(struct noBst* no) {
  if (no->balanco == -2) {
    if (no->esq->balanco <= 0)
      return rebalancearEsqEsq(no);  // caso 1
    else
      return rebalancearEsqDir(no);  // caso 2
  } else if (no->balanco == 2) {
    if (no->dir->balanco >= 0)
      return rebalancearDirDir(no);  // caso 3
    else
      return rebalancearDirEsq(no);  // caso 4
  }
}

struct noBst* rebalancearEsqEsq(struct noBst* no) {
  return rotacaoDireita(no);
}

struct noBst* rebalancearEsqDir(struct noBst* no) {
  no->esq = rotacaoEsquerda(no->esq);
  return rotacaoDireita(no);
}

struct noBst* rebalancearDirDir(struct noBst* no) {
  return rotacaoEsquerda(no);
}

struct noBst* rebalancearDirEsq(struct noBst* no) {
  no->dir = rotacaoDireita(no->dir);
  return rotacaoEsquerda(no);
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

struct noBst* endPaiMenor(struct noBst* raiz) {
  if (!raiz) return NULL;

  if (raiz->esq && raiz->esq->esq)
    raiz = endPaiMenor(raiz->esq);
  else
    return raiz;
}

struct noBst* endPaiMaior(struct noBst* raiz) {
  if (!raiz) return NULL;

  if (raiz->dir && raiz->dir->dir)
    raiz = endPaiMenor(raiz->dir);
  else
    return raiz;
}

struct noBst* removerNoComDoisFilhos(struct noBst* raiz) {
  if (raiz->dir->altura >= raiz->esq->altura) {
    struct noBst* paiMenor = endPaiMenor(raiz->dir);
    if (paiMenor->esq) {
      raiz->val = paiMenor->esq->val;
      if (paiMenor->esq->dir)
        paiMenor->esq = paiMenor->esq->dir;
      else
        paiMenor->esq = NULL;
      free(paiMenor->esq);
    } else {  // paiMenor é o menor
      raiz->val = paiMenor->val;
      if (paiMenor->dir)
        raiz->dir = paiMenor->dir;
      else
        raiz->dir = NULL;
      free(paiMenor);
    }
  } else {
    struct noBst* paiMaior = endPaiMaior(raiz->esq);
    if (paiMaior->dir) {
      raiz->val = paiMaior->dir->val;
      if (paiMaior->dir->esq)
        paiMaior->dir = paiMaior->dir->esq;
      else
        paiMaior->dir = NULL;
      free(paiMaior->dir);
    } else {  // paiMaior é o maior
      raiz->val = paiMaior->val;
      if (paiMaior->esq)
        raiz->esq = paiMaior->esq;
      else
        raiz->esq = NULL;
      free(paiMaior);
    }
  }
  return raiz;
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
      } else
        return removerNoComDoisFilhos(raiz);
    } else {
      if (val < raiz->val) {
        raiz->esq = remover(raiz->esq, val, tamanho);
        atualizar(raiz);
        raiz = balancear(raiz);
      } else {
        raiz->dir = remover(raiz->dir, val, tamanho);
        atualizar(raiz);
        raiz = balancear(raiz);
      }
    }
  }
}