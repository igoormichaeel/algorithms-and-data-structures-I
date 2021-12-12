#include <stdbool.h>

struct noBst {
  int val;
  struct noBst* esq;
  struct noBst* dir;
};

struct noBst* alocarNovoNo(int val);
void inserir(struct noBst** raiz, int val, int* tamanho);
bool buscar(struct noBst* raiz, int val);
int max(struct noBst* raiz);
int min(struct noBst* raiz);
int altura(struct noBst* raiz);
void emOrdem(struct noBst* raiz);
void preOrdem(struct noBst* raiz);
void posOrdem(struct noBst* raiz);
struct noBst* endPaiMenor(struct noBst* raiz);
void removerNoComDoisFilhos(struct noBst* raiz);
struct noBst* remover(struct noBst* raiz, int val, int* tamanho);
struct noBst* rotacaoDireita(struct noBst* raiz);
struct noBst* rotacaoEsquerda(struct noBst* raiz);