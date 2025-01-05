#include <stdio.h>
#include <string.h>
#include <ctype.h>
#include "utils.h"

// Função para validar o nome.
// Verifica se o nome tem entre 1 e 100 caracteres.
int validar_nome(const char *nome) {
    if (strlen(nome) == 0 || strlen(nome) > 100) {
        printf("Erro: Nome deve ter entre 1 e 100 caracteres.\n");
        return 0;
    }
    return 1;
}

// Função para validar o CPF.
// Verifica se o CPF tem exatamente 11 dígitos numéricos.
int validar_cpf(const char *cpf) {
    if (strlen(cpf) != 11) {
        printf("Erro: CPF deve conter exatamente 11 digitos.\n");
        return 0;
    }
    for (int i = 0; i < 11; i++) {
        if (!isdigit(cpf[i])) {
            printf("Erro: CPF deve conter apenas numeros.\n");
            return 0;
        }
    }
    return 1;
}

// Função para validar a prioridade.
// Verifica se a prioridade é 1 (alta), 2 (média) ou 3 (baixa).
int validar_prioridade(int prioridade) {
    if (prioridade < 1 || prioridade > 3) {
        printf("Erro: Prioridade deve ser 1 (alta), 2 (media) ou 3 (baixa).\n");
        return 0;
    }
    return 1;
}

// Função para validar o número de itens no carrinho.
// Verifica se o número é maior ou igual a zero.
int validar_num_itens(int num_itens) {
    if (num_itens < 0) {
        printf("Erro: O numero de itens no carrinho deve ser maior ou igual a 0.\n");
        return 0;
    }
    return 1;
}
