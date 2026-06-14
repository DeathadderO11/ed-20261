#include <stdio.h>

float ler_e_calcular_media(int n) {
    float soma = 0.0;
    float numero;
    
    for (int i = 1; i <= n; i++) {
        printf("Digite o %do numero: ", i);
        scanf("%f", &numero);
        soma = soma + numero;
    }
    
    return soma / n;
}

int main() {
    int n;
    
    printf("--- Media Aritmetica ---\n");
    printf("Quantos numeros deseja informar? (Maximo 100): ");
    scanf("%d", &n);
    
    if (n <= 0 || n > 100) {
        printf("A quantidade deve ser entre 1 e 100.\n");
    } else {
        float media = ler_e_calcular_media(n);
        printf("A media aritmetica e: %.2f\n", media);
    }
    
    return 0;
}