#include <stdio.h>
#include "cardapio.h"

const char *entradas[NUM_ENTRADAS] = {
    "Sopa de Cebola",
    "Salada Caesar",
    "Bruschetta",
    "Carpaccio de Carne",
    "Camarao ao Alho"
};

const char *pratos_principais[NUM_PRATOS_PRINCIPAIS] = {
    "Lasanha a Bolonhesa",
    "File Mignon com Fritas",
    "Frango Grelhado com Legumes",
    "Bacalhau a Gomes de Sa",
    "Risoto de Cogumelos"
};

const char *sobremesas[NUM_SOBREMESAS] = {
    "Tiramisu",
    "Cheesecake de Frutas Vermelhas",
    "Mousse de Chocolate",
    "Pudim de Leite",
    "Sorvete de Baunilha com Calda de Morango"
};

// Função para exibir o cardápio
void exibir_cardapio() {
    printf("\n--- Cardápio ---\n");

    printf("Entradas:\n");
    for (int i = 0; i < NUM_ENTRADAS; i++) {
        printf("%d. %s\n", i + 1, entradas[i]);
    }

    printf("\nPratos Principais:\n");
    for (int i = 0; i < NUM_PRATOS_PRINCIPAIS; i++) {
        printf("%d. %s\n", i + 1, pratos_principais[i]);
    }

    printf("\nSobremesas:\n");
    for (int i = 0; i < NUM_SOBREMESAS; i++) {
        printf("%d. %s\n", i + 1, sobremesas[i]);
    }
    printf("----------------\n");
}