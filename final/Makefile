CC = g++
CFLAGS = -I.

BUILD = ./build

SRCS = $(shell find ./src -name "*.cc")
MAIN = main.cc
TESTS = $(shell find ./tests -name "*.cc")

all:main

main:$(MAIN) $(SRCS) 
	@echo "💥 Building........"
	@echo "To execute: ./build/main"
	@echo "✔️ Done Building"
	@mkdir -p $(BUILD) 
	$(CC) $(CFLAGS) -o $(BUILD)/$@ $^

tests: $(TESTS)
	@echo "💥 Building........"
	@echo "To execute: ./build/tests"
	@echo "✔️ Done Building"
	@mkdir -p $(BUILD) 
	@$(CC) $(CFLAGS) -o $(BUILD)/$@ $^

clean:
	rm -rf $(BUILD)/*
	rm -rf $(BUILD)
