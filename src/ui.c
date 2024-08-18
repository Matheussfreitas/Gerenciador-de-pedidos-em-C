#include <stdio.h>
#include <stdlib.h>
#include "lista_ligada.h"
#include "fila.h"
#include "ui.h"
#include "cardapio.h"

// Função para exibir o menu e obter a escolha do usuário
int exibir_menu() {
    int opcao;

    printf("\nSistema de Gerenciamento de Pedidos\n");
    printf("1. Adicionar Pedido\n");
    printf("2. Remover Pedido\n");
    printf("3. Processar Pedido\n");
    printf("4. Listar Pedidos Pendentes\n");
    printf("5. Listar Pedidos em Processamento\n");
    printf("6. Sair\n");
    printf("Escolha uma opcao: ");
    scanf("%d", &opcao);

    return opcao;
}

// Função para lidar com a opção de adicionar um pedido usando o cardápio
void adicionar_pedido_ui(ListaLigada *lista) {
    exibir_cardapio();

    int categoria, opcao;
    printf("Escolha uma categoria (1: Entradas, 2: Pratos Principais, 3: Sobremesas): ");
    scanf("%d", &categoria);

    switch(categoria) {
        case 1:
            printf("Escolha uma entrada: ");
            scanf("%d", &opcao);
            if (opcao > 0 && opcao <= NUM_ENTRADAS) {
                adicionar_pedido(lista, entradas[opcao - 1]);
            } else {
                printf("Opção inválida.\n");
            }
            break;
        case 2:
            printf("Escolha um prato principal: ");
            scanf("%d", &opcao);
            if (opcao > 0 && opcao <= NUM_PRATOS_PRINCIPAIS) {
                adicionar_pedido(lista, pratos_principais[opcao - 1]);
            } else {
                printf("Opção inválida.\n");
            }
            break;
        case 3:
            printf("Escolha uma sobremesa: ");
            scanf("%d", &opcao);
            if (opcao > 0 && opcao <= NUM_SOBREMESAS) {
                adicionar_pedido(lista, sobremesas[opcao - 1]);
            } else {
                printf("Opção inválida.\n");
            }
            break;
        default:
            printf("Categoria inválida.\n");
    }
}

// Função para lidar com a opção de remover um pedido
void remover_pedido_ui(ListaLigada *lista) {
    char prato[MAX_PRATO];
    printf("Digite o nome do prato para remover: ");
    scanf(" %[^\n]", prato);
    remover_pedido(lista, prato);
}

// Função para lidar com a opção de processar um pedido
void processar_pedido_ui(ListaLigada *lista, Fila *fila) {
    if (lista->inicio != NULL) {
        Pedido *pedido = lista->inicio;
        enfileirar(fila, pedido->prato);
        remover_pedido(lista, pedido->prato);
    } else {
        printf("Nenhum pedido pendente para processar.\n");
    }
}

// Função para listar os pedidos pendentes
void listar_pedidos_pendentes_ui(ListaLigada *lista) {
    listar_pedidos_pendentes(lista);
}

// Função para listar os pedidos em processamento
void listar_pedidos_em_processamento_ui(Fila *fila) {
    listar_fila(fila);
}

// Função principal da interface do usuário
void executar_sistema() {
    ListaLigada lista;
    Fila fila;

    inicializar_lista(&lista);
    inicializar_fila(&fila);

    int opcao;
    do {
        opcao = exibir_menu();
        switch(opcao) {
            case 1:
                adicionar_pedido_ui(&lista);
                break;
            case 2:
                remover_pedido_ui(&lista);
                break;
            case 3:
                processar_pedido_ui(&lista, &fila);
                break;
            case 4:
                listar_pedidos_pendentes_ui(&lista);
                break;
            case 5:
                listar_pedidos_em_processamento_ui(&fila);
                break;
            case 6:
                printf("Saindo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while(opcao != 6);

    limpar_lista(&lista);
    limpar_fila(&fila);
}