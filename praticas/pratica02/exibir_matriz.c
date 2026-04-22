#include <stdio.h>
#include <time.h>

void percorre_dois_lacos(int matriz[10][10]) {
    int soma = 0;
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            soma += matriz[i][j];
        }
    }
}

void percorre_um_laco(int matriz[10][10]) {
    int soma = 0;
    int *ponteiro = &matriz[0][0];
    
    for (int i = 0; i < 100; i++) {
        soma += ponteiro[i];
    }
}

int main() {
    int matriz[10][10];
    clock_t inicio, fim;
    double tempo_dois_lacos, tempo_um_laco;
    
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            matriz[i][j] = 1;
        }
    }
    
    inicio = clock();
    for(int i=0; i<10000; i++) percorre_dois_lacos(matriz);
    fim = clock();
    tempo_dois_lacos = ((double) (fim - inicio)) / CLOCKS_PER_SEC;

    inicio = clock();
    for(int i=0; i<10000; i++) percorre_um_laco(matriz);
    fim = clock();
    tempo_um_laco = ((double) (fim - inicio)) / CLOCKS_PER_SEC;
    
    printf("Tempo com DOIS lacos aninhados: %f segundos\n", tempo_dois_lacos);
    printf("Tempo com UM unico laco:        %f segundos\n", tempo_um_laco);
    
    return 0;
}