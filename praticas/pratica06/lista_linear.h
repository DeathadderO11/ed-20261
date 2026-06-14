#ifndef LISTA_LINEAR_H
#define LISTA_LINEAR_H
#include <stdbool.h>

typedef struct lista_t* Lista;

Lista lista_criar();
bool lista_inserir(Lista l, int valor);
bool lista_remover(Lista l, int valor);
bool lista_buscar(Lista l, int valor);
void lista_exibir(Lista l);
bool lista_esta_vazia(Lista l);
void lista_destruir(Lista l);

#endif
