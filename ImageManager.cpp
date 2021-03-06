#include "ImageManager.h"
#include <iostream>

ImageManager::ImageManager()
{
    loadImage("assets/backgrounds/endBG.png","endBG");
    loadImage("assets/backgrounds/titleBG.png","titleBG");
    loadImage("assets/sprites/button.png","button");
    loadImage("assets/sprites/raveSprite.png", "playerSprite");
}

ImageManager::~ImageManager()
{
    //dtor
}

void ImageManager::loadImage(const std::string& filePath)
{
    sf::Texture tempTexture;

    // Ensuring that the file exists
    if (!tempTexture.loadFromFile(filePath))
    {
        std::cout << "Error loading texture at :\n'" << filePath << "'" << std::endl;
    }

    textures[filePath] = tempTexture;
}

void ImageManager::loadImage(const std::string& filePath, const std::string& key)
{
    sf::Texture tempTexture;

    // Ensuring that the file exists
    if (!tempTexture.loadFromFile(filePath))
    {
        std::cout << "Error loading texture at :\n'" << filePath << "'" << std::endl;
    }

    textures[key] = tempTexture;
}

sf::Texture& ImageManager::getTexture(const std::string& key)
{
    return textures[key];
}

void ImageManager::unloadImage(const std::string& key)
{
    textures.erase(key);
}
