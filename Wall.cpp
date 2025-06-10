#include "Wall.h"

Wall::Wall() : material("stone") {}

Wall::~Wall() {}

std::string Wall::getDescription() const {
    return "A solid wall made of " + material + ".";
}

bool Wall::isPassable() const {
    return false;
}

void Wall::setMaterial(const std::string& mat) {
    material = mat;
}

std::string Wall::getMaterial() const {
    return material;
}
