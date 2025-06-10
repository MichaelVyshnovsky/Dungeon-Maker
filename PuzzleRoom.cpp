#include "PuzzleRoom.h"

PuzzleRoom::PuzzleRoom(Wall* north, Wall* east, Wall* south, Wall* west)
    : Room(north, east, south, west) {}

std::string PuzzleRoom::getType() const {
    return "Puzzle Room";
}
