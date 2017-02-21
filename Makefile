#
# Makefile
#

CC ?= gcc
CXX ?= g++
CFLAGS ?= -Wall -std=c++11

CLASSES = game player

.PHONY: all test clean

all: qgame

qgame: build/game.o build/player.o build/main.o
	${CXX} ${CFLAGS} -o $@ $^

build/main.o: src/main.cc
	${CXX} -c ${CFLAGS} $< -o $@

build/%.o: src/%.cpp src/%.hpp
	${CXX} -c ${CFLAGS} $< -o $@

test:

clean:
	rm build/*
