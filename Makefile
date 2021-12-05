
export TOPDIR    := $(shell pwd)
export PREFIX    := $(TOPDIR)/build
export BINDIR    := $(PREFIX)/bin

export CXX       := clang++
export CXXFLAGS  := -std=c++17 -I$(TOPDIR)/include -I$(PREFIX)/include

SRC       := src/main.cc src/kmp.cc
TARGET    := $(BINDIR)/kmp

ifeq ("$(DEBUG)","1")
CXXFLAGS += -g -DDEBUG
endif

.PHONY: build

build: prepare
	$(info Building $(TARGET))
	$(CXX) $(CXXFLAGS) $(SRC) -o $(TARGET)

prepare:
	mkdir -p $(PREFIX)
	mkdir -p $(BINDIR)
	make -C mrt PREFIX=$(PREFIX) DEBUG=$(DEBUG) V=$(V)

clean::
	rm -rf $(BINDIR)

$(V).SILENT:
