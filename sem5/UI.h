#pragma once
#include <SFML/Graphics.hpp>
#include <memory>
#include <optional>

class UI
{
private:
    sf::Font font;
    std::optional<sf::Text> scoreText;
    std::optional<sf::Text> livesText;
    sf::RectangleShape scoreFrame;
    sf::RectangleShape livesFrame;
    bool fontLoaded;

public:
    UI();
    void updateScore(int score);
    void updateLives(int lives);
    void draw(sf::RenderWindow& window);
    void showGameOver(sf::RenderWindow& window, int finalScore);

private:
    void loadFont();
    void createTexts();
};