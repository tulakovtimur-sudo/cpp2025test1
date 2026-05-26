#include "InputHandler.h"
#include "Constants.h"

float getPlayerMovement()
{
    float move = MOVE_STOP;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::A) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Left))
        move = MOVE_LEFT;

    if (sf::Keyboard::isKeyPressed(sf::Keyboard::Key::D) ||
        sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Right))
        move = MOVE_RIGHT;

    return move;
}

bool isShooting()
{
    return sf::Keyboard::isKeyPressed(sf::Keyboard::Key::Space);
}