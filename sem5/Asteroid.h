#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Asteroid
{
private:
    sf::ConvexShape shape;
    float speed;
    bool active;

public:
    Asteroid();
    void spawn(float x, float y, float asteroidSpeed);
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);
    bool isActive() const;
    sf::FloatRect getBounds() const;
    void deactivate();
};