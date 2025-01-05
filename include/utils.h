#ifndef UTILS_H
#define UTILS_H

#include <stdio.h>
#include <string.h>
#include <ctype.h>

// Declaração da função para validar o nome do cliente.
int validar_nome(const char *nome);

// Declaração da função para validar o CPF do cliente.
int validar_cpf(const char *cpf);

// Declaração da função para validar a prioridade do cliente.
int validar_prioridade(int prioridade);

// Declaração da função para validar o número de itens no carrinho.
int validar_num_itens(int num_itens);

#endif
