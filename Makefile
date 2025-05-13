# Compiler and flags
CXX := g++
CXXFLAGS := -std=c++14 -Wall -g

# Directories
SRCDIR := src
BUILDDIR := build
BINDIR := bin

# Output binary
TARGET := $(BINDIR)/program

# Source and object files
SOURCES := $(wildcard $(SRCDIR)/*.cpp)
OBJECTS := $(patsubst $(SRCDIR)/%.cpp,$(BUILDDIR)/%.o,$(SOURCES))

# Vcpkg settings
VCPKG_TRIPLET := x64-windows
VCPKG_ROOT := C:/vcpkg/
VCPKG_INCLUDE_PATH := $(VCPKG_ROOT)/installed/$(VCPKG_TRIPLET)/include
VCPKG_LIB_PATH := $(VCPKG_ROOT)/installed/$(VCPKG_TRIPLET)/lib

# Include and link flags
CXXFLAGS += -I$(VCPKG_INCLUDE_PATH)

# Make sure the necessary directories exist
$(shell mkdir -p $(BUILDDIR))
$(shell mkdir -p $(BINDIR))

# Default build target
all: $(TARGET)

# Link the final binary
$(TARGET): $(OBJECTS)
	$(CXX) $(CXXFLAGS) $(OBJECTS) -o $@ $(LDFLAGS)

# Compile each source file to an object file
$(BUILDDIR)/%.o: $(SRCDIR)/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean the build files
clean:
	rm -rf $(BUILDDIR)/*.o $(TARGET)

.PHONY: all clean
