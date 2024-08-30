# Compiler
CC = gcc

# Compiler Flags
CFLAGS = -I./raylib/src

# Linker Flags
LDFLAGS = -L./raylib/src -lraylib -lGL -lm -lpthread -ldl -lrt -lX11

# Source Files
SRC = main.c

# Output executable name
OUT = myprogram

# Default target
all: $(OUT)

# Build the executable
$(OUT): $(SRC)
	$(CC) $(SRC) $(CFLAGS) $(LDFLAGS) -o $(OUT)

# Clean up build files
clean:
	rm -f $(OUT)

.PHONY: all clean
