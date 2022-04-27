CC := g++
EXE = Wordle
SHELL := /bin/bash
STD_VER := c++11

# Flags
LDFLAGS += -lpthread

# Directories
SRC_DIR	  := src
OBJ_DIR	  := obj
BUILD_DIR := build

# Source files
SRC_C_FILES	  := $(shell find $(SRC_DIR) -name *.c)
SRC_CPP_FILES := $(shell find $(SRC_DIR) -name *.cpp)
SRC_FILES 	  := $(SRC_C_FILES) $(SRC_CPP_FILES)

# Object Files
OBJ_FILES := $(patsubst $(SRC_DIR)%.c,$(OBJ_DIR)%.o,$(SRC_C_FILES))
OBJ_FILES += $(patsubst $(SRC_DIR)%.cpp,$(OBJ_DIR)%.o,$(SRC_CPP_FILES))

# Colors
RED      := \033[1;35m
CYAN     := \033[1;36m
GREEN    := \033[1;32m
ORANGE   := \033[1;33m
COLORTERM:= \033[0m

.PHONY: clean

default: .init $(EXE)
	

.init:
#	If directories don't exist make them
ifeq ("$(wildcard ./$(OBJ_DIR))", "")
	@mkdir -p ./$(OBJ_DIR)
endif
ifeq ("$(wildcard ./$(BUILD_DIR))", "")
	@mkdir -p ./$(BUILD_DIR)
endif

$(EXE): $(OBJ_FILES)
	@echo -e "$(GREEN)[100%] Linking $@$(COLORTERM)"
	@$(CC) -o $(BUILD_DIR)/$@ $^ $(LDFLAGS) -std=$(STD_VER) -g -O0

clean:
	rm -rf build obj

$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c*
#	If the output directory doesn't exist, make it
	@mkdir -p $(@D)
	@$(CC) $(CXXFLAGS) -c $^ -o $@ -std=$(STD_VER) -g -O0
