#include <stdio.h>
#include "lista_linear.h"

void executar_testes() {
    printf("--- Iniciando testes da Lista Linear ---\n\n");

    Lista minha_lista = lista_criar();
    if (minha_lista == NULL) {
        printf("Erro ao criar a lista.\n");
        return;
    }
    
    printf("Lista criada com sucesso.\n");
    lista_exibir(minha_lista);
    printf("A lista esta vazia? %s\n\n", lista_esta_vazia(minha_lista) ? "Sim" : "Nao");

    printf("Inserindo valores: 10, 20, 30, 40...\n");
    lista_inserir(minha_lista, 10);
    lista_inserir(minha_lista, 20);
    lista_inserir(minha_lista, 30);
    lista_inserir(minha_lista, 40);
    lista_exibir(minha_lista);
    printf("\n");

    int valor_busca_1 = 30;
    int valor_busca_2 = 50;
    
    printf("Buscando valor %d: %s\n", valor_busca_1, lista_buscar(minha_lista, valor_busca_1) ? "Encontrado" : "Nao encontrado");
    printf("Buscando valor %d: %s\n\n", valor_busca_2, lista_buscar(minha_lista, valor_busca_2) ? "Encontrado" : "Nao encontrado");
    printf("Removendo o valor 20...\n");
    lista_remover(minha_lista, 20);
    lista_exibir(minha_lista);
    
    printf("Removendo o valor 10 (primeiro)...\n");
    lista_remover(minha_lista, 10);
    lista_exibir(minha_lista);

    printf("Removendo o valor 40 (ultimo)...\n");
    lista_remover(minha_lista, 40);
    lista_exibir(minha_lista);
    printf("\n");
    printf("Destruindo a lista...\n");
    lista_destruir(minha_lista);
    printf("--- Testes finalizados ---\n");
}

int main() {
    executar_testes();
    
    return 0;
}
