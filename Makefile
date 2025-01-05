# Compilador e flags
CC = gcc
CFLAGS = -Iinclude -Wall

# Diretórios de código-fonte e destino dos binários
SRC_DIR = src
OBJ_DIR = obj
BIN_DIR = bin

# Arquivos fontes
SRC = $(wildcard $(SRC_DIR)/*.c)

# Arquivos objeto
OBJ = $(SRC:$(SRC_DIR)/%.c=$(OBJ_DIR)/%.o)

# Nome do executável
TARGET = $(BIN_DIR)/supermercado

# Cria diretórios se não existirem
$(OBJ_DIR):
	mkdir -p $(OBJ_DIR)

$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# Regra padrão para compilar o projeto
all: $(OBJ_DIR) $(BIN_DIR) $(TARGET)

# Linkagem final
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) -o $@ $^

# Compilação dos arquivos .c para .o
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c | $(OBJ_DIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza dos arquivos compilados
clean:
	rm -rf $(OBJ_DIR) $(BIN_DIR)

# Regra para rodar o sistema
run: all
	./$(TARGET)

c: clean all run

r: all run
