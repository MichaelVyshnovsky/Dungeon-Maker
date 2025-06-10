#ifndef PRIZEROOM_H
#define PRIZEROOM_H

#include "Room.h"

class PrizeRoom : public Room {
public:
    PrizeRoom(Wall* north, Wall* east, Wall* south, Wall* west);
    std::string getType() const override;
};

#endif // PRIZEROOM_H
