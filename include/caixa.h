#ifndef CAIXA_H
#define CAIXA_H

#include "fila_prioridade.h"

typedef struct Caixa {
    int id;                         // Número de identificação do caixa
    int aberto;                     // Estado do caixa (1: Aberto, 0: Fechado)
    FilaPrioridade *fila;           // Ponteiro para a fila de clientes do caixa
} Caixa;

// Função para criar um novo caixa
Caixa *criar_caixa(int id);

// Função para abrir um caixa
void abrir_caixa(Caixa *caixa);

// Função para fechar um caixa e realocar seus clientes
void fechar_caixa(Caixa *caixa, Caixa *caixas[], int num_caixas);

// Função para imprimir o estado de um caixa
void imprimir_caixa(const Caixa *caixa);

// Função para realocar os clientes caso o caixa seja fechado
void realocar_clientes(FilaPrioridade *fila_origem, Caixa *caixas[], int num_caixas);

#endif
