#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "cliente.h"
#include "caixa.h"
#include "fila_prioridade.h"
#include "utils.h"

#define NUM_CAIXAS 5

void menu() {
    printf("\nSistema de Gestao de Filas\n");
    printf("1. Cadastrar Cliente\n");
    printf("2. Atender Cliente\n");
    printf("3. Abrir Caixa\n");
    printf("4. Fechar Caixa\n");
    printf("5. Imprimir Lista de Clientes\n");
    printf("6. Imprimir Status dos Caixas\n");
    printf("0. Sair\n");
    printf("Escolha uma opcao: ");
}

int main() {
    Caixa *caixas[NUM_CAIXAS];
    for (int i = 0; i < NUM_CAIXAS; i++) {
        caixas[i] = criar_caixa(i + 1);
    }

    int opcao;
    do {
        menu();
        scanf("%d", &opcao);

        switch (opcao) {
        case 1: {
            char nome[100], cpf[12];
            int prioridade, num_itens, caixa_id;

            // Validação do Nome
            do {
                printf("Nome: ");
                scanf(" %[^\n]", nome); // Permite leitura de strings com espaços
                if (!validar_nome(nome)) {
                    printf("Nome invalido. Tente novamente.\n");
                }
            } while (!validar_nome(nome));

            // Validação do CPF
            do {
                printf("CPF: ");
                scanf("%s", cpf);
                if (!validar_cpf(cpf)) {
                    printf("CPF invalido. Tente novamente.\n");
                }
            } while (!validar_cpf(cpf));

            // Validação da Prioridade
            do {
                printf("Prioridade (1: Alta, 2: Madia, 3: Baixa): ");
                scanf("%d", &prioridade);
                if (!validar_prioridade(prioridade)) {
                    printf("Prioridade invalida. Tente novamente.\n");
                }
            } while (!validar_prioridade(prioridade));

            // Validação do Número de Itens
            do {
                printf("Numero de itens no carrinho: ");
                scanf("%d", &num_itens);
                if (!validar_num_itens(num_itens)) {
                    printf("Numero de itens invalido. Tente novamente.\n");
                }
            } while (!validar_num_itens(num_itens));

            // Validação do Caixa
            do {
                printf("Caixa (1-%d): ", NUM_CAIXAS);
                scanf("%d", &caixa_id);
                if (caixa_id < 1 || caixa_id > NUM_CAIXAS) {
                    printf("Caixa invalido. Tente novamente.\n");
                }
            } while (caixa_id < 1 || caixa_id > NUM_CAIXAS);

            // Cadastro do Cliente
            Cliente *cliente = criar_cliente(nome, cpf, prioridade, num_itens);
            enfileirar(caixas[caixa_id - 1]->fila, cliente);
            printf("Cliente cadastrado com sucesso no caixa %d.\n", caixa_id);
            break;
        }
        case 2: {
            int caixa_id;
            printf("Caixa para atendimento (1-%d): ", NUM_CAIXAS);
            scanf("%d", &caixa_id);
            if (caixa_id >= 1 && caixa_id <= NUM_CAIXAS) {
                Cliente *cliente = desenfileirar(caixas[caixa_id - 1]->fila);
                if (cliente) {
                    printf("Cliente atendido:\n");
                    imprimir_cliente(cliente);
                    free(cliente);
                } else {
                    printf("Nenhum cliente na fila do caixa %d.\n", caixa_id);
                }
            } else {
                printf("Erro: Caixa invalido!\n");
            }
            break;
        }
        case 3: {
            int caixa_id;
            printf("Abrir caixa (1-%d): ", NUM_CAIXAS);
            scanf("%d", &caixa_id);
            if (caixa_id >= 1 && caixa_id <= NUM_CAIXAS) {
                abrir_caixa(caixas[caixa_id - 1]);
                printf("Caixa %d aberto.\n", caixa_id);
            } else {
                printf("Erro: Caixa invalido!\n");
            }
            break;
        }
        case 4: {
            int caixa_id;
            printf("Fechar caixa (1-%d): ", NUM_CAIXAS);
            scanf("%d", &caixa_id);
            if (caixa_id >= 1 && caixa_id <= NUM_CAIXAS) {
                fechar_caixa(caixas[caixa_id - 1], caixas, NUM_CAIXAS);
                printf("Caixa %d fechado.\n", caixa_id);
            } else {
                printf("Erro: Caixa invalido!\n");
            }
            break;
        }
        case 5: {
            for (int i = 0; i < NUM_CAIXAS; i++) {
                imprimir_caixa(caixas[i]);
            }
            break;
        }
        case 6: {
            printf("Status dos caixas:\n");
            for (int i = 0; i < NUM_CAIXAS; i++) {
                printf("Caixa %d: %s\n", caixas[i]->id, caixas[i]->aberto ? "Aberto" : "Fechado");
            }
            break;
        }
        case 0:
            printf("Encerrando o sistema...\n");
            break;
        default:
            printf("Erro: Opcao invalida!\n");
            break;
        }
    } while (opcao != 0);

    for (int i = 0; i < NUM_CAIXAS; i++) {
        free(caixas[i]->fila);
        free(caixas[i]);
    }

    return 0;
}
