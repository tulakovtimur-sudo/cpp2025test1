#include "Player.h"
#include "Constants.h"

sf::ConvexShape createPlayer()
{
    sf::ConvexShape player;
    player.setPointCount(PLAYER_POINT_COUNT);

    for (int i = 0; i < PLAYER_POINT_COUNT; i++)
    {
        player.setPoint(i, PLAYER_POINTS[i]);
    }

    player.setFillColor(PLAYER_COLOR);
    player.setOutlineThickness(PLAYER_OUTLINE_THICKNESS);
    player.setOutlineColor(PLAYER_OUTLINE_COLOR);
    player.setPosition(sf::Vector2f(PLAYER_START_X, PLAYER_START_Y));

    return player;
}

void drawPlayer(sf::RenderWindow& window, sf::ConvexShape& player)
{
    window.draw(player);
}