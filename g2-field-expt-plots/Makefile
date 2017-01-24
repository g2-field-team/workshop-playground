# Makefile for plotting programs

CXX = g++ -O2
CC = gcc -O2

FLAGS += $(shell root-config --cflags)
FLAGS += $(shell root-config --libs)

TARGETS = $(patsubst src/%.cxx,bin/%,$(wildcard src/*.cxx))

all: $(TARGETS)

bin/%: src/%.cxx
	$(CXX) $(FLAGS) $< -o $@ 