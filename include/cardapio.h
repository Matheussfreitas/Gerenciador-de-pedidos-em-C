#ifndef CARDAPIO_H
#define CARDAPIO_H

#define NUM_ENTRADAS 5
#define NUM_PRATOS_PRINCIPAIS 5
#define NUM_SOBREMESAS 5

extern const char *entradas[NUM_ENTRADAS];
extern const char *pratos_principais[NUM_PRATOS_PRINCIPAIS];
extern const char *sobremesas[NUM_SOBREMESAS];

void exibir_cardapio();

#endif // CARDAPIO_H