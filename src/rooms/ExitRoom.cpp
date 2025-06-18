#include "rooms/Room.h"
#include "walls/Wall.h"
#include "rooms/ExitRoom.h"

ExitRoom::ExitRoom(std::shared_ptr<Wall> north,
                       std::shared_ptr<Wall> east,
                       std::shared_ptr<Wall> south,
                       std::shared_ptr<Wall> west)
    : Room(north, east, south, west) {}

std::string ExitRoom::getType() const {
    return "Puzzle Room";
}

std::unique_ptr<Room> ExitRoom::cloneWithWalls(std::shared_ptr<Wall> north,
                                                 std::shared_ptr<Wall> east,
                                                 std::shared_ptr<Wall> south,
                                                 std::shared_ptr<Wall> west) const {
    return std::make_unique<ExitRoom>(north, east, south, west);
}
