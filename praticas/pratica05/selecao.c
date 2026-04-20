#include "selecao.h"

int linear_search(int vetor[], int tamanho, int alvo) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == alvo) {
            return i;
        }
    }
    return -1;
}

int particiona_selecao(int vetor[], int inicio, int fim) {
    int pivo = vetor[fim];
    int i = inicio - 1;
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

    return i + 1;
}

int quick_select(int vetor[], int inicio, int fim, int k) {
    if (inicio <= fim) {
        int posicao_pivo = particiona_selecao(vetor, inicio, fim);
        if (posicao_pivo == k) {
            return vetor[posicao_pivo];
        } 
        else if (posicao_pivo > k) {
            return quick_select(vetor, inicio, posicao_pivo - 1, k);
        } 
        else {
            return quick_select(vetor, posicao_pivo + 1, fim, k);
        }
    }
    return -1;
}