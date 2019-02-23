CC=g++
CFLAGS=-W
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

.PHONY: clean

clean:
	rm -rf $(OBJECT_DIR)
	rm -f $(OUTPUT_PROG)
	mkdir -p $(OBJECT_DIR) $(OBJECT_DIR)/algo
