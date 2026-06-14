#include <stdio.h>

float calcular_potencia(float base, int expoente) {
    float resultado = 1.0;
    
    for (int i = 0; i < expoente; i++) {
        resultado = resultado * base;
    }
    
    return resultado;
}

int main() {
    float base;
    int expoente;
    
    printf("--- Calculo de Potencia ---\n");
    printf("Digite o valor da base: ");
    scanf("%f", &base);
    
    printf("Digite o expoente: ): ");
    scanf("%d", &expoente);
    
    if (expoente < 0) {
        printf("O expoente deve ser positivo.\n");
    } else {
        float resultado = calcular_potencia(base, expoente);
        printf("Resultado: %.2f\n", resultado);
    }
    
    return 0;
}