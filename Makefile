CC=g++
CFLAGS=-shared -fPIC
OUT=out
GAME_DIR=out
GAME=PwnAdventure3-Linux-Shipping


libHack.so: src/libHack.cpp
	$(CC) $< $(CFLAGS) -o $(OUT)/$@

all: libHack.so


.ONSHELL:

run:
	cd $(GAME_DIR); LD_PRELOAD=libHack.so ./$(GAME)

.PHONY: all run