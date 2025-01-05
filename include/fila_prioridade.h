#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include "cliente.h"

// Estrutura para gerenciar filas de clientes com prioridade
typedef struct FilaPrioridade {
    Cliente *inicio;            // Ponteiro para o início da fila
    Cliente *fim;               // Ponteiro para o final da fila
} FilaPrioridade;

// Função para criar uma nova fila
FilaPrioridade *criar_fila();

// Função para adicionar um cliente à fila, mantendo a prioridade
void enfileirar(FilaPrioridade *fila, Cliente *cliente);

// Função para remover o cliente de maior prioridade da fila
Cliente *desenfileirar(FilaPrioridade *fila);

// Função para imprimir os clientes na fila
void imprimir_fila(const FilaPrioridade *fila);

#endif
