CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g -Iinclude

SRCDIRS = src src/walls src/rooms
OBJDIR = obj

# List of source files with relative paths
SOURCES = $(wildcard src/*.cpp) \
          $(wildcard src/walls/*.cpp) \
          $(wildcard src/rooms/*.cpp)

# Replace .cpp with .o in object directory
OBJECTS = $(patsubst src/%.cpp, $(OBJDIR)/%.o, $(SOURCES))

# Create object directory if not exists
$(shell mkdir -p $(OBJDIR)/walls)
$(shell mkdir -p $(OBJDIR)/rooms)

all: dungeon

dungeon: $(OBJECTS)
	$(CXX) $(CXXFLAGS) -o $@ $^

$(OBJDIR)/%.o: src/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/walls/%.o: src/walls/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

$(OBJDIR)/rooms/%.o: src/rooms/%.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJDIR) dungeon

.PHONY: all clean
