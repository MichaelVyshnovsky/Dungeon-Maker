# Compiler and flags
CXX = g++
CXXFLAGS = -std=c++17 -Wall -Wextra -g

# Source files
SRCS = main.cpp \
       Wall.cpp Door.cpp LockedDoor.cpp CrackedWall.cpp AirWall.cpp \
       Room.cpp EntranceRoom.cpp ExitRoom.cpp PrizeRoom.cpp CombatRoom.cpp PuzzleRoom.cpp \
       Dungeon.cpp

# Object files (from source files)
OBJS = $(SRCS:.cpp=.o)

# Executable name
TARGET = dungeon_game

# Default target
all: $(TARGET)

# Link the object files into the final binary
$(TARGET): $(OBJS)
	$(CXX) $(CXXFLAGS) -o $@ $^

# Compile .cpp to .o
%.o: %.cpp
	$(CXX) $(CXXFLAGS) -c $< -o $@

# Clean object files and executable
clean:
	rm -f $(OBJS) $(TARGET)

# Convenience for rebuilding from scratch
rebuild: clean all
