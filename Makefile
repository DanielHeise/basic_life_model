# Directory Structure
# ===================
# root
# ├── bin/			(make created; executable)
# ├── obj/			(make created; build artifacts)
# ├── include/		(user created; .h files)
# ├── lib/			(user created; .a/.so files)
# ├── src/			(user created; .cpp files)
# └── Makefile

SRC_DIR := src
OBJ_DIR := obj
BIN_DIR := bin

TARGET = life

EXE := $(BIN_DIR)/$(TARGET)
SRC := $(wildcard $(SRC_DIR)/*.cpp)
OBJ := $(SRC:$(SRC_DIR)/%.cpp=$(OBJ_DIR)/%.o)

CC		  = g++
CPPFLAGS := -Iinclude -MMD -MP --std=c++17
CFLAGS   := -Wall
LDFLAGS  := -Llib
LDLIBS   := -lm

.PHONY: all clean

all: $(EXE)

$(EXE): $(OBJ) | $(BIN_DIR)
	$(CC) $(LDFLAGS) $^ $(LDLIBS) -o $@

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.cpp | $(OBJ_DIR)
	$(CC) $(CPPFLAGS) $(CFLAGS) -c $< -o $@

$(BIN_DIR) $(OBJ_DIR):
	mkdir -p $@

clean:
	@$(RM) -rv $(BIN_DIR) $(OBJ_DIR)

-include $(OBJ:.o=.d)