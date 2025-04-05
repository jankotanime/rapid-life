# Kompilator i flagi
CXX = g++
CXXFLAGS = -std=c++17 -Iinclude -Wall -Wextra
SFML_LIBS = -lsfml-graphics -lsfml-window -lsfml-system

# Katalogi
SRC_DIR = src
INC_DIR = include
BUILD_DIR = build
BIN_DIR = bin

# Nazwa końcowego programu
TARGET = $(BIN_DIR)/main

# Źródła i obiekty
SOURCES := $(wildcard $(SRC_DIR)/*.cpp) $(wildcard $(SRC_DIR)/*/*.cpp)
OBJECTS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))

# Domyślna reguła
all: $(TARGET)

# Linkowanie
$(TARGET): $(OBJECTS)
	@mkdir -p $(BIN_DIR)
	@echo "Linkowanie: $(CXX) $(OBJECTS) -o $@ $(SFML_LIBS)"
	$(CXX) $(OBJECTS) -o $@ $(SFML_LIBS)

# Kompilacja każdego pliku .cpp do .o
$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	@mkdir -p $(BUILD_DIR)/$(dir $<)  # Tworzenie odpowiednich katalogów
	@echo "Kompilowanie: $(CXX) $(CXXFLAGS) -c $< -o $@"
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Uruchamianie programu
run: $(TARGET)
	./$(TARGET)

# Czyszczenie
clean:
	rm -rf $(BUILD_DIR) $(BIN_DIR)

.PHONY: all clean run
