#ifndef COMBATROOM_H
#define COMBATROOM_H

#include "rooms/Room.h"
#include "walls/Wall.h"
#include <memory>

class CombatRoom : public Room {
public:
    CombatRoom(std::shared_ptr<Wall> north,
              std::shared_ptr<Wall> east,
              std::shared_ptr<Wall> south,
              std::shared_ptr<Wall> west);
              
    std::string getType() const override;

    std::unique_ptr<Room> cloneWithWalls(std::shared_ptr<Wall> north,
                                     std::shared_ptr<Wall> east,
                                     std::shared_ptr<Wall> south,
                                     std::shared_ptr<Wall> west) const override;
};

#endif // COMBATROOM_H
