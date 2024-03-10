
SRC_DIR := ./src

#
#	All source files starting with 'morse' are related
#	to the morse translator library.
#

MORSE_SRCS := $(shell find $(SRC_DIR) -name 'morse*' )

TRANSL_SRCS := $(SRC_DIR)/translator.c

INC_DIR := ./include
LIB_DIR := ./lib

all: $(LIB_DIR)/libMorseTranslator.so $(TRANSL_SRCS) translator

$(LIB_DIR)/libMorseTranslator.so: $(MORSE_SRCS)
	gcc -fPIC -shared -I$(INC_DIR) -o $(LIB_DIR)/libMorseTranslator.so $(MORSE_SRCS) 

translator: $(TRANSL_SRCS)
	gcc -g -I$(INC_DIR) -L$(LIB_DIR) -o translator $(TRANSL_SRCS) -l MorseTranslator

clean:
	rm -f $(LIB_DIR)/*.so translator
