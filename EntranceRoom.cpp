#include "EntranceRoom.h"

EntranceRoom::EntranceRoom(Wall* north, Wall* east, Wall* south, Wall* west)
    : Room(north, east, south, west) {}

std::string EntranceRoom::getType() const {
    return "Entrance";
}
