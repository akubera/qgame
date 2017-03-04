#
# Makefile
#

CC ?= gcc
CXX ?= g++
CFLAGS ?= -Wall -std=c++14

CLASSES = Game Player App

CLASS_SRC_FILES = $(addsuffix .cpp,$(shell echo "${CLASSES}" | tr A-Z a-z))
CLASS_HDR_FILES = $(subst .cpp,.hpp,${CLASS_SRC_FILES})
CLASS_OBJ_FILES = $(subst .cpp,.o,${CLASS_SRC_FILES})

.PHONY: all test clean

all: qgame

qgame: build/main.o $(addprefix build/,${CLASS_OBJ_FILES})
	${CXX} ${CFLAGS} -o $@ $^

build/main.o: src/main.cc
	${CXX} -c ${CFLAGS} $< -o $@

build/%.o: src/%.cpp src/%.hpp
	${CXX} -c ${CFLAGS} $< -o $@

test:

clean:
	rm build/*
