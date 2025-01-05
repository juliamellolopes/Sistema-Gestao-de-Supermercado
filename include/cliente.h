#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct Cliente {
    char nome[100];                   // Nome do cliente (máximo de 100 caracteres)
    char cpf[12];                     // CPF do cliente (11 dígitos + caractere nulo)
    int prioridade;                   // Prioridade do cliente (1: Alta, 2: Média, 3: Baixa)
    int num_itens;                    // Número de itens no carrinho
    struct Cliente *prox;             // Ponteiro para o próximo cliente na fila (lista encadeada)
} Cliente;

// Função para criar um novo cliente com os dados fornecidos
Cliente *criar_cliente(const char *nome, const char *cpf, int prioridade, int num_itens);

// Função para exibir os dados de um cliente
void imprimir_cliente(const Cliente *cliente);

#endif
