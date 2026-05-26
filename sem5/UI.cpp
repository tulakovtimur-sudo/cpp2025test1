#include "UI.h"
#include "Constants.h"
#include <iostream>

UI::UI() : fontLoaded(false)
{
    loadFont();
    createTexts();

    scoreFrame.setSize(sf::Vector2f(UI_FRAME_WIDTH, UI_FRAME_HEIGHT));
    scoreFrame.setFillColor(UI_BG_COLOR);
    scoreFrame.setOutlineThickness(UI_OUTLINE_THICKNESS);
    scoreFrame.setOutlineColor(UI_SCORE_COLOR);
    scoreFrame.setPosition(sf::Vector2f(UI_SCORE_X, UI_SCORE_Y));

    livesFrame.setSize(sf::Vector2f(UI_FRAME_WIDTH, UI_FRAME_HEIGHT));
    livesFrame.setFillColor(UI_BG_COLOR);
    livesFrame.setOutlineThickness(UI_OUTLINE_THICKNESS);
    livesFrame.setOutlineColor(UI_LIVES_COLOR);
    livesFrame.setPosition(sf::Vector2f(UI_LIVES_X, UI_LIVES_Y));
}

void UI::loadFont()
{
    std::string fontPath = "C:/Windows/Fonts/Arial.ttf";

    if (!font.openFromFile(fontPath))
    {
        std::cout << "ERROR: Cannot load font from: " << fontPath << std::endl;
        fontLoaded = false;
    }
    else
    {
        fontLoaded = true;
        std::cout << "Font loaded successfully" << std::endl;
    }
}

void UI::createTexts()
{
    if (fontLoaded)
    {
        scoreText = sf::Text(font, "Score: 0", UI_FONT_SIZE);
        scoreText->setFillColor(sf::Color::White);
        scoreText->setPosition(sf::Vector2f(UI_SCORE_X + UI_TEXT_OFFSET, UI_SCORE_Y + UI_TEXT_OFFSET));

        livesText = sf::Text(font, "Lives: 3", UI_FONT_SIZE);
        livesText->setFillColor(sf::Color::White);
        livesText->setPosition(sf::Vector2f(UI_LIVES_X + UI_TEXT_OFFSET, UI_LIVES_Y + UI_TEXT_OFFSET));
    }
}
void UI::updateScore(int score)
{
    if (fontLoaded && scoreText.has_value())
    {
        scoreText->setString("Score: " + std::to_string(score));
    }
}

void UI::updateLives(int lives)
{
    if (fontLoaded && livesText.has_value())
    {
        livesText->setString("Lives: " + std::to_string(lives));
    }
}

void UI::draw(sf::RenderWindow& window)
{
    window.draw(scoreFrame);
    window.draw(livesFrame);

    if (fontLoaded)
    {
        if (scoreText.has_value()) window.draw(*scoreText);
        if (livesText.has_value()) window.draw(*livesText);
    }
}

void UI::showGameOver(sf::RenderWindow& window, int finalScore)
{
    if (!fontLoaded) return;

    sf::Text gameOverText(font, "GAME OVER", GAME_OVER_FONT_SIZE);
    gameOverText.setFillColor(sf::Color::Red);
    gameOverText.setPosition(sf::Vector2f(GAME_OVER_X, GAME_OVER_Y));

    sf::Text scoreTextFinal(font, "Final Score: " + std::to_string(finalScore), FINAL_SCORE_FONT_SIZE);
    scoreTextFinal.setFillColor(sf::Color::White);
    scoreTextFinal.setPosition(sf::Vector2f(FINAL_SCORE_X, FINAL_SCORE_Y));

    sf::Text exitText(font, "Press ESC to exit", EXIT_FONT_SIZE);
    exitText.setFillColor(sf::Color::Yellow);
    exitText.setPosition(sf::Vector2f(EXIT_TEXT_X, EXIT_TEXT_Y));

    window.draw(gameOverText);
    window.draw(scoreTextFinal);
    window.draw(exitText);
    window.display();
}