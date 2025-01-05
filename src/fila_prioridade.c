#include <stdio.h>
#include <stdlib.h>
#include "fila_prioridade.h"

FilaPrioridade *criar_fila() {
    FilaPrioridade *fila = (FilaPrioridade *)malloc(sizeof(FilaPrioridade));
    if (!fila) {
        perror("Erro ao alocar memória para fila");
        return NULL;
    }
    fila->inicio = fila->fim = NULL;
    return fila;
}

void enfileirar(FilaPrioridade *fila, Cliente *cliente) {
    if (!fila || !cliente) return;

    if (!fila->inicio) {
        fila->inicio = fila->fim = cliente;
    } else {
        fila->fim->prox = cliente;
        fila->fim = cliente;
    }
}

Cliente *desenfileirar(FilaPrioridade *fila) {
    if (!fila || !fila->inicio) return NULL;

    Cliente *cliente = fila->inicio;
    fila->inicio = fila->inicio->prox;
    if (!fila->inicio) fila->fim = NULL;
    return cliente;
}

void imprimir_fila(const FilaPrioridade *fila) {
    Cliente *atual = fila->inicio;
    while (atual) {
        imprimir_cliente(atual);
        atual = atual->prox;
    }
}
