#include <stdio.h>
#include "pilha.h"

void rodar_testes_pilha() {
    printf("=== TESTES DO TDA PILHA ===\n\n");

    Pilha minha_pilha = pilha_criar();
    if (minha_pilha == NULL) {
        printf("Erro ao alocar memoria para a pilha.\n");
        return;
    }
    printf("Pilha criada com sucesso.\n");
    printf("A pilha esta vazia? %s\n\n", pilha_esta_vazia(minha_pilha) ? "Sim" : "Nao");
    printf("Empilhando valores: 10, 20, 30 e 40...\n");
    pilha_empilhar(minha_pilha, 10);
    pilha_empilhar(minha_pilha, 20);
    pilha_empilhar(minha_pilha, 30);
    pilha_empilhar(minha_pilha, 40);
    pilha_exibir(minha_pilha);
    printf("A pilha esta vazia? %s\n\n", pilha_esta_vazia(minha_pilha) ? "Sim" : "Nao");

    int valor;
    if (pilha_topo(minha_pilha, &valor)) {
        printf("Elemento no topo da pilha atual: %d\n\n", valor);
    }

    printf("Desempilhando dois elementos...\n");
    if (p_desempilhar(minha_pilha, &valor)) {
        printf("Removido do topo: %d\n", valor);
    }
    if (p_desempilhar(minha_pilha, &valor)) {
        printf("Removido do topo: %d\n", valor);
    }
    
    printf("\nEstado atual da pilha:\n");
    pilha_exibir(minha_pilha);
    
    if (pilha_topo(minha_pilha, &valor)) {
        printf("Novo elemento no topo: %d\n\n", valor);
    }

    printf("Liberando a memoria alocada para a pilha...\n");
    pilha_destruir(minha_pilha);
    printf("=== FIM DOS TESTES ===\n");
}

int main() {
    rodar_testes_pilha();
    
    return 0;
}
