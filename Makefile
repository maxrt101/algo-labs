
TOPDIR    := $(shell pwd)
BINDIR    := $(TOPDIR)/bin

CXX       := clang++
CXXFLAGS  := -std=c++17 -I$(TOPDIR)/include

SRC       := src/main.cc src/utils.cc
TARGET    := $(BINDIR)/sort

.PHONY: build

build: prepare
	$(info Building $(TARGET))
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

prepare:
	mkdir -p $(BINDIR)

$(V).SILENT:

