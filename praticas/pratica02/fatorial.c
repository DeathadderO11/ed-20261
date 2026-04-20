#include <stdio.h>

unsigned long long fatorial_iterativo(int n) {
    unsigned long long resultado = 1;
    for (int i = 2; i <= n; i++) {
        resultado *= i;
    }
    return resultado;
}

unsigned long long fatorial_recursivo(int n) {
    if (n == 0 || n == 1) {
        return 1;
    }
    return n * fatorial_recursivo(n - 1);
}

int main() {
    int numero;
    
    printf("--- Calculo de Fatorial ---\n");
    printf("Digite um numero inteiro positivo: ");
    scanf("%d", &numero);
    
    if (numero < 0) {
        printf("Erro: Nao existe fatorial de numero negativo.\n");
    } else {
        printf("Resultado Iterativo: %llu\n", fatorial_iterativo(numero));
        printf("Resultado Recursivo: %llu\n", fatorial_recursivo(numero));
    }
    
    return 0;
}