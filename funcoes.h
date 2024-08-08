#ifndef FUNCOES_H
#define FUNCOES_H

#include "structs.h"

// Funções para pedidos pendentes
void adicionarPedido(ListaPedidos *lista, int id, char pratos[][50], int num_pratos);
void removerPrato(ListaPedidos *lista, int id, const char *nome_prato);
void listarPedidosPendentes(const ListaPedidos *lista);

// Funções para pedidos em processamento
void processarPedido(ListaPedidos *lista, FilaPedidos *fila);
void listarPedidosProcessamento(const FilaPedidos *fila);

// Função para exibir o cardápio
void exibirCardapio();

#endif
