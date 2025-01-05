#ifndef FILA_PRIORIDADE_H
#define FILA_PRIORIDADE_H

#include "cliente.h"

typedef struct FilaPrioridade {
    Cliente *inicio;
    Cliente *fim;
} FilaPrioridade;

FilaPrioridade *criar_fila();
void enfileirar(FilaPrioridade *fila, Cliente *cliente);
Cliente *desenfileirar(FilaPrioridade *fila);
void imprimir_fila(const FilaPrioridade *fila);

#endif
