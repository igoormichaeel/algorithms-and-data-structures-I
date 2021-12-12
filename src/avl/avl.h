#include <stdlib.h>

struct noBst {
  int val;
  int altura;
  int balanco;
  struct noBst* esq;
  struct noBst* dir;
};

struct noBst* alocarNovoNo(int val);
struct noBst* rotacaoDireita(struct noBst* arvore);
struct noBst* rotacaoEsquerda(struct noBst* arvore);
void inserir(struct noBst** raiz, int val, int* tamanho);
void atualizar(struct noBst* no);
struct noBst* balancear(struct noBst* no);
struct noBst* rebalancearEsqEsq(struct noBst* no);
struct noBst* rebalancearEsqDir(struct noBst* no);
struct noBst* rebalancearDirDir(struct noBst* no);
struct noBst* rebalancearDirEsq(struct noBst* no);
int max(struct noBst* raiz);
int min(struct noBst* raiz);
int altura(struct noBst* raiz);
struct noBst* endPaiMenor(struct noBst* raiz);
struct noBst* endPaiMaior(struct noBst* raiz);
struct noBst* removerNoComDoisFilhos(struct noBst* raiz);
struct noBst* remover(struct noBst* raiz, int val, int* tamanho);