#ifndef UI_H
#define UI_H

#include "lista_ligada.h"
#include "fila.h"

int exibir_menu();
void adicionar_pedido_ui(ListaLigada *lista);
void remover_pedido_ui(ListaLigada *lista);
void processar_pedido_ui(ListaLigada *lista, Fila *fila);
void listar_pedidos_pendentes_ui(ListaLigada *lista);
void listar_pedidos_em_processamento_ui(Fila *fila);
void executar_sistema();

#endif // UI_H