#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "fila.h"

// Função para inicializar a fila
void inicializar_fila(Fila *fila) {
    fila->frente = NULL;
    fila->traseira = NULL;
}

// Função para enfileirar (adicionar) um pedido à fila
void enfileirar(Fila *fila, const char *prato) {
    Pedido *novo_pedido = (Pedido *)malloc(sizeof(Pedido));
    if (novo_pedido == NULL) {
        printf("Erro ao alocar memória para o pedido.\n");
        exit(1);
    }
    strcpy(novo_pedido->prato, prato);
    novo_pedido->proximo = NULL;

    if (fila->traseira == NULL) {
        fila->frente = fila->traseira = novo_pedido;
    } else {
        fila->traseira->proximo = novo_pedido;
        fila->traseira = novo_pedido;
    }
    printf("Pedido '%s' adicionado à fila de processamento!\n", prato);
}

// Função para desenfileirar (remover) um pedido da fila
void desenfileirar(Fila *fila) {
    if (fila->frente == NULL) {
        printf("Fila vazia, nenhum pedido para processar.\n");
        return;
    }

    Pedido *temp = fila->frente;
    fila->frente = fila->frente->proximo;

    if (fila->frente == NULL) {
        fila->traseira = NULL;
    }

    printf("Processando pedido: %s\n", temp->prato);
    free(temp);
}

// Função para listar todos os pedidos na fila de processamento
void listar_fila(Fila *fila) {
    Pedido *temp = fila->frente;
    if (temp == NULL) {
        printf("Nenhum pedido em processamento.\n");
        return;
    }

    printf("Pedidos em processamento:\n");
    while (temp != NULL) {
        printf("- %s\n", temp->prato);
        temp = temp->proximo;
    }
}

// Função para limpar toda a fila (liberar memória)
void limpar_fila(Fila *fila) {
    while (fila->frente != NULL) {
        desenfileirar(fila);
    }
}