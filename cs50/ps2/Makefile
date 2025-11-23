CC = g++
CFLAGS = -I include
COMPILE_ONLY = -c

# Source and object files
SRC = src/k_malloc.cpp
OBJ = k_malloc.o
TEST_SRC = tests/t1.cpp
TEST_OBJ = t1.o
OUTPUT = test

all: $(OUTPUT)

$(OBJ):$(SRC)
	$(CC) $(CFLAGS) $(COMPILE_ONLY) -o $(OBJ) $(SRC)

$(TEST_OBJ): $(TEST_SRC)
	$(CC) $(CFLAGS) -o $(TEST_OBJ) (TEST_SRC)

$(OUTPUT): $(OBJ) $(TEST_OBJ)
	$(CC) -o $(OUTPUT) $(OBJ) $(TEST_OBJ)

clean:
	rm -rf *.o $(OUTPUT)