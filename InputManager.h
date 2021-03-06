#ifndef INPUTMANAGER_H
#define INPUTMANAGER_H
#include <SFML/Window.hpp>
#include <map>

class InputManager
{
    public:
        InputManager();
        virtual ~InputManager();
        void update();
        bool pressedOnce(std::string keyName);
        bool validKeyDown();
    private:
        bool pressedKeys[sf::Keyboard::KeyCount];
        bool previousPressedKeys[sf::Keyboard::KeyCount];
        std::map<std::string, sf::Keyboard::Key> keyBinds;
};

#endif // INPUTMANAGER_H
