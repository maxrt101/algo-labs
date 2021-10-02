
TOPDIR    := $(shell pwd)
PREFIX    := $(TOPDIR)/build
BINDIR    := $(PREFIX)/bin

CXX       := clang++
CXXFLAGS  := -std=c++17 -I$(TOPDIR)/include -I$(PREFIX)/include
LDFLAGS   := -L$(PREFIX)/lib -lmrt

SRC       := src/main.cc src/discount.cc src/utils.cc
TARGET    := $(BINDIR)/discount

ifeq ("$(DEBUG)","1")
CXXFLAGS += -g -DDEBUG
endif

.PHONY: build

build: prepare
	$(info Building $(TARGET))
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SRC) -o $(TARGET)

prepare:
	mkdir -p $(PREFIX)
	mkdir -p $(BINDIR)
	make -C mrt PREFIX=$(PREFIX) DEBUG=$(DEBUG) V=$(V)

clean::
	rm -rf $(BINDIR)

$(V).SILENT:

