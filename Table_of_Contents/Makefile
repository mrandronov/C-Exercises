
CC := gcc

SRC_DIR := ./src
INC_DIR := ./include
LIB_DIR := ./lib
BUILD_DIR := ./build

TOC_SRCS := $(SRC_DIR)/table_of_contents.c $(SRC_DIR)/input_data.c
MAIN_SRCS := $(SRC_DIR)/main.c

TOC_OBJS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(TOC_SRCS:.c=.o))
MAIN_OBJS := $(patsubst $(SRC_DIR)/%,$(BUILD_DIR)/%,$(MAIN_SRCS:.c=.o))

INC_FLAGS := -I$(INC_DIR)
LIB_FLAGS := -L$(LIB_DIR)

all: $(TOC_SRCS) $(MAIN_SRCS) $(LIB_DIR)/libTableOfContents.so main

$(BUILD_DIR)/%.o: $(SRC_DIR)/%.c
	@mkdir -p $(BUILD_DIR)
	$(CC) $(INC_FLAGS) -c $^ -o $@

$(LIB_DIR)/libTableOfContents.so: $(TOC_OBJS)
	$(CC) -fPIC -shared $(INC_FLAGS) -o $(LIB_DIR)/libTableOfContents.so $(TOC_OBJS)

main: $(MAIN_OBJS)
	$(CC) -g $(INC_FLAGS) $(LIB_FLAGS) -o main $(MAIN_SRCS) -l TableOfContents

clean:
	rm -rf $(BUILD_DIR) $(LIB_DIR)/*.so main

