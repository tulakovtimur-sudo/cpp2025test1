#pragma once
#include <SFML/Graphics.hpp>
#include <vector>

class Background
{
private:
    sf::RectangleShape background;
    std::vector<sf::RectangleShape> stars;
    float starSpeed;

public:
    Background();
    void update(float deltaTime);
    void draw(sf::RenderWindow& window);

private:
    void createStars();
};