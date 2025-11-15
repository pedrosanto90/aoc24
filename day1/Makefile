# Define the output directory
BIN_DIR = bin

# Define the name of the executable (output file)
TARGET = main

# Define the source files
SOURCES = main.cpp

# Define the object files (to be placed in BIN_DIR)
# The substitution function patsubst replaces the .cpp extension with .o
OBJECTS = $(patsubst %.cpp, $(BIN_DIR)/%.o, $(SOURCES))

# C++ Compiler
CXX = g++

# Compiler flags: -Wall (warnings), -c (compile only), -g (debugging info)
CXXFLAGS = -Wall -c -g

# Linker flags: -o (output file)
LDFLAGS = -g

# --- Main Rules ---

# 1. Default target (first one in the file)
all: $(BIN_DIR) $(BIN_DIR)/$(TARGET)

# 2. Rule to create the bin directory if it doesn't exist
$(BIN_DIR):
	mkdir -p $(BIN_DIR)

# 3. Rule to link the object files into the final executable
$(BIN_DIR)/$(TARGET): $(OBJECTS)
	$(CXX) $(LDFLAGS) $(OBJECTS) -o $@

# 4. Rule to compile the source file(s) into object file(s)
# $< is the first prerequisite (e.g., main.cpp)
# $@ is the target (e.g., bin/main.o)
$(BIN_DIR)/%.o: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@

# 5. Clean rule (to remove generated files)
.PHONY: clean
clean:
	rm -rf $(BIN_DIR)
