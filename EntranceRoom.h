#ifndef ENTRANCEROOM_H
#define ENTRANCEROOM_H

#include "Room.h"

class EntranceRoom : public Room {
public:
    EntranceRoom(Wall* north, Wall* east, Wall* south, Wall* west);
    std::string getType() const override;
};

#endif // ENTRANCEROOM_H
