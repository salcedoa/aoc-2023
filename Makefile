CXX = g++
CXXFLAGS = -std=c++20 -pedantic -Wall -Wpointer-arith -Wwrite-strings
CXXFLAGS += -Wcast-qual -Wcast-align -Wformat-security
CXXFLAGS += -Wformat-nonliteral -Wmissing-format-attribute
CXXFLAGS += -Winline -funsigned-char
CC = $(CXX)

# Get the list of all .cc files in the current directory
SOURCE_FILES := $(wildcard day*.cc)
EXECUTABLES := $(patsubst %.cc,%,$(SOURCE_FILES))

# Default target: Build all executables
all: $(EXECUTABLES)

# Rule to build each executable
%: %.cc utilities.cc
	$(CXX) $(CXXFLAGS) -o $@ $^

# Rule to compile each .cc file into its corresponding object file
%.o: %.cc
	$(CXX) $(CXXFLAGS) -c -o $@ $<

# Run each executable separately
run: $(EXECUTABLES)
	@for executable in $(EXECUTABLES); do \
		./$$executable; \
	done

# Clean up intermediate files and executables
clean:
	rm -f $(EXECUTABLES) *.o
