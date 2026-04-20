#ifndef CONTA_H
#define CONTA_H

typedef struct conta_t* Conta;

Conta conta_criar(int numero);
void conta_depositar(Conta c, float valor);
int conta_sacar(Conta c, float valor);
float conta_ver_saldo(Conta c);
void conta_destruir(Conta c);

#endif