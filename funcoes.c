#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funcoes.h"

// Função para adicionar um novo prato a um pedido
void adicionarPrato(Pedido *pedido, const char *nome_prato) {
    Prato *novo_prato = (Prato *)malloc(sizeof(Prato));
    strcpy(novo_prato->nome, nome_prato);
    novo_prato->proximo = pedido->pratos;
    pedido->pratos = novo_prato;
}

// Função para adicionar um novo pedido à lista de pedidos pendentes
void adicionarPedido(ListaPedidos *lista, int id, char pratos[][50], int num_pratos) {
    Pedido *novo_pedido = (Pedido *)malloc(sizeof(Pedido));
    novo_pedido->id = id;
    novo_pedido->pratos = NULL;
    for (int i = 0; i < num_pratos; ++i) {
        adicionarPrato(novo_pedido, pratos[i]);
    }
    novo_pedido->proximo = lista->primeiro;
    lista->primeiro = novo_pedido;
}

// Função para remover um prato específico de um pedido
void removerPrato(ListaPedidos *lista, int id, const char *nome_prato) {
    Pedido *pedido_atual = lista->primeiro;
    while (pedido_atual != NULL && pedido_atual->id != id) {
        pedido_atual = pedido_atual->proximo;
    }
    if (pedido_atual == NULL) {
        printf("Pedido com ID %d não encontrado.\n", id);
        return;
    }
    Prato *prato_atual = pedido_atual->pratos;
    Prato *prato_anterior = NULL;
    while (prato_atual != NULL && strcmp(prato_atual->nome, nome_prato) != 0) {
        prato_anterior = prato_atual;
        prato_atual = prato_atual->proximo;
    }
    if (prato_atual == NULL) {
        printf("Prato %s não encontrado no pedido.\n", nome_prato);
        return;
    }
    if (prato_anterior == NULL) {
        pedido_atual->pratos = prato_atual->proximo;
    } else {
        prato_anterior->proximo = prato_atual->proximo;
    }
    free(prato_atual);
}

// Função para listar todos os pedidos pendentes
void listarPedidosPendentes(const ListaPedidos *lista) {
    Pedido *pedido_atual = lista->primeiro;
    while (pedido_atual != NULL) {
        printf("Pedido ID: %d\n", pedido_atual->id);
        Prato *prato_atual = pedido_atual->pratos;
        while (prato_atual != NULL) {
            printf(" - %s\n", prato_atual->nome);
            prato_atual = prato_atual->proximo;
        }
        pedido_atual = pedido_atual->proximo;
    }
}

// Função para processar um pedido da lista de pedidos pendentes para a fila de pedidos em processamento
void processarPedido(ListaPedidos *lista, FilaPedidos *fila) {
    if (lista->primeiro == NULL) {
        printf("Nenhum pedido pendente para processar.\n");
        return;
    }
    Pedido *pedido_a_processar = lista->primeiro;
    lista->primeiro = lista->primeiro->proximo;
    FilaNode *novo_node = (FilaNode *)malloc(sizeof(FilaNode));
    novo_node->pedido = pedido_a_processar;
    novo_node->proximo = NULL;
    if (fila->tras == NULL) {
        fila->frente = fila->tras = novo_node;
    } else {
        fila->tras->proximo = novo_node;
        fila->tras = novo_node;
    }
}

// Função para listar todos os pedidos em processamento
void listarPedidosProcessamento(const FilaPedidos *fila) {
    FilaNode *node_atual = fila->frente;
    while (node_atual != NULL) {
        printf("Pedido ID: %d\n", node_atual->pedido->id);
        Prato *prato_atual = node_atual->pedido->pratos;
        while (prato_atual != NULL) {
            printf(" - %s\n", prato_atual->nome);
            prato_atual = prato_atual->proximo;
        }
        node_atual = node_atual->proximo;
    }
}

// Função para exibir o cardápio
void exibirCardapio() {
    printf("Entradas:\n");
    printf("1. Sopa de Cebola\n");
    printf("2. Salada Caesar\n");
    printf("3. Bruschetta\n");
    printf("4. Carpaccio de Carne\n");
    printf("5. Camarão ao Alho\n");
    printf("\nPratos Principais:\n");
    printf("1. Lasanha à Bolonhesa\n");
    printf("2. Filé Mignon com Fritas\n");
    printf("3. Frango Grelhado com Legumes\n");
    printf("4. Bacalhau à Gomes de Sá\n");
    printf("5. Risoto de Cogumelos\n");
    printf("\nSobremesas:\n");
    printf("1. Tiramisu\n");
    printf("2. Cheesecake de Frutas Vermelhas\n");
    printf("3. Mousse de Chocolate\n");
    printf("4. Pudim de Leite\n");
    printf("5. Sorvete de Baunilha com Calda de Morango\n");
}
