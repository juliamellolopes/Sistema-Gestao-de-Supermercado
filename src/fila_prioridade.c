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

    if (!fila->inicio) { // Caso a fila esteja vazia
        fila->inicio = fila->fim = cliente;
    } else { // Adiciona o cliente ao final da fila
        fila->fim->prox = cliente;
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
