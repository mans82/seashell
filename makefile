SRC_DIR := src
BUILD_DIR := build
BIN_DIR := $(BUILD_DIR)/bin

EXEC_NAME := seashell

SRCS := $(shell find $(SRC_DIR) -name '*.cpp')
OBJS := $(patsubst $(SRC_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SRCS))

exec: $(OBJS)
	mkdir -p $(BIN_DIR)
	$(CXX) -o $(BIN_DIR)/$(EXEC_NAME) $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.cpp
	mkdir -p $(@D)
	$(CXX) -o $@ -c $<

clean:
	rm -rf $(BUILD_DIR)
