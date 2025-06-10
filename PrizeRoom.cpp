#include "PrizeRoom.h"

PrizeRoom::PrizeRoom(Wall* north, Wall* east, Wall* south, Wall* west)
    : Room(north, east, south, west) {}

std::string PrizeRoom::getType() const {
    return "Prize Room";
}
