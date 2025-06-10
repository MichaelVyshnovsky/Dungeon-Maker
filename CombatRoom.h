#ifndef COMBATROOM_H
#define COMBATROOM_H

#include "Room.h"

class CombatRoom : public Room {
public:
    CombatRoom(Wall* north, Wall* east, Wall* south, Wall* west);
    std::string getType() const override;
};

#endif // COMBATROOM_H
