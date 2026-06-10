CXX      ?= g++
CXXFLAGS ?= -std=c++20 -Wall -Wextra -O2

SRC_DIR   := src
TEST_DIR  := tests
BUILD_DIR := build

LIB_SRC   := $(SRC_DIR)/twosum.cpp
DEMO_SRC  := $(SRC_DIR)/main.cpp
TEST_SRC  := $(TEST_DIR)/test_twosum.cpp

DEMO_BIN  := $(BUILD_DIR)/twosum_demo
TEST_BIN  := $(BUILD_DIR)/test_twosum

.PHONY: all test run clean

all: $(DEMO_BIN) $(TEST_BIN)

$(BUILD_DIR):
	mkdir -p $(BUILD_DIR)

$(DEMO_BIN): $(DEMO_SRC) $(LIB_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(DEMO_SRC) $(LIB_SRC) -o $@

$(TEST_BIN): $(TEST_SRC) $(LIB_SRC) | $(BUILD_DIR)
	$(CXX) $(CXXFLAGS) $(TEST_SRC) $(LIB_SRC) -o $@

test: $(TEST_BIN)
	./$(TEST_BIN)

run: $(DEMO_BIN)
	./$(DEMO_BIN)

clean:
	rm -rf $(BUILD_DIR)
