#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "ordenacao.h"

#define TAMANHO 100
#define REPETICOES 10000

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
    double tempo_bubble, tempo_selection, tempo_quick;

    gerar_vetor_aleatorio(original, TAMANHO);
    printf("Vetor original de %d elementos gerado.\n\n", TAMANHO);

    inicio = clock();
    for (int i = 0; i < REPETICOES; i++) {
        copiar_vetor(original, vetor_teste, TAMANHO);
        bubble_sort(vetor_teste, TAMANHO);
    }
    fim = clock();
    tempo_bubble = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    inicio = clock();
    for (int i = 0; i < REPETICOES; i++) {
        copiar_vetor(original, vetor_teste, TAMANHO);
        selection_sort(vetor_teste, TAMANHO);
    }
    fim = clock();
    tempo_selection = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    inicio = clock();
    for (int i = 0; i < REPETICOES; i++) {
        copiar_vetor(original, vetor_teste, TAMANHO);
        quick_sort(vetor_teste, 0, TAMANHO - 1);
    }
    fim = clock();
    tempo_quick = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    printf("Tempo do Bubble Sort:    %f segundos\n", tempo_bubble);
    printf("Tempo do Selection Sort: %f segundos\n", tempo_selection);
    printf("Tempo do Quick Sort:     %f segundos\n", tempo_quick);

    return 0;
}