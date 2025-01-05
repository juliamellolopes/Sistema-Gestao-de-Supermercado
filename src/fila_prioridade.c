#include <stdio.h>
#include <stdlib.h>
#include "fila_prioridade.h"

// Cria uma nova fila de prioridade.
// Inicializa os ponteiros para início e fim como NULL.
FilaPrioridade *criar_fila() {
    FilaPrioridade *fila = (FilaPrioridade *)malloc(sizeof(FilaPrioridade));
    if (!fila) {
        perror("Erro ao alocar memória para fila");
        return NULL;
    }
    fila->inicio = fila->fim = NULL;
    return fila;
}

// Insere um cliente na fila.
// Adiciona o cliente no final da lista encadeada.
void enfileirar(FilaPrioridade *fila, Cliente *cliente) {
    if (!fila || !cliente) return;

    // Caso a fila esteja vazia, insere no início
    if (!fila->inicio) {
        fila->inicio = fila->fim = cliente;
        return;
    }

    // Caso o cliente tenha prioridade maior que o primeiro da fila (menor número)
    if (cliente->prioridade < fila->inicio->prioridade) {
        cliente->prox = fila->inicio;
        fila->inicio = cliente;
        return;
    }

    // Procura o local correto para inserir o cliente na fila
    Cliente *atual = fila->inicio;
    while (atual->prox && atual->prox->prioridade <= cliente->prioridade) {
        atual = atual->prox;
    }

    // Insere o cliente na posição encontrada
    cliente->prox = atual->prox;
    atual->prox = cliente;

    // Atualiza o final da fila, se necessário
    if (!cliente->prox) {
        fila->fim = cliente;
    }
}


// Remove o cliente de maior prioridade da fila (início).
Cliente *desenfileirar(FilaPrioridade *fila) {
    if (!fila || !fila->inicio) return NULL;

    Cliente *cliente = fila->inicio;       // Cliente no início da fila
    fila->inicio = fila->inicio->prox;     // Move o início para o próximo
    if (!fila->inicio) fila->fim = NULL;   // Caso a fila fique vazia
    return cliente;
}

// Imprime todos os clientes na fila.
// Percorre a lista encadeada exibindo os dados de cada cliente.
void imprimir_fila(const FilaPrioridade *fila) {
    Cliente *atual = fila->inicio;
    while (atual) {
        imprimir_cliente(atual);
        atual = atual->prox;
    }
}
