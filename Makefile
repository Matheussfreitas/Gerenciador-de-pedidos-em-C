# Compilador e flags
CC = gcc
CFLAGS = -Iinclude -Wall -g

# Diretórios
SRC_DIR = src
BUILD_DIR = build

# Arquivos fonte e objetos
SRCS = $(SRC_DIR)/main.c $(SRC_DIR)/ui.c $(SRC_DIR)/lista_ligada.c $(SRC_DIR)/fila.c $(SRC_DIR)/cardapio.c
OBJS = $(BUILD_DIR)/main.o $(BUILD_DIR)/ui.o $(BUILD_DIR)/lista_ligada.o $(BUILD_DIR)/fila.o $(BUILD_DIR)/cardapio.o

# Nome do executável
TARGET = $(BUILD_DIR)/gerenciamento_pedidos

# Regras de construção
all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos objetos e executável
clean:
	rm -f $(BUILD_DIR)/*.o $(TARGET)