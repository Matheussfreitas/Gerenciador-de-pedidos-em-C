# Sistema de Gerenciamento de Pedidos de Restaurante


## Autores:

- Gabriel Fontineli Dantas
- Matheus Freitas
## Descrição

Este projeto é um sistema simples de gerenciamento de pedidos para um restaurante, implementado na linguagem C. O sistema permite que os pedidos sejam armazenados em uma lista ligada e processados em ordem de chegada utilizando uma fila. As principais funcionalidades incluem adicionar, remover e processar pedidos, além de listar pedidos pendentes e em processamento.

## Funcionalidades

- **Adicionar Pedido**: Permite adicionar um novo pedido à lista de pedidos pendentes.
- **Remover Pedido**: Permite remover um prato específico da lista de pedidos.
- **Processar Pedido**: Transfere o pedido mais antigo da lista pendente para a fila de processamento.
- **Listar Pedidos Pendentes**: Exibe todos os pedidos atualmente na lista ligada.
- **Listar Pedidos em Processamento**: Exibe todos os pedidos na fila de processamento.
- **Exibir Cardápio**: Mostra o cardápio do restaurante, incluindo entradas, pratos principais e sobremesas.

```
/projeto_gerenciamento_pedidos
│
├── src/
│   ├── main.c              
│   ├── ui.c                
│   ├── lista_ligada.c      
│   ├── fila.c              
│   └── cardapio.c          
│
├── include/
│   ├── lista_ligada.h      
│   ├── fila.h              
│   ├── ui.h                
│   ├── cardapio.h          
│   └── pedido.h            
│
├── build/                  
│
├── Makefile                
└── README.md               

```
## Como Compilar

Este projeto utiliza um `Makefile` para facilitar a compilação. Para compilar o projeto, siga os passos abaixo:

1. **Abra o terminal** e navegue até o diretório do projeto.
2. Execute o comando `make` para compilar o projeto:

    ```bash
    make
    ```

3. O executável será gerado na pasta `build` com o nome `gerenciamento_pedidos`.

## Como Executar

Após a compilação, execute o programa com o comando:

```bash
./build/gerenciamento_pedidos
```
Uso do Sistema

Ao iniciar o programa, um menu será exibido com as seguintes opções:

	1.	Adicionar Pedido: Adicione um novo pedido selecionando itens do cardápio.
	2.	Remover Pedido: Remova um pedido específico da lista de pedidos pendentes.
	3.	Processar Pedido: Transfira o pedido mais antigo da lista pendente para a fila de processamento.
	4.	Listar Pedidos Pendentes: Veja todos os pedidos que ainda não foram processados.
	5.	Listar Pedidos em Processamento: Veja todos os pedidos que estão sendo processados.
	6.	Sair: Encerra o programa.

Estrutura de Dados Utilizada

	•	Lista Ligada: Utilizada para armazenar os pedidos pendentes, permitindo inserção e remoção de pratos específicos.
	•	Fila: Utilizada para processar os pedidos em ordem de chegada (FIFO - First In, First Out).

Considerações

	•	O sistema lida corretamente com tentativas de remoção de pratos que não existem na lista ligada.
	•	O código está modularizado e bem documentado para facilitar a manutenção e a expansão futura.