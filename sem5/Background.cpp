#include "Background.h"
#include "Constants.h"
#include <random>

Background::Background() : starSpeed(STAR_SPEED)
{
    background.setSize(sf::Vector2f(WINDOW_WIDTH, WINDOW_HEIGHT));
    background.setFillColor(BACKGROUND_COLOR);
    createStars();
}

void Background::createStars()
{
    std::random_device rd;
    std::mt19937 gen(rd());
    std::uniform_int_distribution<> xDist(0, WINDOW_WIDTH);
    std::uniform_int_distribution<> yDist(0, WINDOW_HEIGHT);
    std::uniform_int_distribution<> sizeDist(STAR_SIZE_MIN, STAR_SIZE_MAX);
    std::uniform_int_distribution<> alphaDist(STAR_ALPHA_MIN, STAR_ALPHA_MAX);

    for (int i = 0; i < STAR_COUNT; i++)
    {
        float starSize = static_cast<float>(sizeDist(gen));
        sf::RectangleShape star(sf::Vector2f(starSize, starSize));
        star.setFillColor(sf::Color(STAR_COLOR.r, STAR_COLOR.g, STAR_COLOR.b, alphaDist(gen)));
        star.setPosition(sf::Vector2f(static_cast<float>(xDist(gen)),
            static_cast<float>(yDist(gen))));
        stars.push_back(star);
    }
}

void Background::update(float deltaTime)
{
    for (auto& star : stars)
    {
        star.move(sf::Vector2f(0.f, starSpeed * deltaTime));

        if (star.getPosition().y > WINDOW_HEIGHT)
        {
            std::random_device rd;
            std::mt19937 gen(rd());
            std::uniform_int_distribution<> xDist(0, WINDOW_WIDTH);
            star.setPosition(sf::Vector2f(static_cast<float>(xDist(gen)), 0.f));
        }
    }
}

void Background::draw(sf::RenderWindow& window)
{
    window.draw(background);
    for (auto& star : stars)
    {
        window.draw(star);
    }
}