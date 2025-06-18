#include "rooms/Room.h"
#include "walls/Wall.h"
#include "rooms/EmptyRoom.h"

EmptyRoom::EmptyRoom(std::shared_ptr<Wall> north,
                     std::shared_ptr<Wall> east,
                     std::shared_ptr<Wall> south,
                     std::shared_ptr<Wall> west)
    : Room(north, east, south, west) {}

std::string EmptyRoom::getType() const {
    return "Empty Room";
}

std::unique_ptr<Room> EmptyRoom::cloneWithWalls(std::shared_ptr<Wall> north,
                                                 std::shared_ptr<Wall> east,
                                                 std::shared_ptr<Wall> south,
                                                 std::shared_ptr<Wall> west) const {
    return std::make_unique<EmptyRoom>(north, east, south, west);
}
