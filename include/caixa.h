#ifndef CAIXA_H
#define CAIXA_H

#include "fila_prioridade.h"

typedef struct Caixa {
    int id;
    int aberto; // 1: Aberto, 0: Fechado
    FilaPrioridade *fila;
} Caixa;

Caixa *criar_caixa(int id);
void abrir_caixa(Caixa *caixa);
void fechar_caixa(Caixa *caixa, Caixa *caixas[], int num_caixas);
void imprimir_caixa(const Caixa *caixa);
void realocar_clientes(FilaPrioridade *fila_origem, Caixa *caixas[], int num_caixas);

#endif
