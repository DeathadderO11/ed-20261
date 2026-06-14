#include <stdio.h>

void calcular_situacao_imc(float peso, float altura) {
    float imc = peso / (altura * altura);
    
    printf("Seu IMC e: %.2f\n", imc);
    printf("Situacao: ");
    
    if (imc < 18.5) {
        printf("Abaixo do peso\n");
    } else if (imc >= 18.5 && imc <= 24.9) {
        printf("Peso normal\n");
    } else if (imc >= 25.0 && imc <= 29.9) {
        printf("Sobrepeso\n");
    } else {
        printf("Obesidade\n");
    }
}

int main() {
    float peso, altura;
    
    printf("--- Calculadora de IMC ---\n");
    printf("Digite o seu peso: ");
    scanf("%f", &peso);
    
    printf("Digite a sua altura: ");
    scanf("%f", &altura);
    
    calcular_situacao_imc(peso, altura);
    
    return 0;
}