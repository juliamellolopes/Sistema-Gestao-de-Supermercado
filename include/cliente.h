#ifndef CLIENTE_H
#define CLIENTE_H

typedef struct Cliente {
    char nome[100];
    char cpf[12]; // 11 dígitos + terminador
    int prioridade; // 1: Alta, 2: Média, 3: Baixa
    int num_itens;
    struct Cliente *prox;
} Cliente;

Cliente *criar_cliente(const char *nome, const char *cpf, int prioridade, int num_itens);
void imprimir_cliente(const Cliente *cliente);

#endif
