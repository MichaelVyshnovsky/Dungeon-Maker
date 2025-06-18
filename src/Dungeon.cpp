#include <Dungeon.h>
#include <rooms/EntranceRoom.h>
#include <rooms/ExitRoom.h>
#include <rooms/PuzzleRoom.h>
#include <rooms/PrizeRoom.h>
#include <walls/Wall.h>
#include <walls/AirWall.h>
#include <iostream>
#include <random>
#include <ctime>
#include <algorithm>
#include <cstdlib>

Dungeon::Dungeon(int w, int h, unsigned seed) : width(w), height(h) {
    grid.resize(height, std::vector<std::shared_ptr<Room>>(width, nullptr));
    std::srand(seed);
    generate();
}

Dungeon::Dungeon(int w, int h) : Dungeon(w, h, static_cast<unsigned>(std::time(nullptr))) {}

bool Dungeon::isBorder(int x, int y) const {
    return x == 0 || y == 0 || x == width - 1 || y == height - 1;
}

void Dungeon::placeEntranceAndExit() {
    do {
        entrancePos = {rand() % width, rand() % height};
    } while (!isBorder(entrancePos.first, entrancePos.second));

    do {
        exitPos = {rand() % width, rand() % height};
    } while (!isBorder(exitPos.first, exitPos.second) || entrancePos == exitPos);

    grid[entrancePos.second][entrancePos.first] = std::make_shared<EntranceRoom>(nullptr, nullptr, nullptr, nullptr);
    grid[exitPos.second][exitPos.first] = std::make_shared<ExitRoom>(nullptr, nullptr, nullptr, nullptr);
}

void Dungeon::placePrizeRooms(int count) {
    prizeRoomPositions.clear();
    int attempts = 0;

    while ((int)prizeRoomPositions.size() < count && attempts++ < 1000) {
        std::pair<int, int> pos = {rand() % width, rand() % height};
        if (pos != entrancePos && pos != exitPos && !grid[pos.second][pos.first]) {
            grid[pos.second][pos.first] = std::make_shared<PrizeRoom>(nullptr, nullptr, nullptr, nullptr);
            prizeRoomPositions.push_back(pos);
        }
    }
}

void Dungeon::assignWalls() {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            auto& current = grid[y][x];
            if (!current) continue;

            std::shared_ptr<Wall> north, east, south, west;

            // Get north and west walls from neighbors or create new
            north = (y > 0 && grid[y - 1][x]) ? grid[y - 1][x]->getWall("south") : std::make_shared<Wall>();
            west  = (x > 0 && grid[y][x - 1]) ? grid[y][x - 1]->getWall("east")  : std::make_shared<Wall>();

            // For east and south, check if neighbor exists, if yes, set nullptr so neighbor will own that wall
            east  = (x < width - 1 && grid[y][x + 1]) ? nullptr : std::make_shared<Wall>();
            south = (y < height - 1 && grid[y + 1][x]) ? nullptr : std::make_shared<Wall>();

            current = std::shared_ptr<Room>(current->cloneWithWalls(north, east, south, west).release());

            // Set east wall of eastern neighbor if needed
            if (x < width - 1 && grid[y][x + 1] && !east) {
                auto neighbor = grid[y][x + 1];
                neighbor = std::shared_ptr<Room>(neighbor->cloneWithWalls(
                    neighbor->getWall("north"),
                    current->getWall("east"),
                    neighbor->getWall("south"),
                    neighbor->getWall("west")
                ).release());
                grid[y][x + 1] = neighbor;
            }

            // Set south wall of southern neighbor if needed
            if (y < height - 1 && grid[y + 1][x] && !south) {
                auto neighbor = grid[y + 1][x];
                neighbor = std::shared_ptr<Room>(neighbor->cloneWithWalls(
                    neighbor->getWall("north"),
                    neighbor->getWall("east"),
                    current->getWall("south"),
                    neighbor->getWall("west")
                ).release());
                grid[y + 1][x] = neighbor;
            }
        }
    }
}

void Dungeon::generatePath() {
    std::vector<std::pair<int, int>> waypoints = prizeRoomPositions;
    waypoints.insert(waypoints.begin(), entrancePos);
    waypoints.push_back(exitPos);

    for (size_t i = 0; i < waypoints.size() - 1; ++i) {
        int x = waypoints[i].first;
        int y = waypoints[i].second;
        int targetX = waypoints[i + 1].first;
        int targetY = waypoints[i + 1].second;

        while (x != targetX || y != targetY) {
            if (!grid[y][x]) {
                grid[y][x] = std::make_shared<PuzzleRoom>(nullptr, nullptr, nullptr, nullptr);
            }

            int dx = targetX - x;
            int dy = targetY - y;

            if ((std::abs(dx) > std::abs(dy) && dx != 0) || dy == 0) {
                x += (dx > 0) ? 1 : -1;
            } else {
                y += (dy > 0) ? 1 : -1;
            }
        }

        if (!grid[y][x]) {
            grid[y][x] = std::make_shared<PuzzleRoom>(nullptr, nullptr, nullptr, nullptr);
        }
    }
}

void Dungeon::generate() {
    placeEntranceAndExit();
    placePrizeRooms(2);
    generatePath();
    assignWalls();
}

void Dungeon::printDungeonMap() const {
    for (int y = 0; y < height; ++y) {
        for (int x = 0; x < width; ++x) {
            if (entrancePos == std::make_pair(x, y)) {
                std::cout << "E ";
            } else if (exitPos == std::make_pair(x, y)) {
                std::cout << "X ";
            } else if (grid[y][x]) {
                if (std::dynamic_pointer_cast<PrizeRoom>(grid[y][x])) {
                    std::cout << "$ ";
                } else {
                    std::cout << ". ";
                }
            } else {
                std::cout << "# ";
            }
        }
        std::cout << "\n";
    }
}
