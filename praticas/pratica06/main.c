#include <stdio.h>
#include "tabela_hash.h"

void executar_testes_hash() {
    printf("=== INICIANDO TESTES DA TABELA HASH ===\n\n");

    int tamanho_tabela = 5;
    TabelaHash minha_tabela = hash_criar(tamanho_tabela);
    if (minha_tabela == NULL) {
        printf("Falha ao alocar a Tabela Hash.\n");
        return;
    }
    printf("Tabela Hash criada com %d indices.\n", tamanho_tabela);
    printf("A tabela esta vazia? %s\n\n", hash_esta_vazia(minha_tabela) ? "Sim" : "Nao");
    printf("Inserindo valores: 5, 6, 11, 10, 14, 23...\n");
    hash_inserir(minha_tabela, 5);
    hash_inserir(minha_tabela, 6);
    hash_inserir(minha_tabela, 11);
    hash_inserir(minha_tabela, 10);
    hash_inserir(minha_tabela, 14);
    hash_inserir(minha_tabela, 23);
    hash_exibir(minha_tabela);
    printf("A tabela esta vazia? %s\n\n", hash_esta_vazia(minha_tabela) ? "Sim" : "Nao");

    int busca_existente = 11;
    int busca_inexistente = 99;

    printf("Buscando o valor %d: %s\n", busca_existente, hash_buscar(minha_tabela, busca_existente) ? "Encontrado" : "Nao encontrado");
    printf("Buscando o valor %d: %s\n\n", busca_inexistente, hash_buscar(minha_tabela, busca_inexistente) ? "Encontrado" : "Nao encontrado");
    printf("Removendo o valor 11 (meio da lista do Indice 1)...\n");

    hash_remover(minha_tabela, 11);
    hash_exibir(minha_tabela);
    hash_remover(minha_tabela, 10);
    hash_exibir(minha_tabela);

    printf("Tentando remover um valor nao existente (99)...\n");
    if (!hash_remover(minha_tabela, 99)) {
        printf("Remocao falhou: valor 99 nao consta na tabela.\n\n");
    }

    printf("Destruindo a tabela hash...\n");
    hash_destruir(minha_tabela);
    printf("=== FIM DOS TESTES ===\n");
}

int main() {
    executar_testes_hash();
    
    return 0;
}