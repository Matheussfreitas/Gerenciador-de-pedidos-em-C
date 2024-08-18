#ifndef LISTA_LIGADA_H
#define LISTA_LIGADA_H

#include "pedido.h"

typedef struct {
    Pedido *inicio;
} ListaLigada;

void inicializar_lista(ListaLigada *lista);
void adicionar_pedido(ListaLigada *lista, const char *prato);
void remover_pedido(ListaLigada *lista, const char *prato);
void listar_pedidos_pendentes(ListaLigada *lista);
void limpar_lista(ListaLigada *lista);

#endif // LISTA_LIGADA_H