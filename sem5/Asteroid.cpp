#include "Asteroid.h"
#include "Constants.h"

Asteroid::Asteroid() : speed(ASTEROID_DEFAULT_SPEED), active(false)
{
    shape.setPointCount(ASTEROID_POINT_COUNT);
    for (int i = 0; i < ASTEROID_POINT_COUNT; i++)
    {
        shape.setPoint(i, ASTEROID_POINTS[i]);
    }

    shape.setFillColor(ASTEROID_COLOR);
    shape.setOutlineThickness(ASTEROID_OUTLINE_THICKNESS);
    shape.setOutlineColor(ASTEROID_OUTLINE_COLOR);
}

void Asteroid::spawn(float x, float y, float asteroidSpeed)
{
    shape.setPosition(sf::Vector2f(x, y));
    speed = asteroidSpeed;
    active = true;
}

void Asteroid::update(float deltaTime)
{
    if (active)
    {
        shape.move(sf::Vector2f(0.f, speed * deltaTime));

        if (shape.getPosition().y > WINDOW_HEIGHT)
        {
            active = false;
        }
    }
}

void Asteroid::draw(sf::RenderWindow& window)
{
    if (active)
    {
        window.draw(shape);
    }
}

bool Asteroid::isActive() const
{
    return active;
}

sf::FloatRect Asteroid::getBounds() const
{
    return shape.getGlobalBounds();
}

void Asteroid::deactivate()
{
    active = false;
}