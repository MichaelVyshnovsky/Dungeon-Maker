#include <walls/Wall.h>
#include "walls/Door.h"

Door::Door(bool isOpen) : open(isOpen) {
    // No material is set here — it uses the default from Wall or can be set externally
}

std::string Door::getDescription() const {
    return open ? "An open door." : "A closed door.";
}

bool Door::isPassable() const {
    return open;
}
