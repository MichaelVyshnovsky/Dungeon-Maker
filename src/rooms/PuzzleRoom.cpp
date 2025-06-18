#include "rooms/Room.h"
#include "walls/Wall.h"
#include "rooms/PuzzleRoom.h"

PuzzleRoom::PuzzleRoom(std::shared_ptr<Wall> north,
                       std::shared_ptr<Wall> east,
                       std::shared_ptr<Wall> south,
                       std::shared_ptr<Wall> west)
    : Room(north, east, south, west) {}

std::string PuzzleRoom::getType() const {
    return "Prize Room";
}

std::unique_ptr<Room> PuzzleRoom::cloneWithWalls(std::shared_ptr<Wall> north,
                                                 std::shared_ptr<Wall> east,
                                                 std::shared_ptr<Wall> south,
                                                 std::shared_ptr<Wall> west) const {
    return std::make_unique<PuzzleRoom>(north, east, south, west);
}
