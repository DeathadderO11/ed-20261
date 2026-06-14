#include <stdio.h>
#include "arvore_binaria.h"

void executar_testes_arvore() {
printf("=== TESTES DO TDA ARVORE BINARIA ===\n\n");

Arvore minha_arvore = arvore_criar();
if (minha_arvore == NULL) {
printf("Erro ao criar a arvore.\n");
return;
}
printf("Arvore criada com sucesso.\n");
printf("A arvore esta vazia? %s\n\n", arvore_esta_vazia(minha_arvore) ? "Sim" : "Nao");
printf("Inserindo os valores: 50, 30, 70, 20, 40, 60, 80...\n");
arvore_inserir(minha_arvore, 50);
arvore_inserir(minha_arvore, 30);
arvore_inserir(minha_arvore, 70);
arvore_inserir(minha_arvore, 20);
arvore_inserir(minha_arvore, 40);
arvore_inserir(minha_arvore, 60);
arvore_inserir(minha_arvore, 80);

printf("A arvore esta vazia? %s\n\n", arvore_esta_vazia(minha_arvore) ? "Sim" : "Nao");

printf("--- Exibicao dos Percursos ---\n");
arvore_exibir_pre_ordem(minha_arvore);
arvore_exibir_em_ordem(minha_arvore); // Exibe do menor para o maior valor

printf("\n");

// 4. Destruição da Árvore
printf("Liberando memoria alocada...\n");
arvore_destruir(minha_arvore);
printf("=== FIM DOS TESTES ===\n");
}

int main() {
executar_testes_arvore();

return 0;
}
