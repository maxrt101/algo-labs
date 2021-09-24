
export TOPDIR := $(shell pwd)
export BINDIR := $(TOPDIR)/bin

CXX      := clang++
CFLAGS   := -I$(TOPDIR)/include/ -g
CXXFLAGS := -std=c++17

SRC      := $(TOPDIR)/src/main.cc
TARGET   := $(BINDIR)/btree

.PHONY: build

build: prepare
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(SRC) -o $(TARGET)

prepare:
	mkdir -p $(BINDIR)

