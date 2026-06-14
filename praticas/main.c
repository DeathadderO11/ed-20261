#include <stdio.h>
#include "fila.h"

void rodar_testes_fila() {
printf("=== TESTES DO TDA FILA ===\n\n");

Fila minha_fila = fila_criar();
if (minha_fila == NULL) {
printf("Erro ao criar a fila.\n");
return;
}
printf("Fila criada com sucesso.\n");
printf("A fila esta vazia? %s\n\n", fila_esta_vazia(minha_fila) ? "Sim" : "Nao");
printf("Enfileirando os valores: 5, 15, 25 e 35...\n");
fila_enfileirar(minha_fila, 5);
fila_enfileirar(minha_fila, 15);
fila_enfileirar(minha_fila, 25);
fila_enfileirar(minha_fila, 35);

fila_exibir(minha_fila);
printf("A fila esta vazia? %s\n\n", fila_esta_vazia(minha_fila) ? "Sim" : "Nao");

int valor_topo;
if (fila_inicio(minha_fila, &valor_topo)) {
printf("Consultando sem remover - Elemento no inicio da fila: %d\n\n", valor_topo);
}
  
int valor_removido;
printf("Desenfileirando dois elementos...\n");

if (fila_desenfileirar(minha_fila, &valor_removido)) {
printf("Valor desenfileirado: %d\n", valor_removido);
}
if (fila_desenfileirar(minha_fila, &valor_removido)) {
printf("Valor desenfileirado: %d\n", valor_removido);
}

printf("\nEstado atual da fila:\n");
fila_exibir(minha_fila);

if (fila_inicio(minha_fila, &valor_topo)) {
printf("Novo elemento no inicio da fila: %d\n\n", valor_topo);
}

printf("Destruindo a fila e liberando a memoria...\n");
fila_destruir(minha_fila);

printf("=== FIM DOS TESTES ===\n");
}

int main() {
rodar_testes_fila();

return 0;
}
