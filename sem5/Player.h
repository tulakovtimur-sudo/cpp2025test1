#pragma once
#include <SFML/Graphics.hpp>

sf::ConvexShape createPlayer();
void drawPlayer(sf::RenderWindow& window, sf::ConvexShape& player);