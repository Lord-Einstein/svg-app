# Compilateur et options
CC = gcc
CFLAGS = -Wall -Wextra -std=c99

# Dossier des binaires et objets
BIN_DIR = bin

# Nom de l'exécutable
TARGET = $(BIN_DIR)/app

# Tous les fichiers .c du répertoire courant et des sous-dossiers
SRCS = $(shell find . -name '*.c')

# Fichiers objets correspondants dans bin/
OBJS = $(patsubst ./%.c, $(BIN_DIR)/%.o, $(SRCS))

# Création du dossier bin si nécessaire
$(BIN_DIR):
	@mkdir -p $(BIN_DIR)

# Règle par défaut
all: $(BIN_DIR) $(TARGET)

# Linker les objets pour créer l'exécutable
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $^

# Compiler chaque fichier .c en .o dans bin/ en recréant les sous-dossiers
$(BIN_DIR)/%.o: %.c | $(BIN_DIR)
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

# Nettoyer tous les fichiers compilés
clean:
	rm -rf $(BIN_DIR)

# Exécuter l'application
run: all
	./$(TARGET)

#Voir les fuites de mémoire et les mallocs non free.
vg:
	valgrind --leak-check=full --show-reachable=no ./bin/app
	
# Pour ne pas confondre avec des fichiers
.PHONY: all clean run vg
