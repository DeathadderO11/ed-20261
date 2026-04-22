#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "selecao.h"

#define TAMANHO 100
#define REPETICOES 100000

void gerar_vetor_aleatorio(int vetor[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        vetor[i] = rand() % 1000;
    }
}

void copiar_vetor(int origem[], int destino[], int tamanho) {
    for (int i = 0; i < tamanho; i++) {
        destino[i] = origem[i];
    }
}

int main() {
    int original[TAMANHO], vetor_teste[TAMANHO];
    clock_t inicio, fim;
    double tempo_linear, tempo_quick;
    
    srand(time(NULL));
    gerar_vetor_aleatorio(original, TAMANHO);

    int alvo_busca = original[50]; 
    int k_esimo = 50; 
    
    printf("Vetor de %d elementos gerado.\n\n", TAMANHO);

    inicio = clock();
    for (int i = 0; i < REPETICOES; i++) {
        linear_search(original, TAMANHO, alvo_busca);
    }
    fim = clock();
    tempo_linear = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    inicio = clock();
    for (int i = 0; i < REPETICOES; i++) {
        copiar_vetor(original, vetor_teste, TAMANHO);
        quick_select(vetor_teste, 0, TAMANHO - 1, k_esimo);
    }
    fim = clock();
    tempo_quick = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo da Busca Linear: %f segundos\n", tempo_linear);
    printf("Tempo do Quick Select: %f segundos\n", tempo_quick);

    return 0;
}