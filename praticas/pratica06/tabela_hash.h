#ifndef TABELA_HASH_H
#define TABELA_HASH_H
#include <stdbool.h>

typedef struct hash_t* TabelaHash;

TabelaHash hash_criar(int tamanho);
bool hash_inserir(TabelaHash h, int valor);
bool hash_buscar(TabelaHash h, int valor);
bool hash_remover(TabelaHash h, int valor);
void hash_exibir(TabelaHash h);
bool hash_esta_vazia(TabelaHash h);
void hash_destruir(TabelaHash h);

#endif