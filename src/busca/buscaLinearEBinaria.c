#include <stdio.h>
#include <stdlib.h>

int buscaLinear(int* vetor, int tam, int valor) {
  for (int i = 0; i < tam; i++)
    if (vetor[i] == valor) return i;
  return -1;
}

int buscaPosicao(int* vetor, int tam, int valor) {
  int inicio = 0, fim = tam - 1, delta = tam, meio, posicao;

  while (delta >= 1) {
    delta = fim - inicio + 1;
    meio = delta / 2 + inicio;

    if (delta == 1 || delta == 2) {
      if (valor <= vetor[fim])
        return fim;
      else
        return fim + 1;
    }

    if (valor == vetor[meio])
      return meio;
    else if (valor < vetor[meio])
      fim = meio - 1;
    else
      inicio = meio + 1;
  }
}

int buscaBinaria(int* vetor, int tam, int valor) {
  int inicio = 0, fim = tam - 1, delta, meio;

  while (inicio != fim) {
    delta = fim - inicio + 1;
    meio = delta / 2 + inicio;

    if (valor == vetor[meio])
      return meio;
    else if (valor < vetor[meio])
      fim = meio - 1;
    else
      inicio = meio + 1;
  }

  if (valor == vetor[inicio]) return inicio;

  return -1;
}