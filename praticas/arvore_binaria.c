#include <stdio.h>
#include <stdlib.h>
#include "arvore_binaria.h"

typedef struct no_t {
struct no_t esquerda;
int valor;
struct no_t* direita;
} no_t;

struct arvore_t {
no_t raiz;
};

Arvore arvore_criar() {
Arvore a = (Arvore)malloc(sizeof(struct arvore_t));
if (a != NULL) {
a->raiz = NULL;
}
return a;
}

bool arvore_esta_vazia(Arvore a) {
if (a == NULL) return true;
return a->raiz == NULL;
}

static no_t inserir_no(no_t* raiz, int valor, bool* sucesso) {
if (raiz == NULL) {
no_t* novo_no = (no_t*)malloc(sizeof(no_t));
if (novo_no == NULL) {
*sucesso = false;
return NULL;
}
novo_no->valor = valor;
novo_no->esquerda = NULL;
novo_no->direita = NULL;
*sucesso = true;
return novo_no;
}

if (valor < raiz->valor) {
raiz->esquerda = inserir_no(raiz->esquerda, valor, sucesso);
} else if (valor > raiz->valor) {
raiz->direita = inserir_no(raiz->direita, valor, sucesso);
} else {
*sucesso = false;
}

return raiz;
}

bool arvore_inserir(Arvore a, int valor) {
if (a == NULL) return false;
bool sucesso = false;
a->raiz = inserir_no(a->raiz, valor, &sucesso);
return sucesso;
}

static void exibir_pre_ordem_no(no_t* raiz) {
if (raiz != NULL) {
printf("%d ", raiz->valor);
exibir_pre_ordem_no(raiz->esquerda);
exibir_pre_ordem_no(raiz->direita);
}
}

static void exibir_em_ordem_no(no_t* raiz) {
if (raiz != NULL) {
exibir_em_ordem_no(raiz->esquerda);
printf("%d ", raiz->valor);
exibir_em_ordem_no(raiz->direita);
}
}

static void exibir_pos_ordem_no(no_t* raiz) {
if (raiz != NULL) {
exibir_pos_ordem_no(raiz->esquerda);
exibir_pos_ordem_no(raiz->direita);
printf("%d ", raiz->valor);
}
}

void arvore_exibir_pre_ordem(Arvore a) {
if (a == NULL || arvore_esta_vazia(a)) {
printf("Arvore vazia.\n");
return;
}
printf("Pre-ordem: [ ");
exibir_pre_ordem_no(a->raiz);
printf("]\n");
}

void arvore_exibir_em_ordem(Arvore a) {
if (a == NULL || arvore_esta_vazia(a)) {
printf("Arvore vazia.\n");
return;
}
printf("Em ordem: [ ");
exibir_em_ordem_no(a->raiz);
printf("]\n");
}

void arvore_exibir_pos_ordem(Arvore a) {
if (a == NULL || arvore_esta_vazia(a)) {
printf("Arvore vazia.\n");
return;
}
printf("Pos-ordem: [ ");
exibir_pos_ordem_no(a->raiz);
printf("]\n");
}

static void destruir_no(no_t raiz) {
if (raiz != NULL) {
destruir_no(raiz->esquerda);
destruir_no(raiz->direita);
free(raiz);
}
}

void arvore_destruir(Arvore a) {
if (a != NULL) {
destruir_no(a->raiz);
free(a);
}
}
