# Makefile for plotting programs

CXX = g++ -O2
CC = gcc -O2

FLAGS += $(shell root-config --cflags)
FLAGS += $(shell root-config --libs)
FLAGS += -I/usr/local/include -Wl,-rpath,/usr/local/lib -L/usr/local/lib -lfid
FLAGS += -I$(BOOST_INC) -L$(BOOST_LIB) -lboost_system -lboost_filesystem

TARGETS = $(patsubst src/%.cxx,bin/%,$(wildcard src/*.cxx))

all: $(TARGETS)

bin/%: src/%.cxx
	$(CXX) $(FLAGS) $< -o $@ 