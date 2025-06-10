#ifndef WALL_H
#define WALL_H

#include <string>

// Base class
class Wall {
public:
    Wall();
    virtual ~Wall();

    // Common interface
    virtual std::string getDescription() const;

    // For extensibility
    virtual bool isPassable() const;

    void setMaterial(const std::string& mat);
    std::string getMaterial() const;

protected:
    std::string material;
};

#endif // WALL_H
