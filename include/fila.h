#ifndef FILA_H
#define FILA_H

#include "pedido.h"

typedef struct {
    Pedido *frente;
    Pedido *traseira;
} Fila;

void inicializar_fila(Fila *fila);
void enfileirar(Fila *fila, const char *prato);
void desenfileirar(Fila *fila);
void listar_fila(Fila *fila);
void limpar_fila(Fila *fila);

#endif // FILA_H