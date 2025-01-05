#include <stdio.h>
#include <stdlib.h>
#include "caixa.h"

// Cria um novo caixa com um ID específico
Caixa *criar_caixa(int id) {
    Caixa *novo = (Caixa *)malloc(sizeof(Caixa));
    if (!novo) {
        perror("Erro ao alocar memória para caixa");
        return NULL;
    }
    novo->id = id;
    novo->aberto = 1;
    novo->fila = criar_fila();
    return novo;
}

// Define o estado do caixa como aberto
void abrir_caixa(Caixa *caixa) {
    if (caixa) caixa->aberto = 1;
}

// Fecha um caixa e realoca seus clientes para caixas abertos
void fechar_caixa(Caixa *caixa, Caixa *caixas[], int num_caixas) {
    if (!caixa || !caixa->aberto) return;

    caixa->aberto = 0;
    realocar_clientes(caixa->fila, caixas, num_caixas);
}

// Função para realocar os clientes caso o caixa seja fechado
void realocar_clientes(FilaPrioridade *fila_origem, Caixa *caixas[], int num_caixas) {
    Cliente *cliente = NULL;
    while ((cliente = desenfileirar(fila_origem)) != NULL) {
        for (int i = 0; i < num_caixas; i++) {
            if (caixas[i]->aberto) {
                enfileirar(caixas[i]->fila, cliente);
                break;
            }
        }
    }
}

// Imprime o estado do caixa e sua fila
void imprimir_caixa(const Caixa *caixa) {
    printf("Caixa %d: %s\n", caixa->id, caixa->aberto ? "Aberto" : "Fechado");
    printf("Clientes na fila:\n");
    imprimir_fila(caixa->fila);
}
