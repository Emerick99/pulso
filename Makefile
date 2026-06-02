# ==============================================================================
# Makefile simple — Issue #34
# Compilación sin CMake para entornos ligeros
# ==============================================================================

CXX     ?= g++
CXXFLAGS = -std=c++17 -Wall -Wextra -Wpedantic -O2

SRC_DIR  = src
TEST_DIR = tests
BUILD_DIR = build_local

# Recopilar fuentes automáticamente
SRCS     = $(wildcard $(SRC_DIR)/*.cpp)
OBJS     = $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

TEST_SRCS = $(wildcard $(TEST_DIR)/*.cpp)
TEST_OBJS = $(patsubst $(TEST_DIR)/%.cpp, $(BUILD_DIR)/test_%.o, $(TEST_SRCS))

TARGET      = $(BUILD_DIR)/app
TEST_TARGET = $(BUILD_DIR)/run_tests

# ------------------------------------------------------------------------------
# Target por defecto
# ------------------------------------------------------------------------------
.PHONY: all build test clean format run help
all: build

$(TARGET): $(OBJS) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compilar cada .cpp → .o solo si hubo cambios (regla implícita con prereqs)
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) -c $< -o $@

# ------------------------------------------------------------------------------
# Tests
# ------------------------------------------------------------------------------
.PHONY: test
test:
	cd build && ctest --output-on-failure

# ------------------------------------------------------------------------------
# Directorio de build
# ------------------------------------------------------------------------------
$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

# ------------------------------------------------------------------------------
# Limpieza
# ------------------------------------------------------------------------------
.PHONY: clean
clean:
	rm -rf build/ $(BUILD_DIR)

# ------------------------------------------------------------------------------
# Build con CMake
# ------------------------------------------------------------------------------
.PHONY: build
build:
	cmake -S . -B build && cmake --build build

# ------------------------------------------------------------------------------
# Formateo de código
# ------------------------------------------------------------------------------
.PHONY: format
format:
	find src -type f \( -name "*.cpp" -o -name "*.hpp" -o -name "*.h" \) -exec clang-format -i {} +

# ------------------------------------------------------------------------------
# Ejecutar el binario
# ------------------------------------------------------------------------------
.PHONY: run
run:
	./build/bin/pulso --once

# ------------------------------------------------------------------------------
# Ayuda
# ------------------------------------------------------------------------------
.PHONY: help
help:
	@echo "Targets disponibles:"
	@echo "  build   - Compila el proyecto con CMake"
	@echo "  test    - Ejecuta los tests con ctest"
	@echo "  clean   - Elimina el directorio build/"
	@echo "  format  - Aplica clang-format a todo src/"
	@echo "  run     - Ejecuta ./build/bin/pulso --once"
	@echo "  help    - Muestra esta ayuda"