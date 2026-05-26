#pragma once
#include <SFML/Graphics.hpp>

class Bullet
{
private:
    sf::RectangleShape shape;
    float speed;
    bool active;

public:
    Bullet();
    void shoot(float x, float y);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool isActive() const;
    sf::FloatRect getBounds() const;
    void deactivate();
};