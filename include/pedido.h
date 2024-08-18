#ifndef PEDIDO_H
#define PEDIDO_H

#define MAX_PRATO 50

typedef struct Pedido {
    char prato[MAX_PRATO];
    struct Pedido *proximo;
} Pedido;

#endif // PEDIDO_H