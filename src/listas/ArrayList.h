struct arraylist {
  int* vetor;
  int qtdade;
  int capacidade;
};

// Declaracao de funcoes

struct arraylist* inicializar(int capacidade);

int obterElementoEmPosicao(struct arraylist* lista, int posicao);

void duplicarCapacidade(struct arraylist* lista);

void inserirElementoNoFim(struct arraylist* lista, int valor);

void inserirElementoEmPosicao(struct arraylist* lista, int valor, int posicao);

void atualizarElemento(struct arraylist* lista, int valor, int posicao);

void removerElementoNoFim(struct arraylist* lista);

void removerElementoEmPosicao(struct arraylist* lista, int posicao);

void exibirLista(struct arraylist* lista);

// Fim de declaracao de funcoes