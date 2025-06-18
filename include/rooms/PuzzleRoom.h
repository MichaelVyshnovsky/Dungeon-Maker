#ifndef PUZZLEROOM_H
#define PUZZLEROOM_H

#include "rooms/Room.h"
#include "walls/Wall.h"
#include <memory>

class PuzzleRoom : public Room {
public:
    PuzzleRoom(std::shared_ptr<Wall> north,
               std::shared_ptr<Wall> east,
               std::shared_ptr<Wall> south,
               std::shared_ptr<Wall> west);

    std::string getType() const override;

    std::unique_ptr<Room> cloneWithWalls(std::shared_ptr<Wall> north,
                                     std::shared_ptr<Wall> east,
                                     std::shared_ptr<Wall> south,
                                     std::shared_ptr<Wall> west) const override;
};

#endif // PUZZLEROOM_H
