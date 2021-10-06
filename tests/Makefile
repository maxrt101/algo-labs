# Only intended to be ran from parent Makefile

SRC       := test.cc
TARGET    := $(BINDIR)/discount_test

.PHONY: test

test: compile
	$(TARGET) $(TARGET_BINARY)

compile:
	$(CXX) $(CFLAGS) $(CXXFLAGS) $(LDFLAGS) $(SRC) -o $(TARGET)

