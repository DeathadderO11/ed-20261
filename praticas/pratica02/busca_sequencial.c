#include <stdio.h>

int busca_sequencial(int vetor[], int tamanho, int alvo) {
    for (int i = 0; i < tamanho; i++) {
        if (vetor[i] == alvo) {
            return i;
        }
    }
    return -1;
}

int main() {
    int vetor[100];
    int alvo, posicao;
    
    printf("--- Busca Sequencial ---\n");

    for (int i = 0; i < 100; i++) {
        vetor[i] = i + 1;
    }
    
    printf("Digite o numero que deseja buscar: ");
    scanf("%d", &alvo);
    
    posicao = busca_sequencial(vetor, 100, alvo);
    
    if (posicao != -1) {
        printf("Numero %d encontrado no indice %d!\n", alvo, posicao);
    } else {
        printf("Numero %d NAO foi encontrado no vetor.\n", alvo);
    }
    
    return 0;
}