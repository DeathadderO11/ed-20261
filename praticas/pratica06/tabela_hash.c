#include <stdio.h>
#include <stdlib.h>
#include "tabela_hash.h"

typedef struct no_t {
    int valor;
    struct no_t* proximo;
} no_t;

struct hash_t {
    no_t** tabela;
    int tamanho;
};

static int funcao_hash(int valor, int tamanho) {
    if (valor < 0) {
        return (valor % tamanho + tamanho) % tamanho; 
    }
    return valor % tamanho;
}

TabelaHash hash_criar(int tamanho) {
    if (tamanho <= 0) return NULL;

    TabelaHash h = (TabelaHash)malloc(sizeof(struct hash_t));
    if (h == NULL) return NULL;

    h->tamanho = tamanho;
    h->tabela = (no_t**)calloc(tamanho, sizeof(no_t*));
    if (h->tabela == NULL) {
        free(h);
        return NULL;
    }

    return h;
}

bool hash_esta_vazia(TabelaHash h) {
    if (h == NULL || h->tabela == NULL) return true;

    for (int i = 0; i < h->tamanho; i++) {
        if (h->tabela[i] != NULL) {
            return false;
        }
    }
    return true;
}

bool hash_inserir(TabelaHash h, int valor) {
    if (h == NULL || h->tabela == NULL) return false;
    if (hash_buscar(h, valor)) return false;

    int indice = funcao_hash(valor, h->tamanho);

    no_t* novo_no = (no_t*)malloc(sizeof(no_t));
    if (novo_no == NULL) return false;

    novo_no->valor = valor;
    novo_no->proximo = h->tabela[indice];
    h->tabela[indice] = novo_no;

    return true;
}

bool hash_buscar(TabelaHash h, int valor) {
    if (h == NULL || h->tabela == NULL) return false;

    int indice = funcao_hash(valor, h->tamanho);
    no_t* atual = h->tabela[indice];

    while (atual != NULL) {
        if (atual->valor == valor) {
            return true;
        }
        atual = atual->proximo;
    }
    return false;
}

bool hash_remover(TabelaHash h, int valor) {
    if (h == NULL || h->tabela == NULL) return false;

    int indice = funcao_hash(valor, h->tamanho);
    no_t* atual = h->tabela[indice];
    no_t* anterior = NULL;

    while (atual != NULL && atual->valor != valor) {
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL) return false;

    if (anterior == NULL) {
        
        h->tabela[indice] = atual->proximo;
    } else {
      
        anterior->proximo = atual->proximo;
    }

    free(atual);
    return true;
}

void hash_exibir(TabelaHash h) {
    if (h == NULL || h->tabela == NULL) {
        printf("Tabela Hash vazia ou nao inicializada.\n");
        return;
    }

    printf("--- ESTRUTURA DA TABELA HASH ---\n");
    for (int i = 0; i < h->tamanho; i++) {
        printf("Indice [%d]: ", i);
        no_t* atual = h->tabela[i];
        if (atual == NULL) {
            printf("NULL");
        } else {
            while (atual != NULL) {
                printf("%d -> ", atual->valor);
                atual = atual->proximo;
            }
            printf("NULL");
        }
        printf("\n");
    }
    printf("--------------------------------\n");
}

void hash_destruir(TabelaHash h) {
    if (h != NULL) {
        if (h->tabela != NULL) {
            for (int i = 0; i < h->tamanho; i++) {
                no_t* atual = h->tabela[i];
                while (atual != NULL) {
                    no_t* auxiliar = atual->proximo;
                    free(atual);
                    atual = auxiliar;
                }
            }
            free(h->tabela);
        }
        free(h);
    }
}