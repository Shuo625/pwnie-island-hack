INCLUDE_DIR := src
CC          := g++
CFLAGS      := -shared -fPIC -I $(INCLUDE_DIR)

GAME_DIR    := game
GAME        := PwnAdventure3-Linux-Shipping

LIBHACK     := libHack.so

SOURCES_DIR := src
SOURCES     := $(shell find $(SOURCES_DIR) -name '*.cpp') 

BUILD_DIR   := build
OBJECTS     := $(patsubst $(SOURCES_DIR)/%.cpp, $(BUILD_DIR)/%.o, $(SOURCES))


$(BUILD_DIR)/%.o: $(SOURCES_DIR)/%.cpp
	$(CC) $(CFLAGS) -c $< -o $@

$(LIBHACK): $(OBJECTS)
	$(CC) $(CFLAGS) $(OBJECTS) -o $(BUILD_DIR)/$@

all: $(LIBHACK)

clean:
	rm $(BUILD_DIR)/*.o

rungame:
	cp $(BUILD_DIR)/$(LIBHACK) $(GAME_DIR)
	cd $(GAME_DIR); LD_PRELOAD=$(LIBHACK) ./$(GAME)

.PHONY: all run