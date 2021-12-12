#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

// função auxiliar: swap
void swap(int *v, int i, int j){
    int temp = v[i];

    v[i] = v[j];
    v[j] = temp;
}

void swapDOUBLE(double *v, int i, int j){
    int temp = v[i];

    v[i] = v[j];
    v[j] = temp;
}

// selectionSort in-place
void selectionSortIP(int *v, int tamanho){
    for(int j=0; j<tamanho-1; j++){
        int iMenor = j;

        for(int i=j+1; i<tamanho; i++){
            if(v[i] < v[iMenor]) iMenor = i;
        }

        int temp = v[j];
        v[j] = v[iMenor];
        v[iMenor] = temp;
    }
}

// bubbleSort
void bubbleSort(int* v, int n){
    for(int j = 0; j < n-1; j++){
        bool trocou = false;

        for(int i=0; i < n-j-1; i++){
            if(v[i] > v[i+1]){
                swap(v, i, i+1);
                trocou = true;
            }
        }

        if(!trocou) return;
    }
}

// insertionSort in-place
void insertionSortIP(int* v, int tamanho){
    for(int i=1; i < tamanho; i++){
        int valor = v[i];
        int j;

        for(j=i; j > 0 && v[j-1 ] > valor; j--){
            v[j] = v[j-1];
        }

        v[j] = valor;
    }
}

// mergeSort
void merge(int *v, int tamV, int *e, int tamE, int *d, int tamD){
    int indexV = 0, indexE = 0, indexD = 0;

    while(indexE < tamE && indexD < tamD){
        if(e[indexE] <= d[indexD]){
            v[indexV] = e[indexE];
            indexE++;
        } else{
            v[indexV] = d[indexD];
            indexD++;
        }
        indexV++;
    }
    while(indexE < tamE){
        v[indexV] = e[indexE];
        indexE++;
        indexV++;
    }
    while(indexD < tamD){
        v[indexV] = d[indexD];
        indexD++;
        indexV++;
    }
}

void mergeSort(int *v, int tamV){
    if(tamV > 1){
        int meio = tamV/2, tamE = meio, tamD = tamV - meio;
        int *e = (int*)malloc(tamE*sizeof(int));
        int *d = (int*)malloc(tamD*sizeof(int));
        
        for(int i = 0; i < meio; i++){
            e[i] = v[i];
        }
        for(int i = meio; i < tamV; i++) {
            d[i-meio] = v[i];
        }
        
        mergeSort(e, tamE);
        mergeSort(d, tamD);

        merge(v, tamV, e, tamE, d, tamD);

        free(e);
        free(d);
    }
}

// quickSort
int particiona(int *v, int ini, int fim, bool randomizacao){
    int pivoIndex = ini;

    if(randomizacao){
        srand(time(0));

        int i_pivo = rand() % (fim - ini + 1) + ini;
        
        swap(v, i_pivo, fim);
    }

    int pivo = v[fim];  

    for(int i = ini; i < fim; i++){
        if(v[i] <= pivo){
            swap(v, pivoIndex, i);
            pivoIndex++;
        }
    }

    swap(v, pivoIndex, fim);

    return pivoIndex;
}

void quickSort(int *v, int ini, int fim, bool randomizacao){
    int tam = fim - ini + 1;
    if (tam>1){
        int pivoIndex = particiona(v, ini, fim, randomizacao);
        quickSort(v, ini, pivoIndex - 1, randomizacao);
        quickSort(v, pivoIndex + 1, fim, randomizacao);
    }
}

int particionaDOUBLE(double *v, int ini, int fim, bool randomizacao){
    int pivoIndex = ini;

    if(randomizacao){
        srand(time(0));

        int i_pivo = rand() % (fim - ini + 1) + ini;
        
        swapDOUBLE(v, i_pivo, fim);
    }

    int pivo = v[fim];  

    for(int i = ini; i < fim; i++){
        if(v[i] <= pivo){
            swapDOUBLE(v, pivoIndex, i);
            pivoIndex++;
        }
    }

    swapDOUBLE(v, pivoIndex, fim);

    return pivoIndex;
}

void quickSortDOUBLE(double *v, int ini, int fim, bool randomizacao){
    int tam = fim - ini + 1;
    if (tam>1){
        int pivoIndex = particionaDOUBLE(v, ini, fim, randomizacao);
        quickSortDOUBLE(v, ini, pivoIndex - 1, randomizacao);
        quickSortDOUBLE(v, pivoIndex + 1, fim, randomizacao);
    }
}

// countingSort
void countingSort(int *v, int tamanho){
    int iMenor = 0, iMaior = 0;

    for(int i = 0; i < tamanho; i++){
        if(v[i] < v[iMenor]) iMenor = i;
        if(v[i] > v[iMaior]) iMaior = i;
    }

    int vMenor = v[iMenor], vMaior = v[iMaior];
    int tamanho_c = vMaior - vMenor + 1;
    int* c = (int*)calloc(tamanho_c, sizeof(int));

    for(int i = 0; i < tamanho; i++){
        c[v[i] - vMenor]++;
    }

    int index_v = 0;

    for(int i=0; i < tamanho_c; i++){
        int j = c[i];
        while(j > 0){
            v[index_v] = i + vMenor;
            index_v++;
            j--;
        }
    }
}

// função auxiliar: instancia array
int* instanciaINT(int tamanho){
    int *v = (int*)malloc(tamanho * sizeof(int));

    return v;
}

double* instanciaDOUBLE(int tamanho){
    double *v = (double*)malloc(tamanho * sizeof(double));

    return v;
}

