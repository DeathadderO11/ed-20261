#include <stdio.h>
#include <stdlib.h>
#include "conta.h"  

struct conta_t {
    int numero;
    float saldo;
};

Conta conta_criar(int numero) {

    Conta nova_conta = (Conta) malloc(sizeof(struct conta_t));
    
    if (nova_conta != NULL) {
        nova_conta->numero = numero;
        nova_conta->saldo = 0.0;
    }
    
    return nova_conta;
}

void conta_depositar(Conta c, float valor) {
    if (c != NULL && valor > 0) {
        c->saldo += valor;
        printf("Deposito de R$ %.2f realizado com sucesso.\n", valor);
    } else {
        printf("Erro no deposito. Valor invalido.\n");
    }
}

int conta_sacar(Conta c, float valor) {
    if (c != NULL && valor > 0 && c->saldo >= valor) {
        c->saldo -= valor;
        printf("Saque de R$ %.2f realizado com sucesso.\n", valor);
        return 1;
    }
    printf("Falha no saque. Saldo insuficiente ou valor invalido.\n");
    return 0;
}

float conta_ver_saldo(Conta c) {
    if (c != NULL) {
        return c->saldo;
    }
    return 0.0;
}

void conta_destruir(Conta c) {
    if (c != NULL) {
        free(c);
    }
}