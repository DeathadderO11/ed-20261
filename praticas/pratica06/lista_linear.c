#include <stdio.h>
#include <stdlib.h>
#include "lista_linear.h"

typedef struct no_t {
    struct no_t* anterior;
    int valor;
    struct no_t* proximo;
} no_t;

struct lista_t {
    no_t* primeiro;
    no_t* ultimo;
};

Lista lista_criar() {
    Lista l = (Lista)malloc(sizeof(struct lista_t));
    if (l != NULL) {
        l->primeiro = NULL;
        l->ultimo = NULL;
    }
    return l;
}

bool lista_esta_vazia(Lista l) {
    if (l == NULL) return true;
    return l->primeiro == NULL;
}

bool lista_inserir(Lista l, int valor) {
    if (l == NULL) return false;
    
    no_t* novo_no = (no_t*)malloc(sizeof(no_t));
    if (novo_no == NULL) return false;

    novo_no->valor = valor;
    novo_no->proximo = NULL;
    novo_no->anterior = l->ultimo;

    if (lista_esta_vazia(l)) {
        l->primeiro = novo_no;
    } else {
        l->ultimo->proximo = novo_no;
    }
    
    l->ultimo = novo_no;
    return true;
}

bool lista_remover(Lista l, int valor) {
    if (l == NULL || lista_esta_vazia(l)) return false;
    
    no_t* atual = l->primeiro;

    while (atual != NULL && atual->valor != valor) {
        atual = atual->proximo;
    }

    if (atual == NULL) return false; 

    if (atual->anterior != NULL) {
        atual->anterior->proximo = atual->proximo;
    } else {
        l->primeiro = atual->proximo; 
    }

    if (atual->proximo != NULL) {
        atual->proximo->anterior = atual->anterior;
    } else {
        l->ultimo = atual->anterior;
    }

    free(atual);
    return true;
}

bool lista_buscar(Lista l, int valor) {
    if (l == NULL || lista_esta_vazia(l)) return false;
    
    no_t* atual = l->primeiro;
    while (atual != NULL) {
        if (atual->valor == valor) return true;
        atual = atual->proximo;
    }
    return false;
}

void lista_exibir(Lista l) {
    if (l == NULL || lista_esta_vazia(l)) {
        printf("Lista vazia.\n");
        return;
    }
    
    no_t* atual = l->primeiro;
    printf("Elementos da Lista: [ ");
    while (atual != NULL) {
        printf("%d ", atual->valor);
        atual = atual->proximo;
    }
    printf("]\n");
}

void lista_destruir(Lista l) {
    if (l != NULL) {
        no_t* atual = l->primeiro;
        while (atual != NULL) {
            no_t* proximo = atual->proximo;
            free(atual);
            atual = proximo;
        }
        free(l);
    }
}
