#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"

typedef struct no_t {
int valor;
struct no_t proximo;
} no_t;

struct pilha_t {
no_t topo;
};

Pilha pilha_criar() {
Pilha p = (Pilha)malloc(sizeof(struct pilha_t));
if (p != NULL) {
p->topo = NULL;
}
return p;
}

bool pilha_esta_vazia(Pilha p) {
if (p == NULL) return true;
return p->topo == NULL;
}

bool pilha_empilhar(Pilha p, int valor) {
if (p == NULL) return false;

no_t* novo_no = (no_t*)malloc(sizeof(no_t));
if (novo_no == NULL) return false;
novo_no->valor = valor;
novo_no->proximo = p->topo;
p->topo = novo_no;

return true;
}

bool p_desempilhar(Pilha p, int valor_removido) {
if (p == NULL || pilha_esta_vazia(p)) return false;

no_t* no_aux = p->topo;
if (valor_removido != NULL) {
*valor_removido = no_aux->valor;
}

p->topo = no_aux->proximo;
free(no_aux);

return true;
}

bool pilha_topo(Pilha p, int valor_topo) {
if (p == NULL || pilha_esta_vazia(p)) return false;

if (valor_topo != NULL) {
*valor_topo = p->topo->valor;
}
return true;
}

void pilha_exibir(Pilha p) {
if (p == NULL || pilha_esta_vazia(p)) {
printf("Pilha vazia.\n");
return;
}

no_t* atual = p->topo;
printf("Pilha (Topo -> Base): ");
while (atual != NULL) {
printf("[%d] ", atual->valor);
atual = atual->proximo;
}
printf("\n");
}

/* Destrói a pilha, liberando toda a memória alocada /
void pilha_destruir(Pilha p) {
if (p != NULL) {
no_t atual = p->topo;
while (atual != NULL) {
no_t* proximo = atual->proximo;
free(atual);
atual = proximo;
}
free(p);
}
}
