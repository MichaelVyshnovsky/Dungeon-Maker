#include <walls/Wall.h>
#include "walls/LockedDoor.h"

LockedDoor::LockedDoor(bool isOpen, bool isLocked)
    : Door(isOpen), locked(isLocked) {}

std::string LockedDoor::getDescription() const {
    if (locked)
        return "A locked door.";
    return Door::getDescription();
}

bool LockedDoor::isPassable() const {
    return !locked && Door::isPassable();
}

void LockedDoor::unlock() {
    locked = false;
}

void LockedDoor::lock() {
    locked = true;
}

bool LockedDoor::isLocked() const {
    return locked;
}
