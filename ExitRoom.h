#ifndef EXITROOM_H
#define EXITROOM_H

#include "Room.h"

class ExitRoom : public Room {
public:
    ExitRoom(Wall* north, Wall* east, Wall* south, Wall* west);
    std::string getType() const override;
};

#endif // EXITROOM_H
