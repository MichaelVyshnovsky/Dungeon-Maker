#include "ExitRoom.h"

ExitRoom::ExitRoom(Wall* north, Wall* east, Wall* south, Wall* west)
    : Room(north, east, south, west) {}

std::string ExitRoom::getType() const {
    return "Exit";
}
