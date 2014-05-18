#include "Tile.h"
#include <iostream>

Tile::Tile(int identifier, int x, int y, const int tileSize)
{
    //gridLocation = sf::Vector2i(gridX, gridY);

    // Determining the type of tile specified
    switch(identifier)
    {
    case 0:
        type = Type::DIRT;
        break;
    case 1:
        type = Type::CLEAR;
        break;
    case 2:
        type = Type::METAL;
        break;
    case 3:
        type = Type::EXIT;
        break;
    case 4:
        type = Type::ROCK;
        break;
    case 5:
        type = Type::DIAMOND;
        break;
    default:
        std::cout << "Tile type: " << identifier << " is invalid, defaulting to 0 (DIRT)" << std::endl;
        type = Type::DIRT;
        break;
    }
    sprite.setPosition(x*tileSize, y*tileSize);
}

// Default constructor
Tile::Tile(){}

void Tile::setTexture(sf::Texture& texture, const int tileSize)
{
    // Associating a texture (tileSheet) with this sprite
    sprite.setTexture(texture);

    // Determining what part of the tileSheet to draw
    if (type != Type::EXIT)
        sprite.setTextureRect( sf::IntRect(type * tileSize, 0, tileSize, tileSize) );
    else
        sprite.setTextureRect( sf::IntRect(2 * tileSize, 0, tileSize, tileSize) );
}

void Tile::setType(Type newType, const int tileSize)
{
    /*switch(newType)
    {
    case 0:
        type = Type::DIRT;
        break;
    case 1:
        type = Type::CLEAR;
        break;
    case 2:
        type = Type::METAL;
        break;
    case 3:
        type = Type::EXIT;
        break;
    default:
        type = Type::DIRT;
        break;
    }*/
    type = newType;

    // Changing the sprite to relfect the new type
    sprite.setTextureRect( sf::IntRect(type * tileSize, 0, tileSize, tileSize ));
}

void Tile::draw(sf::RenderWindow& window)
{
    window.draw(sprite);
}

Tile::~Tile()
{
    //dtor
}
