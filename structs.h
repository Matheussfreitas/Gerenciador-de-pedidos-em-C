#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Prato {
    char nome[50];
    struct Prato *proximo;
} Prato;

typedef struct Pedido {
    int id;
    Prato *pratos;
    struct Pedido *proximo;
} Pedido;

typedef struct ListaPedidos {
    Pedido *primeiro;
} ListaPedidos;

typedef struct FilaNode {
    Pedido *pedido;
    struct FilaNode *proximo;
} FilaNode;

typedef struct FilaPedidos {
    FilaNode *frente;
    FilaNode *tras;
} FilaPedidos;

#endif
