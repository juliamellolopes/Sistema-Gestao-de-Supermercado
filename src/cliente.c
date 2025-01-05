#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"

// Cria um novo cliente com os dados fornecidos
Cliente *criar_cliente(const char *nome, const char *cpf, int prioridade, int num_itens) {
    Cliente *novo = (Cliente *)malloc(sizeof(Cliente));
    if (!novo) {
        perror("Erro ao alocar memória para cliente");
        return NULL;
    }
    strncpy(novo->nome, nome, 100);
    strncpy(novo->cpf, cpf, 12);
    novo->prioridade = prioridade;
    novo->num_itens = num_itens;
    novo->prox = NULL;
    return novo;
}

// Exibe os dados de um cliente na saída padrão
void imprimir_cliente(const Cliente *cliente) {
    if (cliente) {
        printf("Nome: %s\nCPF: %s\nPrioridade: %d\nItens no carrinho: %d\n",
            cliente->nome, cliente->cpf, cliente->prioridade, cliente->num_itens);
    }
}
