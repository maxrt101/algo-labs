
TOPDIR   := $(shell pwd)
BINDIR   := $(TOPDIR)/bin

CXX      := clang++
CXXFLAGS := -std=c++17 -I$(TOPDIR)/include

SRC      := src/main.cc
TARGET   := $(BINDIR)/stack_test

.PHONY: build

build: prepare
	$(info Building $(TARGET))
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

prepare:
	mkdir -p $(BINDIR)

$(V).SILENT:

