#include <stdio.h>

void contar_notas(int valor) {
    int notas[] = {200, 100, 50, 20, 10, 5, 2};
    int quantidade;
    
    printf("\nSaque realizado com sucesso!\n");
    
    for (int i = 0; i < 7; i++) {
        quantidade = valor / notas[i]; 
        
        if (quantidade > 0) {
            printf("- %d nota(s) de R$ %d\n", quantidade, notas[i]);
            valor = valor % notas[i];
        }
    }

    if (valor > 0) {
        printf("\nAtencao: Sobrou R$ %d que nao pode ser sacado. \n", valor);
    }
}

int main() {
    int saque;
    
    printf("--- Caixa Eletronico ---\n");
    printf("Digite o valor do saque (Maximo R$ 1000): R$ ");
    scanf("%d", &saque);
    
    if (saque <= 0 || saque > 1000) {
        printf("Erro: O valor do saque deve estar entre R$ 1 e R$ 1000.\n");
    } else {
        contar_notas(saque);
    }
    
    return 0;
}