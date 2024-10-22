
CC = gcc
CFLAGS = -Wall

SRC_DIR = src
BUILD_DIR = build

SOURCES = $(wildcard $(SRC_DIR)/*.c)
OBJS = $(patsubst $(SRC_DIR)/%.c, $(BUILD_DIR)/%.o, $(SOURCES))

TARGET = a2

all: $(BUILD_DIR) $(TARGET)

$(TARGET): $(OBJS)
	@$(CC) $(CFLAGS) -o $@ $^

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@$(CC) $(CFLAGS) -c $< -o $@

$(BUILD_DIR):
	@mkdir -p $(BUILD_DIR)

clean-build:
	@rm -rf $(BUILD_DIR)

clean-target:
	@rm $(TARGET).exe

clean: clean-build clean-target

run: all
	@./$(TARGET)