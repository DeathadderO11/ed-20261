#include <stdio.h>
#include "conta.h"

void exibir_boas_vindas() {
    printf("   SISTEMA BANCARIO   \n");
}

int main() {
    exibir_boas_vindas();

    Conta minha_conta = conta_criar(12345);
    if (minha_conta == NULL) {
        printf("Erro de memoria ao criar a conta!\n");
        return 1;
    }
    printf("Conta numero 12345 criada com sucesso!\n");
    printf("Saldo inicial: R$ %.2f\n\n", conta_ver_saldo(minha_conta));

    conta_depositar(minha_conta, 500.00);
    printf("Saldo atual: R$ %.2f\n\n", conta_ver_saldo(minha_conta));

    conta_sacar(minha_conta, 150.00);
    printf("Saldo atual: R$ %.2f\n\n", conta_ver_saldo(minha_conta));

    conta_sacar(minha_conta, 1000.00);
    printf("Saldo atual: R$ %.2f\n\n", conta_ver_saldo(minha_conta));

    conta_destruir(minha_conta);
    printf("Conta encerrada e memoria liberada com sucesso.\n");

    return 0;
}