#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

void menu() {
    printf("-------------------------\n");
    printf("1. Exibir Cardápio\n");
    printf("2. Adicionar Pedido\n");
    printf("3. Remover Prato de Pedido\n");
    printf("4. Processar Pedido\n");
    printf("5. Listar Pedidos Pendentes\n");
    printf("6. Listar Pedidos em Processamento\n");
    printf("7. Sair\n");
    printf("-------------------------\n");
}

int main() {
    ListaPedidos lista_pedidos = {NULL};
    FilaPedidos fila_pedidos = {NULL, NULL};
    int opcao, id, num_pratos;
    char nome_prato[50];

    while (1) {
        menu();
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                exibirCardapio();
                break;
            case 2:
                printf("ID do pedido: ");
                scanf("%d", &id);
                printf("Número de pratos: ");
                scanf("%d", &num_pratos);
                char (*pratos)[50] = malloc(num_pratos * sizeof(*pratos));
                for (int i = 0; i < num_pratos; ++i) {
                    printf("Nome do prato %d: ", i + 1);
                    scanf("%s", pratos[i]);
                }
                adicionarPedido(&lista_pedidos, id, pratos, num_pratos);
                free(pratos);
                break;
            case 3:
                printf("ID do pedido: ");
                scanf("%d", &id);
                printf("Nome do prato a remover: ");
                scanf("%s", nome_prato);
                removerPrato(&lista_pedidos, id, nome_prato);
                break;
            case 4:
                processarPedido(&lista_pedidos, &fila_pedidos);
                break;
            case 5:
                listarPedidosPendentes(&lista_pedidos);
                break;
            case 6:
                listarPedidosProcessamento(&fila_pedidos);
                break;
            case 7:
                exit(0);
            default:
                printf("Opção inválida.\n");
        }
    }
    return 0;
}
