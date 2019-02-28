CC=g++
CFLAGS=-Wall -std=c++11 -O0 -g
OUTPUT_DIR=dist
OBJECT_DIR=$(OUTPUT_DIR)/obj
OUTPUT_PROG=$(OUTPUT_DIR)/output

DEPS=$(shell find src -type f -name '*.hpp')

CPP_FILES=$(shell find src -type f -name '*.cpp')
OBJS=$(patsubst src/%.cpp, $(OBJECT_DIR)/%.o, $(CPP_FILES))

$(OBJECT_DIR)/%.o: src/%.cpp $(DEPS)
	$(CC) -c -o $@ $< $(CFLAGS)

build: $(OBJS)
	$(CC) -o $(OUTPUT_PROG) $^ $(CFLAGS)
	chmod +x $(OUTPUT_PROG)

test: $(OUTPUT_PROG)
	./$(OUTPUT_PROG) data/daftar_rumah.small.csv 100 index 4
	./$(OUTPUT_PROG) data/daftar_rumah.small.csv 100 binary "Abyasa Adriansyah"
	./$(OUTPUT_PROG) data/daftar_rumah.small.csv 100 linear "Shania Purwanti"
	./$(OUTPUT_PROG) data/daftar_rumah.small.csv 100 loglin C
	./$(OUTPUT_PROG) data/daftar_rumah.small.csv 100 square average
	./$(OUTPUT_PROG) data/daftar_rumah.small.csv 20 shortest 10

.PHONY: clean

clean:
	rm -rf $(OBJECT_DIR)
	rm -f $(OUTPUT_PROG)
	mkdir -p $(OBJECT_DIR) $(OBJECT_DIR)/algo
