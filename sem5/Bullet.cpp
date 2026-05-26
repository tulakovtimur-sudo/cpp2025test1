#include "Bullet.h"
#include "Constants.h"

Bullet::Bullet() : speed(BULLET_SPEED), active(false)
{
    shape.setSize(sf::Vector2f(BULLET_WIDTH, BULLET_HEIGHT));
    shape.setFillColor(BULLET_COLOR);
    shape.setOutlineThickness(BULLET_OUTLINE_THICKNESS);
    shape.setOutlineColor(BULLET_OUTLINE_COLOR);
}

void Bullet::shoot(float x, float y)
{
    shape.setPosition(sf::Vector2f(x, y - BULLET_OFFSET_Y));
    active = true;
}

void Bullet::update(float deltaTime)
{
    if (active)
    {
        shape.move(sf::Vector2f(0.f, -speed * deltaTime));

        if (shape.getPosition().y + shape.getSize().y < 0)
        {
            active = false;
        }
    }
}

void Bullet::draw(sf::RenderWindow& window)
{
    if (active)
    {
        window.draw(shape);
    }
}

bool Bullet::isActive() const
{
    return active;
}

sf::FloatRect Bullet::getBounds() const
{
    return shape.getGlobalBounds();
}

void Bullet::deactivate()
{
    active = false;
}