// funções auxiliares: exibir arrays
void exibirArrayINT(int *v, int tamV) {
    printf("[");

    for (int i = 0; i < tamV; i++) {
        printf("%d", v[i]);

        if (i < tamV - 1) printf(", ");
    }

    printf("]\n");
}

void exibirArrayDOUBLE(double *v, int tamV) {
    printf("[");

    for (int i = 0; i < tamV; i++) {
        printf("%lf", v[i]);

        if (i < tamV - 1) printf(", ");
    }

    printf("]\n");
}

// função auxiliar: gera arrays
void geraArrays(int* v_random, int* v_ordenado_cre, int* v_ordenado_dec, int tamanho, int limite_superior, time_t seed){
    srand(seed);
    for(int i = 0; i < tamanho; i++){
        v_random[i] = rand();
        if(i == 0){
            v_ordenado_cre[i] = rand() % limite_superior;
            v_ordenado_dec[i] = rand() % limite_superior;
        } else{
            v_ordenado_cre[i] = rand() % (limite_superior - v_ordenado_cre[i-1] + 1) + v_ordenado_cre[i-1];
            v_ordenado_dec[i] = rand() % v_ordenado_dec[i-1] + 1;
        }
    }
}

// função auxiliar: calcula tempo
double ordenaEComputaTempo(int* v, int tamanho, int code){
    /*
    * Códigos:
    * 0 - selectionSort in-place
    * 1 - bubbleSort
    * 2 - insertionSort in-place
    * 3 - mergeSort
    * 4 - quickSort sem randomização de pivô
    * 5 - quickSort com randomização de pivô
    * 6 - countingSort
    */
    clock_t begin, end;

    begin = clock();
    
    switch(code){
        case 0:
            selectionSortIP(v, tamanho);
            break;
        case 1:
            bubbleSort(v, tamanho);
            break;
        case 2:
            insertionSortIP(v, tamanho);
            break;
        case 3:
            mergeSort(v, tamanho);
            break;
        case 4:
            quickSort(v, 0, tamanho - 1, false);
            break;
        case 5:
            quickSort(v, 0, tamanho - 1, true);
            break;
        case 6:
            countingSort(v, tamanho);
            break;
        default:
            printf("Erro: código do ordenador inválido (1-7)!\n");
            break;
    }

    end = clock();

    double tempo = (double)(end - begin)/(CLOCKS_PER_SEC/1000);

    //printf("Tempo total: %lf\n", tempo);
    
    return tempo;
}

int main(){
    int limite_superior = 1000;
    int tamanho = 100000;
    int* v_random = instanciaINT(tamanho);
    int* v_ordenado_cre = instanciaINT(tamanho);
    int* v_ordenado_dec = instanciaINT(tamanho);
    double* tempos_v_random = instanciaDOUBLE(30);
    double* tempos_v_ordenado_cre = instanciaDOUBLE(30);
    double* tempos_v_ordenado_dec = instanciaDOUBLE(30);

    time_t seed = time(NULL);
    
    printf("--------------------------------------------------------\n");
    for(int i = 0; i < 7; i++){  // Laço para 7 algoritmos
        double media_v_random = 0, media_v_ordenado_cre = 0, media_v_ordenado_dec = 0;
        // if(i == 0 || i == 1 || i == 2) continue;
        for(int j = 0; j < 30; j++){ // Laço para preencher os vetores de tempo
            geraArrays(v_random, v_ordenado_cre, v_ordenado_dec, tamanho, limite_superior, seed);
            // Vetor com valores aleatórios:
            tempos_v_random[j] = ordenaEComputaTempo(v_random, tamanho, i);
            media_v_random += tempos_v_random[j];
            // Vetor ordenado crescente:
            tempos_v_ordenado_cre[j] = ordenaEComputaTempo(v_ordenado_cre, tamanho, i);
            media_v_ordenado_cre += tempos_v_ordenado_cre[j];
            // Vetor ordenado decrescente:
            tempos_v_ordenado_dec[j] = ordenaEComputaTempo(v_ordenado_dec, tamanho, i);
            media_v_ordenado_dec += tempos_v_ordenado_dec[j];
        }
        // Ordena os vetores de tempo para cálculo de mediana
        quickSortDOUBLE(tempos_v_random, 0, 29, true);
        quickSortDOUBLE(tempos_v_ordenado_cre, 0, 29, true);
        quickSortDOUBLE(tempos_v_ordenado_dec, 0, 29, true);

        switch(i){
            case 0:
                printf("selectionSortIP:\n");
                break;
            case 1:
                printf("bubbleSort:\n");
                break;
            case 2:
                printf("insertionSortIP:\n");
                break;
            case 3:
                printf("mergeSort:\n");
                break;
            case 4:
                printf("quickSort sem randomização de pivô:\n");
                break;
            case 5:
                printf("quickSort com randomização de pivô:\n");
                break;
            case 6:
                printf("countingSort:\n");
                break;
            default:
                printf("Erro: código do ordenador inválido (1-7)!\n");
                break;
        }

        printf("Média, em milissegundos, para array com elementos aleatórios: %lf\n", media_v_random /= 30);
        printf("Mediana, em milissegundos, para array com elementos aleatórios: %lf\n", tempos_v_random[15]);

        printf("Média, em milissegundos, para array ordenado crescente: %lf\n", media_v_ordenado_cre /= 30);
        printf("Mediana, em milissegundos, para array com elementos aleatórios: %lf\n", v_ordenado_cre[tamanho/2]);

        printf("Média, em milissegundos, para array ordenado decrescente: %lf\n", media_v_ordenado_dec /= 30);
        printf("Mediana, em milissegundos, para array com elementos aleatórios: %lf\n", v_ordenado_dec[tamanho/2]);
        printf("--------------------------------------------------------\n");
    }

    return 0;
}