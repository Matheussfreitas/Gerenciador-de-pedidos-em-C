#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista_ligada.h"

// Função para inicializar a lista ligada
void inicializar_lista(ListaLigada *lista) {
    lista->inicio = NULL;
}

// Função para adicionar um novo pedido à lista ligada
void adicionar_pedido(ListaLigada *lista, const char *prato) {
    Pedido *novo_pedido = (Pedido *)malloc(sizeof(Pedido));
    if (novo_pedido == NULL) {
        printf("Erro ao alocar memória para novo pedido.\n");
        exit(1);
    }
    strcpy(novo_pedido->prato, prato);
    novo_pedido->proximo = NULL;

    if (lista->inicio == NULL) {
        lista->inicio = novo_pedido;
    } else {
        Pedido *temp = lista->inicio;
        while (temp->proximo != NULL) {
            temp = temp->proximo;
        }
        temp->proximo = novo_pedido;
    }
    printf("Pedido '%s' adicionado com sucesso!\n", prato);
}

// Função para remover um pedido específico da lista ligada
void remover_pedido(ListaLigada *lista, const char *prato) {
    Pedido *temp = lista->inicio;
    Pedido *anterior = NULL;

    while (temp != NULL && strcmp(temp->prato, prato) != 0) {
        anterior = temp;
        temp = temp->proximo;
    }

    if (temp == NULL) {
        printf("Pedido '%s' não encontrado na lista.\n", prato);
        return;
    }

    if (anterior == NULL) {
        lista->inicio = temp->proximo;
    } else {
        anterior->proximo = temp->proximo;
    }

    free(temp);
    printf("Pedido '%s' removido com sucesso!\n", prato);
}

// Função para listar todos os pedidos pendentes na lista ligada
void listar_pedidos_pendentes(ListaLigada *lista) {
    Pedido *temp = lista->inicio;
    if (temp == NULL) {
        printf("Nenhum pedido pendente.\n");
        return;
    }

    printf("Pedidos pendentes:\n");
    while (temp != NULL) {
        printf("- %s\n", temp->prato);
        temp = temp->proximo;
    }
}

// Função para limpar toda a lista ligada (liberar memória)
void limpar_lista(ListaLigada *lista) {
    Pedido *temp = lista->inicio;
    while (temp != NULL) {
        Pedido *proximo = temp->proximo;
        free(temp);
        temp = proximo;
    }
    lista->inicio = NULL;
}