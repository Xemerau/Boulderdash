#include <iostream>
#include <SFML/Graphics.hpp>
#include "ImageManager.h"
#include "Level.h"
#include "Camera2D.h"
#include "InputManager.h"
#include "Player.h"

int main()
{
    // Initilizing the SFML Window
    sf::RenderWindow window(sf::VideoMode(1280,720), "Boulderdash");
    window.setFramerateLimit(60);
    ImageManager imageManager;
    InputManager inputManager;
    Level testLevel("levels/testLevel/", "assets/tilesheets/upperTiles.png", imageManager);
    imageManager.loadImage("assets/sprites/raveSprite.png", "playerSprite");
    Player player(1 * testLevel.getTileSize(),4 * testLevel.getTileSize(),imageManager.getTexture("playerSprite"));
    player.initAnimations(1,1);

    while(window.isOpen())
    {
        // Update
        inputManager.update();
        sf::Event event;
        while(window.pollEvent(event))
        {

        }
        if(inputManager.validKeyDown())
        {
            testLevel.update();
            player.update(testLevel, inputManager);
        }

        // Render
        window.clear();
        testLevel.draw(window);
        player.draw(window);
        window.display();
    }
}
