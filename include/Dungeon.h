#ifndef DUNGEON_H
#define DUNGEON_H

#include <rooms/Room.h>
#include <walls/Wall.h>
#include <vector>
#include <memory>
#include <utility>



class Dungeon {
public:
    Dungeon(int width, int height, unsigned seed);
    Dungeon(int width, int height);

    void generate();
    void printDungeonMap() const;

private:
    int width;
    int height;
    std::vector<std::vector<std::shared_ptr<Room>>> grid;

    std::pair<int, int> entrancePos;
    std::pair<int, int> exitPos;
    std::vector<std::pair<int, int>> prizeRoomPositions;

    bool isBorder(int x, int y) const;
    void placeEntranceAndExit();
    void placePrizeRooms(int count);
    void assignWalls();
    void generatePath();
};

#endif // DUNGEON_H
