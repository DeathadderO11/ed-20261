#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct no_t {
int valor;
struct no_t proximo;
} no_t;

struct fila_t {
no_t inicio;
no_t* fim;
};

Fila fila_criar() {
Fila f = (Fila)malloc(sizeof(struct fila_t));
if (f != NULL) {
f->inicio = NULL;
f->fim = NULL;
}
return f;
}

bool fila_esta_vazia(Fila f) {
if (f == NULL) return true;
return f->inicio == NULL;
}

bool fila_enfileirar(Fila f, int valor) {
if (f == NULL) return false;

no_t* novo_no = (no_t*)malloc(sizeof(no_t));
if (novo_no == NULL) return false;

novo_no->valor = valor;
novo_no->proximo = NULL;

if (fila_esta_vazia(f)) {
f->inicio = novo_no;
} else {
f->fim->proximo = novo_no;
}

f->fim = novo_no;
return true;
}

bool fila_desenfileirar(Fila f, int valor_removido) {
if (f == NULL || fila_esta_vazia(f)) return false;

no_t* no_aux = f->inicio;
if (valor_removido != NULL) {
*valor_removido = no_aux->valor;
}

f->inicio = no_aux->proximo;
if (f->inicio == NULL) {
f->fim = NULL;
}

free(no_aux);
return true;
}

bool fila_inicio(Fila f, int valor_inicio) {
if (f == NULL || fila_esta_vazia(f)) return false;

if (valor_inicio != NULL) {
*valor_inicio = f->inicio->valor;
}
return true;
}

void fila_exibir(Fila f) {
if (f == NULL || fila_esta_vazia(f)) {
printf("Fila vazia.\n");
return;
}

no_t* atual = f->inicio;
printf("Fila (Inicio -> Fim): [ ");
while (atual != NULL) {
printf("%d ", atual->valor);
atual = atual->proximo;
}
printf("]\n");
}

void fila_destruir(Fila f) {
if (f != NULL) {
no_t atual = f->inicio;
while (atual != NULL) {
no_t* proximo = atual->proximo;
free(atual);
atual = proximo;
}
free(f);
}
}
