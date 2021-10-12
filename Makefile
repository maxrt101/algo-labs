export TOPDIR    := $(shell pwd)
export PREFIX    := $(TOPDIR)/build
export BINDIR    := $(PREFIX)/bin

export CXX       := clang++
export CXXFLAGS  := -std=c++17 -I$(TOPDIR)/include -I$(PREFIX)/include
export LDFLAGS   := -L$(PREFIX)/lib -lmrt

SRC       := src/main.cc
TARGET    := $(BINDIR)/rbtee

ifeq ("$(DEBUG)","1")
CXXFLAGS += -g -DDEBUG
endif

.PHONY: build

build: prepare
	$(info Building $(TARGET))
	$(CXX) $(CXXFLAGS) $(LDFLAGS) $(SRC) -o $(TARGET)

test: prepare
	make -C tests PREFIX=$(PREFIX) DEBUG=$(DEBUG) V=$(V) TARGET_BINARY=$(TARGET)

prepare:
	mkdir -p $(PREFIX)
	mkdir -p $(BINDIR)
	make -C mrt PREFIX=$(PREFIX) DEBUG=$(DEBUG) V=$(V)

clean::
	rm -rf $(BINDIR)

$(V).SILENT:
