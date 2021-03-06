#ifndef LEVEL_H
#define LEVEL_H
#include "Tile.h"
#include <SFML/Graphics/RenderWindow.hpp>
#include "ImageManager.h"
#include <iostream>


class Level
{
    public:
    Level(int levelCount, const std::string& tilePath, ImageManager& imageManager);
    Level();
    ~Level(); // Destructor
    void draw(sf::RenderWindow& window);
    void update(sf::Vector2i playerLocation);
    Tile::Type getTileID(int x, int y);     // Gets the ID of a tile at the specified position
    bool traversable(int x, int y);         // Gets wether or not the specified tile is traversable
    const int getTileSize();
    bool isPlayerCrushed();
    bool getDiamondCollected();
    std::vector<sf::Vector2i> getObstacleLocations();
    sf::Vector2i getPlayerSpawn();
    void loadMap(ImageManager& imageManager);
    int getRemainingDiamonds();
    sf::Vector2i getMapSize();
    void checkExit(sf::Vector2i playerLocation);
    bool isCleared();


    private:
    struct Obstacle
    {
        int x;
        int y;
        bool falling = false;

        Obstacle(int xLoc, int yLoc)
        {
            x = xLoc;
            y = yLoc;
        }
    };

    std::vector<Tile> tileMap;
    std::vector<Obstacle> obstacleLocations;
    sf::Vector2i mapSize;   // The size of the map in tiles
    sf::Vector2i playerSpawn;
    sf::Vector2i exitLocation;
    int tileSize = 64;
    int remainingDiamonds;
    bool exitOpen;
    bool cleared;
    bool playerCrushed;
    bool diamondCollected;

    std::string mapPath;
    std::string tilesheetPath;
};

#endif // LEVEL_H
