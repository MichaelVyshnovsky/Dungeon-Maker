#ifndef PUZZLEROOM_H
#define PUZZLEROOM_H

#include "Room.h"

class PuzzleRoom : public Room {
public:
    PuzzleRoom(Wall* north, Wall* east, Wall* south, Wall* west);
    std::string getType() const override;
};

#endif // PUZZLEROOM_H
