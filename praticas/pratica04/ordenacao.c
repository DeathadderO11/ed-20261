#include "ordenacao.h"

void bubble_sort(int vetor[], int tamanho) {
    int aux;
    for (int i = 0; i < tamanho - 1; i++) {
        for (int j = 0; j < tamanho - i - 1; j++) {
            if (vetor[j] > vetor[j + 1]) {
                aux = vetor[j];
                vetor[j] = vetor[j + 1];
                vetor[j + 1] = aux;
            }
        }
    }
}

void selection_sort(int vetor[], int tamanho) {
    int min_idx, aux;
    for (int i = 0; i < tamanho - 1; i++) {
        min_idx = i;
        for (int j = i + 1; j < tamanho; j++) {
            if (vetor[j] < vetor[min_idx]) {
                min_idx = j;
            }
        }

        if (min_idx != i) {
            aux = vetor[i];
            vetor[i] = vetor[min_idx];
            vetor[min_idx] = aux;
        }
    }
}

int particiona(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = (inicio - 1);
    int aux;

    for (int j = inicio; j < fim; j++) {
        if (vetor[j] <= pivo) {
            i++;
            aux = vetor[i];
            vetor[i] = vetor[j];
            vetor[j] = aux;
        }
    }
    aux = vetor[i + 1];
    vetor[i + 1] = vetor[fim];
    vetor[fim] = aux;

    return (i + 1);
}

void quick_sort(int vetor[], int inicio, int fim) {
    if (inicio < fim) {
        int pi = particiona(vetor, inicio, fim);
        quick_sort(vetor, inicio, pi - 1);
        quick_sort(vetor, pi + 1, fim);   
    }
}